#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>
#include <errno.h>


int nanosleep(const struct timespec *req, struct timespec *rem) {
    int result;
    struct timespec remaining, requested;

    requested = *req;

    while (1) {
        result = syscall(__NR_nanosleep, &requested, &remaining);

        if (result == -1) {
            if (errno == EINTR) {
                requested = remaining;
                continue;
            } else {
                return -1;
            }
        } else {
            return 0;
        }
    }
}
