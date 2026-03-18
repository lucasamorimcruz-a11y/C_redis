#include "my_redis.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

static void _log(const char *level, const char *fmt, va_list ap) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm *t = localtime(&tv.tv_sec);
    fprintf(stderr, "[%02d:%02d:%02d.%03ld] %s ",
            t->tm_hour, t->tm_min, t->tm_sec,
            (long)(tv.tv_usec / 1000), level);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
}

void log_info(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt); _log("INFO ", fmt, ap); va_end(ap);
}
void log_warn(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt); _log("WARN ", fmt, ap); va_end(ap);
}
void log_error(const char *fmt, ...) {
    va_list ap; va_start(ap, fmt); _log("ERROR", fmt, ap); va_end(ap);
}

long long mstime(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

uint32_t dict_hash(const char *key, size_t len) {
    uint32_t h = 2166136261u;
    for (size_t i = 0; i < len; i++) {
        h ^= (unsigned char)key[i];
        h *= 16777619u;
    }
    return h;
}

int set_nonblock(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) return REDIS_ERR;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1 ? REDIS_ERR : REDIS_OK;
}