// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total_size = nmemb * size;
    void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr != MAP_FAILED) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}


void free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }
}


void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    void *new_ptr = mremap(ptr, sizeof(ptr), size, MREMAP_MAYMOVE);

    if (new_ptr == MAP_FAILED) {
        return NULL;
    }

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;

    if (ptr == NULL) {
        return malloc(total_size);
    }

    void *new_ptr = mremap(ptr, sizeof(ptr), total_size, MREMAP_MAYMOVE);

    if (new_ptr == MAP_FAILED) {
        return NULL;
    }

    return new_ptr;
}
