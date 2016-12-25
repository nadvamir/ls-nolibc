void* syscall3(
        void* number,
        void* arg1,
        void* arg2,
        void* arg3);

typedef unsigned long int size_t;
typedef long int ssize_t;

static
ssize_t write(int fd, void const* data, size_t nbytes)
{
    return (ssize_t) syscall3(
        (void*)1, /* SYS_write */
        (void*)(ssize_t)fd,
        (void*)data,
        (void*)nbytes);
}

int main(int argc, char* argv[])
{
    write(1, "hello\n", 6);

    return 0;
}

