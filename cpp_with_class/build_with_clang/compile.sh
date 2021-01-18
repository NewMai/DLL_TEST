#################################################################################
# 编译 32位的 DLL
# For clang++

# 找到 Windows 上可用的后端：
C:\MyProgramFiles\llvm-8_x64\bin\clang++.exe -print-effective-triple
C:\MyProgramFiles\llvm-8_x64\bin\clang++.exe -print-target-triple


# 方法一：
# 在 LINK 的时候加上 /DEBUG  信息，就可以包含 调试信息了
# Compile
# --target=x86_64-pc-windows-msvc19.11.0
C:\MyProgramFiles\llvm-8_x64\bin\clang++.exe -c -m32 -g --target=x86_64-pc-windows-msvc ..\get_rand.cpp -o get_rand.obj

# Link
C:\MyProgramFiles\llvm-8_x64\bin\clang++.exe -m32 -g -shared get_rand.obj -o get_random.dll


# 方法二：
# 一次性编译
C:\MyProgramFiles\llvm-8_x64\bin\clang++.exe -m32 -g -shared ..\get_rand.cpp -o get_random.dll





#################################################################################
# 编译 EXE
cl /c /Od /Zi /EHsc /GS- /MDd /nologo /Fd:main.pdb main.cpp
link /DEBUG /INCREMENTAL:NO /NOLOGO main.obj /PDB:main.pdb /OUT:main.exe

C:\MyProgramFiles\llvm-8_x64\bin\clang++.exe -m32 -g --target=x86_64-pc-windows-msvc ..\main.cpp -o main.exe




