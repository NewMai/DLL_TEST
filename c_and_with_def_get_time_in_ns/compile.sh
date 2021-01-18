

# 只编译，不链接
ml64 /c GetHighAccuracyTime.asm

# 根据 def 文件生成 lib 文件【可选】
lib /def:GetHighAccuracyTime.def GetHighAccuracyTime.obj /out:GetHighAccuracyTime.lib

# 根据 def 文件和 obj 文件生成 dll 文件 和 lib 文件，如果没有输入 def 文件，则 dll 中没有导出表，并且不会生成 lib 文件
# /noentry 选项要加上，就是表明不需要 DllMain() 函数
link /dll /noentry /def:GetHighAccuracyTime.def GetHighAccuracyTime.obj /out:GetHighAccuracyTime.dll

# 直接生产 DLL 文件【可选】
cl /LD GetHighAccuracyTime.asm



# 编译 test.c， 生成 test.obj
cl /c test.c

# 根据 test.obj 和 math.lib 生成 test.exe
link test.obj GetHighAccuracyTime.lib /out:test.exe

# 直接根据 test.c 和 math.lib 生成 test.exe 【可选】
cl test.c GetHighAccuracyTime.lib

# 查看 dll 的导出表【可选】
dumpbin /EXPORTS GetHighAccuracyTime.dll

# 查看 exe 的导入表【可选】
dumpbin /IMPORTS test.exe

# 查看 lib 的导出表【可选】
dumpbin /EXPORTS GetHighAccuracyTime.lib

