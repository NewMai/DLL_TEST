
#include <iostream>
using namespace std;


void* myNew(void*(*alloc_fn)(size_t), size_t size)
{
    void* buf = NULL;

    buf = alloc_fn(size);

    return buf;
}

void test1()
{
    int i = 0;
    void* buf = myNew(&::operator new [], 20);
    int *intptr = (int*)buf;

    intptr[0] = 123;
    intptr[1] = 456;
    intptr[2] = 789;
    intptr[3] = 109;

    for (i = 0; i < 4; i++)
    {
        printf("data[%d] = %d\n", i, intptr[i]);
    }
}

int main()
{
    test1();
    return 0;
}

// g++ ./new_delete_test.cpp -o ./new_delete_test.exe
// g++ ./new_delete_test.cpp -o ./new_delete_test.exe -v
