// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	//return -1;
	    va_list args;
    mode_t mode = 0; // Initialize mode to 0

    if (flags & O_CREAT) {
        va_start(args, flags);
        mode = va_arg(args, mode_t);
        va_end(args);
    }

    int fd = syscall(__NR_openat, AT_FDCWD, filename, flags, mode);

    if (fd < 0) {
        errno = -fd;
        return -1;
    }

    return fd;
}
