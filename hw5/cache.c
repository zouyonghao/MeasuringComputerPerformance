#include <stdio.h>
#include <stdlib.h>
#include <linux/types.h>
#include <sys/time.h>

extern int Reader(void *ptr, unsigned long size, unsigned long loops);

int main()
{
    struct timeval start;
    struct timeval end;
    unsigned long diff;

    // for cache
    __u32 size = 1 << 10;

    volatile int sink;
    __u64 *data = malloc(sizeof(__u64) * size);
    if (data == NULL)
    {
        printf("malloc failed\n");
        exit(0);
    }
    for (int i = 0; i < size; i++)
    {
        data[i] = i;
    }

    int loop = 100000;
    gettimeofday(&start, NULL);
    Reader(data, size, loop);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    long double result = (long double)size * loop / 1048576 / diff * 1000000;
    printf("Speed is %Lf MB/s\n", result);
    free(data);
}