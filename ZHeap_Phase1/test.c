#include "zheap.h"

int main()
{
	int *ptr1 = (int*) zmalloc(sizeof(int));
	char *ptr2 = (char*) zmalloc(sizeof(char));
	int *ptr3 = (int*) zmalloc(sizeof(int));
	char *ptr4 = (char*) zmalloc(sizeof(char));
	int *ptr5 = (int*) zmalloc(sizeof(int));

	*ptr1 = 69;
	*ptr2 = 'a';
	*ptr3 = 420;
	*ptr4 = 'b';
	*ptr5 = 18;

	printf("start of the heap: %p\n", heap);
	printf("ptr1: %p\n", (void*) ptr1);
	printf("ptr2: %p\n", (void*) ptr2);
	printf("ptr3: %p\n", (void*) ptr3);
	printf("ptr4: %p\n", (void*) ptr4);
	printf("ptr5: %p\n", (void*) ptr5);

	printf("\nThe blocks in heap:\n\n");

	print();

	printf("the value of ptr1: %d\n", *ptr1);
	printf("the value of ptr2: %c\n", *ptr2);
	printf("the value of ptr3: %d\n", *ptr3);
	printf("the value of ptr4: %c\n", *ptr4);
	printf("the value of ptr5: %d\n", *ptr5);

	return 0;
}
