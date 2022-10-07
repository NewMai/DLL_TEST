

del /Q /F test.obj test.exp test.exe
@REM pause

call F:\MyProgramFiles\VS\VS2019Pro\VC\Auxiliary\Build\vcvars32.bat

cl /nologo /c test.c

link /nologo test.obj math.lib /out:test.exe

@REM cl test.c math.lib

echo ====Finished====

@REM "E:\ReverseEngine\PEParser_CFF_NTCore_ExplorerSuite\CFF_Explorer\CFF Explorer.exe" .\test.exe

.\test.exe

pause