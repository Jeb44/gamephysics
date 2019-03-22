#include "Test.h"
#include "Vector.h"
#include <iostream>

int main()
{
	Vector a(1.0f, 1.0f, 0.50f);
	Vector b(1.0f, 1.0f, 1.50f);

	std::cout << "A" << a.print() << std::endl;
	std::cout << "B" << b.print() << std::endl;

	Vector c = a + b;
	std::cout << "c = a + b | " << c.print() << std::endl;

	c = a - b;
	std::cout << "c = a - b | " << c.print() << std::endl;

	c += a;
	std::cout << "c += a | " << c.print() << std::endl;

	c -= b;
	std::cout << "c -= b | " << c.print() << std::endl;
	
	bool d = a == b;
	std::cout << d << std::endl;
	d = a == a;
	std::cout << d << std::endl;

	/*std::cout << "a == b | " << (a == b) << std::endl;
	std::cout << "a != b | " << (a != b) << std::endl;
	std::cout << "a == a | " << (a == a) << std::endl;
	std::cout << "a != a | " << (a != a) << std::endl;*/

	getchar();
}