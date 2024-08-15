#include "zheap.h"

int main()
{
	int *ptr1 = (int*) zmalloc(sizeof(int));
	char *ptr2 = (char*) zmalloc(sizeof(char));
	int *ptr3 = (int*) zmalloc(sizeof(int));
	char *ptr4 = (char*) zmalloc(sizeof(char));

	int *ptr5 = (int*) zmalloc(10 * sizeof(int));
	char *ptr6 = (char*) zmalloc(6 * sizeof(char));

	printf("\nStoring some initial data\n");
	*ptr1 = 123456;
	*ptr2 = 'a';
	*ptr3 = 325682;
	*ptr4 = 'b';

	for (int i = 0; i < 10; ++i)
	{
		ptr5[i] = i + 1;
	}
	*ptr6 = 'h';
	*(ptr6 + 1) = 'e';
	*(ptr6 + 2) = 'l';
	*(ptr6 + 3) = 'l';
	*(ptr6 + 4) = 'o';
	*(ptr6 + 5) = '\0';

	printf("value sotred at %p is %d\n", (void*) ptr1, *ptr1);
	printf("value sotred at %p is %c\n", (void*) ptr2, *ptr2);
	printf("value sotred at %p is %d\n", (void*) ptr3, *ptr3);
	printf("value sotred at %p is %c\n", (void*) ptr4, *ptr4);

	for (int i = 0; i < 10; ++i)
	{
		printf("value sotred at %p is %d\n", (void*) (ptr5 + i), *(ptr5 + i));
	}
	printf("value sotred at %p is %s\n", (void*) ptr6, ptr6);
	

	printf("Start of the heap: %p\n", heap);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Freeing first block\n");
	zfree(ptr1);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Freeing last block (will merge with the block after if exists)\n");
	zfree(ptr6);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Freeing the block before the last (will merge with the block after)\n");
	zfree(ptr5);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Allocate memory for int (first fit in the 1st block)\n");
	ptr1 = (int*) zmalloc(sizeof(int));

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Freeing first block\n");
	zfree(ptr1);

	printf("Freeing the block after the first (will merge with the block before)\n");
	zfree(ptr2);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Allocate memory for int (first fit in the 1st block)\n");
	ptr1 = (int*) zmalloc(sizeof(int));

	printf("Allocate memory for char (first fit in the 2nd block)\n");
	ptr2 = (char*) zmalloc(sizeof(char));

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Freeing the second block\n");
	zfree(ptr2);

	printf("Freeing the fourth block (will merge with the block after)\n");
	zfree(ptr4);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Freeing the third block (2nd, 3rd, 4th blocks will merge)\n");
	zfree(ptr3);

	printf("\nThe blocks in heap:\n\n");
	print();

	printf("Storing a value in the first block\n");
	*ptr1 = 400;

	printf("value sotred at %p is %d\n", (void*) ptr1, *ptr1);
}
