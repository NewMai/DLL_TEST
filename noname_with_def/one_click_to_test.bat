
del /Q /F *.obj *.exp *.lib *.dll *.exe
pause

cmd.exe /C "build_dll.bat"

start cmd.exe /C "build_exe.bat"
start cmd.exe /C "build_exe_dyn.bat"

pause