#pragma once
#include <string>
#include <stdio.h>
#include <math.h>
#include "stringHelper.h"

class Vector {
public:
	Vector();
	Vector(float x, float y, float z);
	~Vector();

	float x, y, z;

	void addition(const Vector v);
	Vector& operator+=(const Vector& rhs); //is friend faster?
	friend Vector operator+(Vector lhs, const Vector& rhs);

	void subtract(const Vector v);
	Vector& operator-=(const Vector& rhs);
	friend Vector operator-(Vector lhs, const Vector& rhs);

	friend bool operator==(const Vector& lhs, const Vector& rhs);
	friend bool operator!=(const Vector& lhs, const Vector& rhs);

	std::string print();
};

