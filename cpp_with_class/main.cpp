
#include <stdio.h>
#include <Windows.h>
#include <iostream>
using namespace std;


class A
{
public:
	A()
	{
		printf("Initializing class A\n");
	}
};
class B
{
public:
	B()
	{
		printf("Initializing class B\n");
	}
};
class C
{
public:
	C()
	{
		printf("Initializing class C\n");
	}
};

static A a;
static B b;
static C c;

// void get_rand_data(void* data, uint32_t datalen);
typedef void (*FUNC)(void*, int);

void test_rand(FUNC get_rand_data)
{
	unsigned char data[2] = { 0 };
	if (get_rand_data)
	{
		get_rand_data(data, sizeof(data));

		printf("Got random data from dll:\n");
		for (int i = 0; i < sizeof(data); i++)
		{
			printf("data[%d] = %02X\n", i, data[i]);
		}
	}
	else
	{
		puts("Function [get_rand_data] is NULL!");
	}
}

void func1()
{
	char szDll[] = "get_random.dll";
	char szFuncName[] = "get_rand_data";
	FUNC get_rand_data = NULL;
	HMODULE hModule = LoadLibraryA(szDll);

	if (hModule)
	{
		get_rand_data = (FUNC)GetProcAddress(hModule, szFuncName);
		if (get_rand_data)
		{
			puts("Test1: \n");
			test_rand(get_rand_data);
			puts("\n");

			puts("Test2: \n");
			test_rand(get_rand_data);
			puts("\n");

			puts("Test3: \n");
			test_rand(get_rand_data);
			puts("\n");

		}
		else
		{
			puts("Get process failed!");
		}
		FreeLibrary(hModule);
		hModule = NULL;
	}
	else
	{
		puts("Load library failed!");
	}
}

int main()
{
	printf("Enter main() function\n");

	func1();

	printf("Leave main() function\n");

	return 0;
}
