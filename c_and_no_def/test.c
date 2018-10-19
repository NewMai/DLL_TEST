
#include "math.h"
#include <stdio.h>

int main()
{
    int a = 5; 
    int b = 16;
    int c = 0;

    c = MyAdd(a, b);
    printf("c = %d\n", c);

    c = MySub(a, b);
    printf("c = %d\n", c);

    c = MyMul(a, b);
    printf("c = %d\n", c);

    return 0;
}



