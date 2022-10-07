
#include <vector>
#include <map>
using namespace std;

#include "common.h"

// __attribute__((__visibility__("default")))
int sub(int a, int b)
{
    int c = 0;
    MyTestClass tc;

    c = a - b;
    c = tc.func1(c);
    return c;
}

// __attribute__ ((visibility ("default")))
// __attribute__ ((visibility ("hidden")))
static int mul(int a, int b)
{
    return a * b;
}


