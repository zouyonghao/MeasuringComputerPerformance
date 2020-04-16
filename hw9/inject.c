#include <dlfcn.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>

unsigned long total_read_count = 0;
unsigned long total_write_count = 0;

unsigned long total_read_size = 0;
unsigned long total_write_size = 0;

double total_read_time = 0;
double total_write_time = 0;

typedef ssize_t (*WRITE)(int fd, const void *buf, size_t count);

int write(int fd, const void *buf, size_t count)
{
    total_write_count++;
    total_write_size += count;
    static void *handle = NULL;
    static WRITE old_write = NULL;

    if (!handle)
    {
        handle = dlopen("libc.so.6", RTLD_LAZY);
        old_write = (WRITE)dlsym(handle, "write");
    }
    printf("write func called. count = %ld\n", count);
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    gettimeofday(&start, NULL);
    int result = old_write(fd, buf, count);

    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("write time is %ld\n", diff);
    total_write_time += diff;
    return result;
}

typedef ssize_t (*READ)(int fd, void *buf, size_t count);

int read(int fd, void *buf, size_t count)
{
    total_read_count++;
    total_read_size += count;
    static void *handle = NULL;
    static WRITE old_write = NULL;

    if (!handle)
    {
        handle = dlopen("libc.so.6", RTLD_LAZY);
        old_write = (WRITE)dlsym(handle, "read");
    }
    printf("read func called. count = %ld\n", count);
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    gettimeofday(&start, NULL);
    int result = old_write(fd, buf, count);

    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("write time is %ld\n", diff);
    total_read_time += diff;
    return result;
}

void print_statistics()
{
    printf("total read is %ld\n", total_read_count);
    printf("total write is %ld\n", total_write_count);
    printf("average read size is %f\n", (double)total_read_size / total_read_count);
    printf("average write size is %f\n", (double)total_write_size / total_write_count);
    printf("total read time is %f\n", total_read_time / total_read_count);
    printf("total write time is %f\n", total_write_time / total_write_count);
}

typedef void (*EXIT)(int status) __attribute__((noreturn));

void exit(int status)
{
    printf("exit func called.\n");
    print_statistics();
    static void *handle = NULL;
    static EXIT old_exit = NULL;

    if (!handle)
    {
        handle = dlopen("libc.so.6", RTLD_LAZY);
        old_exit = (EXIT)dlsym(handle, "exit");
    }

    old_exit(status);
}

__attribute__((destructor)) void main() {
    print_statistics();
}