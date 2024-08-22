#include "zheap.h"

struct block *free_list = NULL;

void *malloc(size_t size) {
    return zmalloc(size);
}

void free(void *ptr) {
    zfree(ptr);
}

void *realloc(void *ptr, size_t size) {
    return zrealloc(ptr, size);
}

void *calloc(size_t nmemb, size_t size) {
    return zcalloc(nmemb, size);
}

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
