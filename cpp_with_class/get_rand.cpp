
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "get_rand.h"

#include <iostream>
using namespace std;


class MyRandom
{
public:
	MyRandom()
	{
		cout << "Run in to constructor of MyRandom" << endl;
		srand(time(NULL));
	}
};

static MyRandom myrand;

BOOL APIENTRY DllMain(HANDLE  hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		printf("DLL process attached!\n");
		//srand(time(NULL));
		break;
	}
	case DLL_PROCESS_DETACH:
	{
		printf("DLL process detached!\n");
		break;
	}
	case DLL_THREAD_ATTACH:
	{
		printf("DLL thread attached!\n");
		//srand(time(NULL));
		break;
	}
	case DLL_THREAD_DETACH:
	{
		printf("DLL thread detached!\n");
		break;
	}
	default:
	{
		printf("Unknown resean for dll call!\n");
		break;
	}
	}

	return TRUE;
}

void get_rand_data(void* data, uint32_t datalen)
{
	int i = 0;
	uint8_t* p = (uint8_t*)data;
	for (i = 0; i < datalen; i++)
	{
		p[i] = rand() % 256;
	}
}
