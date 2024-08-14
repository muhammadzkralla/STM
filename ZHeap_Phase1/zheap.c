#include "zheap.h"

char heap[HEAP_SIZE];
struct block *free_list = NULL;
char *brk = heap;

/**
 * print - Prints the current free list
 *
 * Return: void
 */
void print()
{
	struct block *tmp = free_list;

	while (tmp != NULL)
	{
		printf("start: %p\n", (void*) tmp);
		printf("size: %ld bytes\n", tmp->size);
		printf("free: %d\n", tmp->free);
		printf("next: %p\n", (void*) tmp->next);
		printf("**************\n");

		tmp = tmp->next;
	}
}
