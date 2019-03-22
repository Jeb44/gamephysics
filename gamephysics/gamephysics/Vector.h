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

	void multiplication(const float scalar);
	Vector& operator*=(const float& scalar);
	friend Vector operator*(Vector lhs, const float& scalar);

	//add static functions
	Vector negate();
	float length();
	Vector normalize(); 
	float dot(const Vector& rhs);
	Vector project(const Vector& rhs);
	Vector cross(const Vector& rhs);

	friend bool operator==(const Vector& lhs, const Vector& rhs);
	friend bool operator!=(const Vector& lhs, const Vector& rhs);

	std::string print();

};

