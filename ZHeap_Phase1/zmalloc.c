#include "zheap.h"

/**
 * zmalloc - Allocates the required memory in virtual heap
 *
 * @size: the required memory size
 *
 * Return: void
 */
void *zmalloc(size_t size)
{
	struct block *current = free_list, *prev = free_list;

	// first-fit algorithm to find the first block that fits the required size
	// in the free list of blocks
	while (current != NULL)
	{
		// this block is valid
		if (current->free && current->size >= size + sizeof(block))
		{
			// if the block size is greater than the required size, we split
			// this block into two blocks, one with the required size and assign
			// it as used, and another one with the remaining space and assign it
			// as free
			if (current->size > size + sizeof(block))
			{
				if (can_split(current, size) == 0)
				{
					split_block(current, size);
				}
				else
				{
					prev = current;
					current = current->next;
					continue;
				}
			}

			current->free = 0;
			return (char*) current + sizeof(block);
		}

		prev = current;
		current = current->next;
	}

	size_t total_size = size + sizeof(block);

	// minimize the number of increasing the system break
	if (total_size < PAGE_SIZE)
	{
		total_size = PAGE_SIZE;
	}
	else
	{
		total_size += PAGE_SIZE;
	}

	// there's no enough space to increase the heap break
	if (brk + total_size > heap + HEAP_SIZE)
	{
		return NULL;
	}

	// create the new block and increment the heap break
	current = (block*) brk;
	current->size = total_size;
	current->free = 0;
	current->next = NULL;

	increment_brk(total_size);
	
	// the same splitting strategy
	if (current->size > size + sizeof(block))
	{
		split_block(current, size);
	}

	// if the malloc is successful, initialize the free list linked list
	if (prev != NULL)
	{
		prev->next = current;
	}
	else
	{
		free_list = (block*) heap;
	}

	return (char*) current + sizeof(block);
}

/**
 * split_block - Splits the passed block into two blocks
 *
 * @current: the block we will split
 * @size: the size of the first block without metadata
 *
 * Return: void
 */
void split_block(struct block *current, size_t size)
{
	struct block *new_block = (block*) ((char*) current + size + sizeof(block));
	new_block->size = current->size - size - sizeof(block);
	new_block->free = 1;
	new_block->next = current->next;

	if (new_block->size < sizeof(block))
	{
		increment_brk(PAGE_SIZE);
		new_block->size = (new_block->size + PAGE_SIZE);
	}
	
	current->size = size + sizeof(block);
	current->next = new_block;
}

/**
 * increment_brk - Increments the virtual program break.
 *
 * @size: the amount of increase
 *
 * Return: void
 */
void increment_brk(size_t size)
{
	brk += size;

	size_t heap_size = brk - heap;
	size_t rem = heap + HEAP_SIZE - brk;

	printf("\nthe program break incremented by %ld bytes\n", size);
	printf("the heap size now is %ld bytes\n", heap_size);
	printf("heap can be increased more by: %ld bytes if needed\n", rem);
}

/**
 * can_split - Check if we can split this node or not.
 *
 * @current: the block we will split
 * @size: the size of the first block without metadata
 *
 * Return: 0 if yes, -1 if not
 */
int can_split(struct block *current, size_t size)
{
	if (current->next == NULL)
	{
		return 0;
	}

	size_t block_size = sizeof(block);
	size_t total_size = size + block_size;
	size_t current_size = current->size;

	if (current_size - total_size > block_size)
	{
		return 0;
	}

	return -1;
}
