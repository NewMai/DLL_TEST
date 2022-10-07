
#include <stdio.h>

void test1()
{

}

int main()
{
    test1();
    return 0;
}


/*
del *.obj *.exe *.a *.dll
set PATH=%PATH%;F:\MyProgramFiles\mingw64_x86-64_with_gcc10.3.0_from_msys2\mingw64\bin
set PATH=%PATH%;C:\MyProgramFiles\VS\VS2019Pro\VC\Tools\MSVC\14.28.29910\bin\Hostx64\x64

g++ -O2 -DNDEBUG -fPIC -shared ./new_delete.cpp -Wl,--out-implib,./new_delete.dll.a -o ./new_delete.dll

g++ -c -g -D_DEBUG -fvisibility=hidden ./new_delete.cpp -o ./new_delete.obj
g++ -g -D_DEBUG -shared -fPIC -Wl,--out-implib,./new_delete.dll.a ./new_delete.obj -o ./new_delete.dll

g++ -c -O2 -DNDEBUG -fvisibility=hidden ./new_delete.cpp -o ./new_delete.obj
g++ -O2 -DNDEBUG -shared -fPIC -Wl,--out-implib,./new_delete.dll.a ./new_delete.obj -o ./new_delete.dll


dumpbin /EXPORTS ./new_delete.dll

g++ ./main.cpp -g ./new_delete.dll.a -o ./main.exe


cl /c /nologo ./new_delete.cpp
link /dll /nologo new_delete.obj /out:new_delete.dll




g++ -c -g -O0 -D_DEBUG -fvisibility=hidden ./stdlib_new_delete.cpp -o ./stdlib_new_delete.obj
g++ -g -O0 -D_DEBUG -shared -fPIC -Wl,--out-implib,./stdlib_new_delete.dll.a ./stdlib_new_delete.obj -o ./stdlib_new_delete.dll

g++ -c -O2 -DNDEBUG -fvisibility=hidden ./stdlib_new_delete.cpp -o ./stdlib_new_delete.obj
g++ -O2 -DNDEBUG -shared -fPIC -Wl,--out-implib,./stdlib_new_delete.dll.a ./stdlib_new_delete.obj -o ./stdlib_new_delete.dll


*/