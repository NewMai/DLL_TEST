
#include <stdio.h>


int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

void test1()
{
    int a = 3;
    int b = 5;
    int c = 0;

    c = add(a, b);
    printf("c = %d\n", c);

    c = sub(a, b);
    printf("c = %d\n", c);

    c = mul(a, b);
    printf("c = %d\n", c);
}

int main()
{
    test1();
    return 0;
}

/*

# 打开 gcc64
gcc64
cd /d E:\DLL_TEST\gcc_milti_file

del *.obj *.exe *.a *.dll

g++ -c -g ./test1.cpp -o ./test1.obj
g++ -c -g ./test2.cpp -o ./test2.obj
g++ -g -shared ./test1.obj ./test2.obj -o ./test.dll


g++ -c -g -D_DEBUG -fvisibility=hidden ./test1.cpp -o ./test1.obj
g++ -c -g -D_DEBUG -fvisibility=hidden ./test2.cpp -o ./test2.obj
g++ -g -D_DEBUG -shared -fPIC -Wl,--kill-at,-fvisibility=hidden,--out-implib,./test.dll.a ./test1.obj ./test2.obj -o ./test.dll

g++ -c -O2 -DNDEBUG -fvisibility=hidden ./test1.cpp -o ./test1.obj
g++ -c -O2 -DNDEBUG -fvisibility=hidden ./test2.cpp -o ./test2.obj
g++ -O2 -DNDEBUG -shared -fPIC -Wl,--kill-at,-fvisibility=hidden,--out-implib,./test.dll.a ./test1.obj ./test2.obj -o ./test.dll


g++ -g -shared -fvisibility=hidden -Wl,--out-implib,./test.dll.a ./test1.cpp ./test2.cpp -o ./test.dll
g++ -g -shared -fvisibility=default -Wl,--out-implib,./test.dll.a ./test1.cpp ./test2.cpp -o ./test.dll
g++ -g -shared -fvisibility=hidden -fvisibility-inlines-hidden -Wl,--out-implib,./test.dll.a ./test1.cpp ./test2.cpp -o ./test.dll
g++ -g -shared -Wl,--kill-at,--out-implib,./test.dll.a ./test1.cpp ./test2.cpp -o ./test.dll

// set(CMAKE_CXX_VISIBILITY_PRESET hidden)
dumpbin /EXPORTS ./test.dll


g++ ./main.cpp -g ./test.dll.a -o ./main.exe



cl /c /nologo ./test1.cpp
cl /c /nologo ./test2.cpp
link /dll /nologo test1.obj test2.obj /out:test.dll


*/

