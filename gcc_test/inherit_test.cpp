

#include <stdint.h>
#include <stdio.h>

// Storage classes
enum Qualifiers : uint8_t
{
	Q_None = 0,
	Q_Const = 1 << 0,
	Q_Volatile = 1 << 1,
	Q_Far = 1 << 2,
	Q_Huge = 1 << 3,
	Q_Unaligned = 1 << 4,
	Q_Restrict = 1 << 5,
	Q_Pointer64 = 1 << 6
};

void test1()
{
	int a = 0, b = 0;

	Qualifiers c = Qualifiers::Q_Const;
	printf("c = %d\n", c);

	c = Qualifiers::Q_Unaligned;
	printf("c = %d\n", c);
}

int main()
{
	test1();
	return 0;
}



