#include "zheap.h"


/**
 * zrealloc - Resizes the allocated memory in the virtual heap
 *
 * @ptr: the pointer to the memory to be resized
 * @size: the new size required
 *
 * Return: void pointer to the newly resized memory block
 */
void *zrealloc(void *ptr, size_t size)
{
	if (ptr == NULL && size == 0)
	{
		printf("Are you joking?\n");
		return NULL;
	}
	else if (ptr == NULL)
	{
		return zmalloc(size);
	}
	else if (size == 0)
	{
		zfree(ptr);
		return NULL;
	}

	struct block *current = (block*) ((char*) ptr - sizeof(block));
	void *new_ptr = zmalloc(size);

	if (new_ptr == NULL)
	{
		return NULL;
	}

	size_t moved_size;
	size_t raw_size = ( current->size - sizeof(block) );

	if (raw_size < size)
	{
		moved_size = raw_size;
	}
	else
	{
		moved_size = size;
	}

	memcpy(new_ptr, ptr, moved_size);
	zfree(ptr);
	return new_ptr;
}
