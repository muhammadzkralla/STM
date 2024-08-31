#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <inttypes.h>
#include <string.h>

typedef struct {
    uint8_t status;
    uint8_t first_chs[3];
    uint8_t partition_type;
    uint8_t last_chs[3];
    uint32_t lba;
    uint32_t sector_count;
} PartitionEntry;

void print_partition_info(const char *device, int partition_number, PartitionEntry *entry) {
    printf("%s%-5d %-10c %-10u %-10u %-10u %uG      %-10X\n",
           device,
           partition_number,
           entry->status == 0x80 ? '*' : ' ',
           entry->lba,
           entry->lba + entry->sector_count - 1,
           entry->sector_count,
           (uint32_t) (((uint64_t) entry->sector_count * 512) / (1024 * 1024 * 1024)),
           entry->partition_type);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <device>\n", argv[0]);
        return 1;
    }

    char buf[512];
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Failed to open the device");
        return 1;
    }

    if (read(fd, buf, 512) != 512) {
        perror("Failed to read from device");
        close(fd);
        return 1;
    }

    PartitionEntry *table_entry_ptr = (PartitionEntry*) &buf[446];
    
    printf("%-5s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "Device",
           "Boot", "Start", "End", "Sectors", "Size", "Id", "Type");

    int logical_partition_count = 0;
    uint32_t ebr_lba = 0;

    for (int i = 0; i < 4; i++) {
        print_partition_info(argv[1], i + 1, &table_entry_ptr[i]);

        // Check if this is an extended partition
        if (table_entry_ptr[i].partition_type == 0x05 || table_entry_ptr[i].partition_type == 0x0F) {
            ebr_lba = table_entry_ptr[i].lba;
            uint32_t extended_base_lba = ebr_lba;

            while (ebr_lba != 0) {
                // Read the EBR
                lseek(fd, ebr_lba * 512, SEEK_SET);
                if (read(fd, buf, 512) != 512) {
                    perror("Failed to read from EBR");
                    close(fd);
                    return 1;
                }

                PartitionEntry *ebr_entry = (PartitionEntry*) &buf[446];
                PartitionEntry *next_ebr_entry = (PartitionEntry*) &buf[462];

                // Print the logical partition found in the EBR
                logical_partition_count++;
                print_partition_info(argv[1], 4 + logical_partition_count, ebr_entry);

                // Check if there's another logical partition
                if (next_ebr_entry->partition_type != 0) {
                    ebr_lba = extended_base_lba + next_ebr_entry->lba;
                } else {
                    ebr_lba = 0; // No more logical partitions
                }
            }
        }
    }

    close(fd);
    return 0;
}
