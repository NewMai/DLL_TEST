
#include <stdio.h>
#include <Windows.h>

// https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformation
void test1()
{
    BOOL bRet = FALSE;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buf = NULL;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = NULL;
    DWORD ReturnedLength = 10000;
    DWORD i = 0, len = 0;

    buf = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(ReturnedLength);
    if (buf)
    {
        bRet = GetLogicalProcessorInformation(buf, &ReturnedLength);
        if (bRet)
        {
            len = ReturnedLength / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
            for (i = 0; i < len; i++)
            {
                ptr = buf + i;
                printf("Buffer[%d] = %p\n", i, ptr);
            }
        }
        free(buf);
        buf = NULL;
    }
}

int main()
{
    test1();
    printf("Hello world!\n");
    return 0;
}



/*

c:/myprogramfiles/mingw64/bin/../libexec/gcc/x86_64-w64-mingw32/4.8.0/collect2.exe 
--sysroot=c:\myprogramfiles\mingw64\bin\../../mingw64 
-m i386pep -Bdynamic 
-o ./gcc_test.exe 
c:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../../../x86_64-w64-mingw32/lib/../lib/crt2.o 
c:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../../../x86_64-w64-mingw32/lib/../lib/crtbegin.o 
-Lc:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0 
-Lc:/myprogramfiles/mingw64/bin/../lib/gcc 
-Lc:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../../../x86_64-w64-mingw32/lib/../lib 
-Lc:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../../../lib 
-Lc:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../../../x86_64-w64-mingw32/lib 
-Lc:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../.. ./gcc_test.o 
-lmingw32 -lgcc -lgcc_eh -lmoldname -lmingwex -lmsvcrt -ladvapi32 -lshell32 -luser32 -lkernel32 -lmingw32 -lgcc -lgcc_eh -lmoldname -lmingwex -lmsvcrt 
c:/myprogramfiles/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/4.8.0/../../../../x86_64-w64-mingw32/lib/../lib/crtend.o

*/
