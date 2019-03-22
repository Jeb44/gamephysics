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

	std::cout << "a == b | " << (a == b) << std::endl;
	std::cout << "a != b | " << (a != b) << std::endl;
	std::cout << "a == a | " << (a == a) << std::endl;
	std::cout << "a != a | " << (a != a) << std::endl;

	float s = 2.0f;
	Vector d = a * s;
	std::cout << "A * s | " << d.print() << std::endl;
	
	d *= s;
	std::cout << "d *= s | " << d.print() << std::endl;

	d.negate();
	std::cout << "d negated | " << d.print() << std::endl;

	std::cout << "a length | " << a.length() << std::endl;
	std::cout << "b length | " << b.length() << std::endl;
	std::cout << "c length | " << c.length() << std::endl;
	std::cout << "d length | " << d.length() << std::endl;

	std::cout << "a normalized | " << a.normalize().print() << std::endl;
	std::cout << "b normalized | " << b.normalize().print() << std::endl;
	std::cout << "c normalized | " << c.normalize().print() << std::endl;
	std::cout << "d normalized | " << d.normalize().print() << std::endl;

	std::cout << "a length | " << a.length() << std::endl;
	std::cout << "b length | " << b.length() << std::endl;
	std::cout << "c length | " << c.length() << std::endl;
	std::cout << "d length | " << d.length() << std::endl;

	Vector e(1.0f, 2.0f, 0.50f);
	Vector f(1.0f, 1.0f, 1.50f);

	std::cout << "E" << e.print() << std::endl;
	std::cout << "F" << f.print() << std::endl;
	std::cout << "E dot F | " << e.dot(f) << std::endl;
	std::cout << "E project F | " << e.project(f).print() << std::endl;
	std::cout << "F project E | " << f.project(e).print() << std::endl;

	std::cout << "E cross F" << e.cross(f).print() << std::endl;
	std::cout << "F cross E" << f.cross(e).print() << std::endl;

	//Orthonormalbasis
	//Input
	Vector x(1.0f, 5.0f, -1.0f);
	Vector y(2.0f, 3.0f, 1.0f);
	Vector z;

	std::cout << std::endl;
	std::cout << "Orthonormalbasis: " << std::endl;
	std::cout << "x" << x.print() << std::endl;
	std::cout << "y" << y.print() << std::endl << std::endl;

	//Normalize x
	x.normalize();
	std::cout << "normalize x => x" << x.print() << std::endl;

	//Calculate Vector z = x "x" y
	z = x.cross(y);
	std::cout << "z = x cross y => z" << z.print() << std::endl << std::endl;

	//Cancel if |z| = 0
	std::cout << "z length = 0? It's " << z.length();
	if (z.length() == 0.0f) {
		std::cout << " => x & y are parallel" << std::endl << std::endl;
	}
	else {
		std::cout << " => continue" << std::endl << std::endl;

		//Normalize z
		z.normalize();
		std::cout << "normalize z => z" << z.print() << std::endl;

		//Calculate y = z "x" x
		y = z.cross(x);
		std::cout << "y = z cross x => x" << x.print() << std::endl << std::endl;

		//Results
		std::cout << "Results: " << std::endl;
		std::cout << "x" << x.print() << " | length = " << x.length() << std::endl;
		std::cout << "y" << y.print() << " | length = " << y.length() << std::endl;
		std::cout << "z" << z.print() << " | length = " << z.length() << std::endl;


	}

	getchar();
}