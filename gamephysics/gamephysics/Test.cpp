#include "Test.h"
#include <stdio.h>

Test::Test()
{
}


Test::~Test()
{
}

void Test::print()
{
	printf("Ich bin eine Testklasse!\n");
}

void Test::sum(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

