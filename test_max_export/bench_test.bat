
@echo off

set rawName=test_max_export
:: set config=x86
set config=x64
set dir_gcc=gcc
set dir_msvc=msvc
@REM set export_funcs=65000  :: Both ok
@REM set export_funcs=65534  :: g++ ok, msvc, failed
@REM set export_funcs=65535  :: g++ ok, msvc, failed
@REM set export_funcs=65536  :: both failed, g++: ld.exe: error: export ordinal too large: 65536 ,  msvc: LINK : fatal error LNK1189: 超过 65535 对象的库限制
set export_funcs=70000
@REM set export_funcs=65

set script_gcc=build_dll_gcc.bat
set script_msvc=build_dll_msvc.bat

:: Remove previous build
if exist %dir_gcc% (
    rd /Q /S %dir_gcc%
)
if exist %dir_msvc% (
    rd /Q /S %dir_msvc%
)

md %dir_gcc%
md %dir_msvc%

:: Generate source files
python .\gen_func.py %export_funcs% %rawName%

copy %rawName%.*     %dir_gcc%
copy %rawName%.*     %dir_msvc%
copy %script_gcc%.*  %dir_gcc%
copy %script_msvc%.* %dir_msvc%


:: Working directory
set CWD=%cd%\
:: Script location
set ScriptLoc=%~dp0%
set FullpathGcc=%ScriptLoc%%dir_gcc%
set FullpathMsvc=%ScriptLoc%%dir_msvc%
:: set MyCMD=C:\Windows\System32\cmd.exe
set MyCMD=start cmd.exe /C


pushd %FullpathGcc%
%MyCMD% "%script_gcc%    %rawName% %config%"
popd

pushd %FullpathMsvc%
%MyCMD% "%script_msvc%    %rawName%  %config%"
popd


@REM %MyCMD% /C "%dir_gcc%\%script_gcc%    %rawName%"
@REM %MyCMD% /C "%dir_msvc%\%script_msvc%  %rawName%"

pause