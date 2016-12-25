void* syscall5(
        void* number,
        void* arg1,
        void* arg2,
        void* arg3,
        void* arg4,
        void* arg5);

typedef unsigned long int size_t;
typedef long int ssize_t;

static
ssize_t write(int fd, void const* data, size_t nbytes)
{
    return (ssize_t) syscall5(
        (void*)1, /* SYS_write */
        (void*)(ssize_t)fd,
        (void*)data,
        (void*)nbytes,
        0, /* ignored */
        0); /* ignored */
}

int main(int argc, char* argv[])
{
    write(1, "hello\n", 6);

    return 0;
}

