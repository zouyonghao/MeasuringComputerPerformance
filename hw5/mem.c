#include <stdio.h>
#include <stdlib.h>
#include <linux/types.h>
#include <sys/time.h>

int main()
{
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    //需要测试的数组大小
    // for cache
    __u32 size = 1 << 18;
    // for mem
    // __u32 size = 1 << 18;
    volatile int sink;
    __u64 *data = malloc(sizeof(__u64) * size);
    if (data == NULL) {
        printf("malloc failed\n");
        exit(0);
    }
    for (int i = 0; i < size; i++)
    {
        data[i] = 0;
    }

    int result = 0;

    // try warmup
    for (int i = 0; i < size; i++)
    {
        result += data[i];
    }

    // 步长
    for (int j = 1; j < 17; j++)
    {
        result = 0;
        gettimeofday(&start, NULL);
        for (int i = 0; i < size; i += j)
        {
            result += data[i];
        }
        sink = result;
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
        printf("Speed is %f MB/s , j = %d\n", size / j * 16 / 1024.0 / 1024.0 / diff * 1000000, j);
    }
}