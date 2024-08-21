#include "zheap.h"

/**
 * zcalloc - Allocates memory for an array of `nmemb` elements of `size` bytes each,
 *           and initializes all bytes in the allocated storage to zero.
 *
 * @nmemb: the number of elements to allocate
 * @size: the size of each element
 *
 * Return: void pointer to the allocated and zero-initialized memory block, or NULL if allocation fails
 */
void *zcalloc(size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0) {
		return NULL;
	}

	size_t total_size = nmemb * size;
	void *ptr = zmalloc(total_size);

	if (ptr == NULL) {
		return NULL;
	}

	memset(ptr, 0, total_size);

	return ptr;
}
