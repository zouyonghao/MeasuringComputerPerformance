#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int count = 0;

void a()
{
    printf("a\n");
    sleep(0.1);
}

void c()
{
    printf("c\n");
    sleep(0.2);
}

void b()
{
    int i = 0;
    rand();
    while (i < 1000)
    {
        i++;
        if (rand() % 100 > 50)
        {
            a();
        }
        else
        {
            c();
        }
        count++;
        printf("%d\n", i);
    }
}

int main(int argc, char const *argv[])
{
    time_t t;
    srand((unsigned)time(&t));
    b();
    return 0;
}
