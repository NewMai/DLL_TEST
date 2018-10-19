
#include <stdio.h>

#ifdef _DLL_EXPORT_
#define DLL_IMPORT_OR_EXPORT __declspec(dllexport)
#else
#define DLL_IMPORT_OR_EXPORT __declspec(dllimport)
#endif

DLL_IMPORT_OR_EXPORT int MyAdd(int a, int b);
DLL_IMPORT_OR_EXPORT int MySub(int a, int b);
DLL_IMPORT_OR_EXPORT int MyMul(int a, int b);
