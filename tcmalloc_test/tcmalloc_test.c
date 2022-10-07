



#include <stdio.h>
#include <stdlib.h>
// #include "tcmalloc.h"

// #pragma comment(lib, "libtcmalloc_minimal.lib")

// Ref: https://blog.51cto.com/u_15069438/4547459


// $ HEAPCHECK=1 <path/to/binary> [binary args]

// HEAPPROFILE=/tmp/heapprof <path/to/binary> [binary args]
// $ pprof <path/to/binary> /tmp/heapprof.0045.heap  # run 'ls' to see options
// $ pprof --gv <path / to / binary> / tmp / heapprof.0045.heap


void test1()
{
	char* buf = NULL;

	buf = malloc(10);

	puts("Input string:");
	scanf("%s", buf);

	printf("You input string: [%s].\n", buf);
}



int main()
{
	test1();


	return 0;
}




