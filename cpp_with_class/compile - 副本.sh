
# 编译 DLL
# For vs2019
# 关闭输出版权信息 /nologo

# 方法一：
# 在 LINK 的时候加上 /DEBUG  信息，就可以包含 调试信息了
# Compile
cl /c /Od /Zi /EHsc /GS- /MDd /nologo /Fd:get_rand.pdb get_rand.cpp

# Link
link /DLL /DEBUG /INCREMENTAL:NO /NOLOGO /DEF:get_rand.def get_rand.obj /PDB:get_random.pdb /OUT:get_random.dll


# 方法二：
# 这种方式携带大量的调试信息，
# 一次性编译（但是这种方法没法使用 .def 文件）
cl /LD /EHsc  get_rand.cpp
cl /LDd /EHsc  get_rand.cpp   # Debug 版本
cl /LDd /EHsc /MDd /Zi /Od /nologo /INCREMENTAL:NO /GS- get_rand.cpp /Fd:get_rand.pdb






# 编译 EXE
cl /c /Od /Zi /EHsc /GS- /MDd /nologo /Fd:main.pdb main.cpp
link /DEBUG /INCREMENTAL:NO /NOLOGO main.obj /PDB:main.pdb /OUT:main.exe






