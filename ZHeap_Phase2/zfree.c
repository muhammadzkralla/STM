#include "zheap.h"

/**
 * zfree - Frees the allocated memory in virtual heap
 *
 * @ptr: the pointer to the memory to be freed
 *
 * Return: void
 */
void zfree(void *ptr)
{
	if (ptr == NULL)
	{
		return;
	}

	ptr = (block*) ((char*) ptr - sizeof(block));
	struct block *current = free_list, *prev = NULL;

	while (current != NULL)
	{
		if (current == ptr)
		{
			current->free = 1;

			int before_free = 0, after_free = 0;
			if (current->next != NULL && current->next->free)
			{
				after_free = 1;
			}

			if (prev != NULL && prev->free)
			{
				before_free = 1;
			}

			if (after_free && before_free)
			{
				merge_blocks(prev, current);
				merge_blocks(prev, current->next);
			}
			else if (after_free)
			{
				merge_blocks(current, current->next);
			}
			else if (before_free)
			{
				merge_blocks(prev, current);
			}

			return;
		}
		
		prev = current;
		current = current->next;
	}

	fprintf(stderr, "Error: Attempting to free a pointer that was not allocated\n");
}

/**
 * merge_blocks - Merges the two passed blocks
 *
 * @first: the first block to merge
 * @second: the second block to merge
 *
 * Return: void
 */
void merge_blocks(struct block *first, struct block *second)
{
	first->size = first->size + second->size;
	first->next = second->next;
}
