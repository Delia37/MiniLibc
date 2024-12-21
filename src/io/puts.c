#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <stdio.h>

int puts(const char *s)
{
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int result = write(1, s, len);

    if (result == -1) {
        errno = -result;
        return -1;
    }

    result = write(1, "\n", 1);

    if (result == -1) {
        errno = -result;
        return -1;
    }

    return len + 1;
}
