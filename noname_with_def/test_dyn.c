
#include <stdio.h>
#include <Windows.h>

typedef int (*FUNC)(int, int);

int main()
{
    int a = 5; 
    int b = 16;
    int c = 0;
    const char* szLibName = "math.dll";
    FUNC fnAdd = NULL, fnSub = NULL, fnMul = NULL;

    HMODULE hMod = LoadLibraryA(szLibName);
    if (!hMod)
    {
        puts("Load dll module failed!");
        return 0;
    }

    // Get process address by function ordinal
    fnAdd = (FUNC)GetProcAddress(hMod, (LPCSTR)1);
    fnSub = (FUNC)GetProcAddress(hMod, (LPCSTR)2);
    fnMul = (FUNC)GetProcAddress(hMod, (LPCSTR)3);

    if (fnAdd)
    {
        c = fnAdd(a, b);
        printf("c = %d\n", c);
    }
    
    if (fnSub)
    {
        c = fnSub(a, b);
        printf("c = %d\n", c);
    }

    if (fnMul)
    {
        c = fnMul(a, b);
        printf("c = %d\n", c);
    }

    FreeLibrary(hMod);
    hMod = NULL;

    return 0;
}



