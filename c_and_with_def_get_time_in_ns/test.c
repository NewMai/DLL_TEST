
#include "GetHighAccuracyTime.h"
#include <stdio.h>



int test_x64()
{
    unsigned long long start = 0 , end = 0, diff = 0;
    double dd = 0;

    puts("Start:");
    start = GetHighAccuracyTime_x64();
    printf("start = 0x%016llX\n\n", start);

    puts("End:");
    end = GetHighAccuracyTime_x64();
    printf("end = 0x%016llX\n\n", end);

    diff = end - start;
    dd = diff;

    puts("Diff in ns:");
    printf("0x%016llX ns\n\n", diff);

    puts("Diff in us:");
    printf("%f us\n\n", dd / 1000);

    puts("Diff in ms:");
    printf("%f ms\n\n", dd / 1000 / 1000);

    return 0;
}

void bench()
{
    unsigned long long i = 0, loop = 10000000, x = 0;
    unsigned long long start = 0 , end = 0, diff = 0;
    double dd = 0;
    
    start = GetHighAccuracyTime_x64();
    
    for(i = 0; i < loop; i++)
    {
        x += 1;
    }
    end = GetHighAccuracyTime_x64();
    
    puts("Start:");
    printf("start = 0x%016llX\n\n", start);
    puts("End:");
    printf("end = 0x%016llX\n\n", end);

    diff = end - start;
    dd = diff;

    puts("Diff in ms:");
    printf("%f ms\n\n", dd / 1000 / 1000);
}

int main()
{
    test_x64();
    bench();

    return 0;    
}

