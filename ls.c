#include "syscalls.h"

void* syscall3(
        void* number,
        void* arg1,
        void* arg2,
        void* arg3);

typedef unsigned long int size_t;
typedef long int ssize_t;

#define stdout 1

ssize_t write(int fd, void const* data, size_t nbytes)
{
    return (ssize_t) syscall3(
        (void*) SYS_write,
        (void*)(ssize_t) fd,
        (void*) data,
        (void*) nbytes);
}

size_t strlen(char const* str)
{
    char const* p;
    for (p = str; *p; ++p);
    return p - str;
}

size_t puts(char const* str)
{
    return write(stdout, str, strlen(str));
}

int main(int argc, char* argv[])
{
    puts("hello world\n");

    return 0;
}

