// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    char *start = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return start;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    char *start = destination;

    while (len > 0 && *source != '\0') {
        *destination = *source;
        destination++;
        source++;
        len--;
    }

    while (len > 0) {
        *destination = '\0';
        destination++;
        len--;
    }

    return start;
}

char *strcat(char *destination, const char *source)
{
	char *start = destination;

    while (*destination != '\0') {
        destination++;
    }

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return start;
}


char *strncat(char *destination, const char *source, size_t len)
{
    if (destination == NULL || source == NULL) {
        return NULL;
    }

    char *start = destination;

    while (*destination != '\0') {
        destination++;
    }

    while (*source != '\0' && len > 0) {
        *destination = *source;
        destination++;
        source++;
        len--;
    }

    *destination = '\0';

    return start;
}


int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
    if (len == 0) return 0;

    while (--len && *str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str) {
        if (*str == c)
            return (char *)str;
        str++;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
    char *last = NULL;
    while (*str) {
        if (*str == c)
            last = (char *)str;
        str++;
    }
    if (c == '\0')
        return (char *)str;
    return last;
}

char *strstr(const char *haystack, const char *needle)
{
    size_t needle_len = strlen(needle);

    while (*haystack) {
        if (strncmp(haystack, needle, needle_len) == 0)
            return (char *)haystack;
        haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    char *last = NULL;
    size_t needle_len = strlen(needle);

    while (*haystack) {
        if (strncmp(haystack, needle, needle_len) == 0)
            last = (char *)haystack;
        haystack++;
    }

    return last;
}

void *memcpy(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;

    for (size_t i = 0; i < num; i++)
        dest[i] = src[i];

    return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    char *dest = (char *)destination;
    const char *src = (const char *)source;

    if (dest <= src || dest >= src + num) {
        while (num--)
            *dest++ = *src++;
    } else {
        dest += num;
        src += num;
        while (num--)
            *(--dest) = *(--src);
    }
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    for (size_t i = 0; i < num; i++) {
        if (p1[i] != p2[i])
            return p1[i] - p2[i];
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    unsigned char *ptr = (unsigned char *)source;

    for (size_t i = 0; i < num; i++)
        ptr[i] = (unsigned char)value;

    return source;
}
