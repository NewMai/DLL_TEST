

del /Q /F *.obj *.dll *.exp *.lib *.exe
pause


# 只编译，不链接
cl /c math.c

# 根据 def 文件生成 lib 文件【可选】
lib /def:math.def math.obj /out:math.lib

# 根据 def 文件和 obj 文件生成 dll 文件 和 lib 文件，如果没有输入 def 文件，则 dll 中没有导出表，并且不会生成 lib 文件
link /dll /def:math.def math.obj /out:math.dll

# 直接生产 DLL 文件【可选】
cl /LD math.c

# 编译 test.c， 生成 test.obj
cl /c test.c

# 根据 test.obj 和 math.lib 生成 test.exe
link test.obj math.lib /out:test.exe

# 直接根据 test.c 和 math.lib 生成 test.exe 【可选】
cl test.c math.lib

# 查看 dll 的导出表【可选】
dumpbin /EXPORTS math.dll

# 查看 exe 的导入表【可选】
dumpbin /IMPORTS test.exe

# 查看 lib 的导出表【可选】
dumpbin /EXPORTS math.lib

