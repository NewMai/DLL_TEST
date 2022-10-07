

# Setup env
set PATH=%PATH%;E:\MyProgramFiles\MSYS2\mingw32\bin

# Compile and link
gcc -c ./tcmalloc_test.c -o ./tcmalloc_test.o -v
gcc ./tcmalloc_test.o -o ./tcmalloc_test.exe -v

# Build
gcc ./tcmalloc_test.c -o ./tcmalloc_test.exe

gcc -g -DPERFTOOLS_DLL_DECL= ./tcmalloc_test.c -o ./tcmalloc_test.exe -L. -llibtcmalloc_minimal


# Open [MSYS2 MinGW 32-bit]
gcc -g ./tcmalloc_test.c -o ./tcmalloc_test.exe -ltcmalloc_minimal
gcc -g ./tcmalloc_test.c -o ./tcmalloc_test.exe -ltcmalloc_minimal.dll -ltcmalloc_minimal

# file:///G:/tmp/gperftools/docs/heap_checker.html
set HEAPCHECK=strict
.\tcmalloc_test.exe

HEAPCHECK=strict ./tcmalloc_test.exe

