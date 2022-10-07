

del /Q /F math.obj math.dll math.exp math.lib
:: pause

call F:\MyProgramFiles\VS\VS2019Pro\VC\Auxiliary\Build\vcvars32.bat

cl /nologo /c math.c

:: lib /nologo /def:math.def math.obj /out:math.lib

link /nologo /dll /def:math.def math.obj /out:math.dll

:: cl /LD math.c

echo ====Finished====

:: "E:\ReverseEngine\PEParser_CFF_NTCore_ExplorerSuite\CFF_Explorer\CFF Explorer.exe" .\math.dll

pause