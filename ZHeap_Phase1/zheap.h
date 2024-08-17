#ifndef ZHEAP_H
#define ZHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 32 * 1024 * 1024
#define PAGE_SIZE 1024 * 1024

typedef struct block {
        size_t size;
	int free;
	struct block *next;
} block;

extern char heap[HEAP_SIZE];
extern struct block *free_list;
extern char *brk;

/* zmalloc */
void *zmalloc(size_t size);
void split_block(struct block *current, size_t size);
void increment_brk(size_t size);
int can_split(struct block *current, size_t size);

/* zfree */
void zfree(void *ptr);
void merge_blocks(struct block *first, struct block *second);

/* zheap */
void print();

#endif /* ZHEAP_H */
