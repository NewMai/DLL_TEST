
#include "GetHighAccuracyTime.h"
#include <stdio.h>


// Not implement
int test_x32()
{
    unsigned int low = 0 , high = 0, nlow = 0 , nhigh = 0, diff = 0;
    double dd = 0;

    puts("Start:");
    low = GetHighAccuracyTime_x32(&high);
    printf("high = 0x%08X, low = 0x%08X\n\n", high, low);

    puts("End:");
    nlow = GetHighAccuracyTime_x32(&nhigh);
    printf("high = 0x%08X, low = 0x%08X\n\n", nhigh, nlow);

    puts("Diff in ns:");
    printf("high = 0x%08X, low = 0x%08X\n\n", nhigh - high, nlow - low);

    diff = nlow - low;
    dd = diff;

    puts("Diff in us:");
    printf("%f us\n\n", dd / 1000);

    return 0;
}


int main()
{
    //test_x32();

    return 0;    
}

