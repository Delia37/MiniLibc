// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
    if (path == NULL || buf == NULL) {
        errno = EINVAL;
        return -1;
    }
    int result = syscall(__NR_stat, path, buf);

    if (result < 0) {
        errno = -result;
        return -1;
    }

    return result;
}
