#ifndef ZHEAP_H
#define ZHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ALIGN(size) (((size) + (sizeof(void*) - 1)) & ~(sizeof(void*) - 1))
#define PAGE_SIZE 136 * 1024

typedef struct block {
        size_t size;
	int free;
	struct block *next;
} block;

extern struct block *free_list;

/* zmalloc */
void *zmalloc(size_t size);
void split_block(struct block *current, size_t size);
int can_split(struct block *current, size_t size);

/* zfree */
void zfree(void *ptr);
void merge_blocks(struct block *first, struct block *second);

/* zrealloc */
void *zrealloc(void *ptr, size_t size);

/* zcalloc */
void *zcalloc(size_t nmemb, size_t size);

/* zheap */
void print();

#endif /* ZHEAP_H */
