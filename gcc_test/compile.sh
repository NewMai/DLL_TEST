

# 打开 gcc64
gcc64
cd /d E:\DLL_TEST\gcc_test

gcc -c ./gcc_test.c -o ./gcc_test.o -v

gcc ./gcc_test.o -o ./gcc_test.exe -v




# 只编译，不链接
cl /c math.c

# 根据 obj 文件生成 dll 文件， 如果有 __declspec(dllexport)， 则会自动生成 lib 文件
link /dll math.obj /out:math.dll

# 根据 def 文件生成 lib 文件【可选】
lib /def:math.def math.obj /out:math.lib   

# 直接生产 DLL 文件【可选】
cl /LD math.c

# 编译 test.c， 生成 test.obj
cl /c test.c

# 根据 test.obj 和 math.lib 生成 test.exe
link test.obj math.lib /out:test.exe

# 直接根据 test.c 和 math.lib 生成 test.exe【可选】
cl test.c math.lib

# 查看 dll 的导出表【可选】
dumpbin /EXPORTS math.dll

# 查看 exe 的导入表【可选】
dumpbin /IMPORTS test.exe

# 查看 lib 的导出表【可选】
dumpbin /EXPORTS math.lib

