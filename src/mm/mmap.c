// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    void *ptr;
	if(fd > -1) {
		errno = EBADF;
		return MAP_FAILED;
	}
	if(flags == MAP_SHARED || flags == MAP_PRIVATE || flags == MAP_ANONYMOUS) {
		errno = EINVAL;
		return MAP_FAILED;
	}
    ptr = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
    return ptr;
}


void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
    void *ptr = (void *)syscall(__NR_mremap, (unsigned long)old_address, (unsigned long)old_size,
     (unsigned long)new_size, (unsigned long)flags, 0, 0);

    if (ptr == MAP_FAILED) {
        errno = -1;
    }

    return ptr;
}

int munmap(void *addr, size_t length)
{
    int ptr = syscall(__NR_munmap, (unsigned long)addr, (unsigned long)length, 0, 0, 0, 0);

    if (ptr < 0) {
        errno = -ptr;
        return -1;
    }

    return ptr;
}
