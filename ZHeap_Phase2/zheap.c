#include "zheap.h"

struct block *free_list = NULL;
pthread_mutex_t malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void *malloc(size_t size) {
    pthread_mutex_lock(&malloc_mutex);
    void *pointer = zmalloc(size);
    pthread_mutex_unlock(&malloc_mutex);

    return pointer;
}

void free(void *ptr) {
    pthread_mutex_lock(&malloc_mutex);
    zfree(ptr);
    pthread_mutex_unlock(&malloc_mutex);
}

void *realloc(void *ptr, size_t size) {
    pthread_mutex_lock(&malloc_mutex);
    void *pointer =  zrealloc(ptr, size);
    pthread_mutex_unlock(&malloc_mutex);
    return pointer;
}

void *calloc(size_t nmemb, size_t size) {
    pthread_mutex_lock(&malloc_mutex);
    void *pointer =  zcalloc(nmemb, size);
    pthread_mutex_unlock(&malloc_mutex);

    return pointer;
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
