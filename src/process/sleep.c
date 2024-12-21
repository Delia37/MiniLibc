#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds) {
    struct timespec requested, remaining;

    requested.tv_sec = seconds;
    requested.tv_nsec = 0;

    while (nanosleep(&requested, &remaining) == -1) {
        if (errno == EINTR) {
            requested = remaining;
            continue;
        } else {
            return remaining.tv_sec;
        }
    }

    return 0;
}
