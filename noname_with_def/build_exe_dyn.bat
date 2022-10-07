

del /Q /F test_dyn.obj test_dyn.exp test_dyn.exe
@REM pause

call F:\MyProgramFiles\VS\VS2019Pro\VC\Auxiliary\Build\vcvars32.bat

cl /nologo /c test_dyn.c

link /nologo test_dyn.obj /out:test_dyn.exe

@REM cl test_dyn.c

echo ====Finished====

@REM "E:\ReverseEngine\PEParser_CFF_NTCore_ExplorerSuite\CFF_Explorer\CFF Explorer.exe" .\test_dyn.exe

.\test_dyn.exe

pause