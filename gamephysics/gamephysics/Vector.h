#pragma once

class Vector {
public:
	Vector();
	~Vector();

	float x, y, z;

	void addition(const Vector v);
	Vector& operator+=(const Vector& rhs);
	friend Vector operator+(Vector lhs, const Vector& rhs);

	char* print();
};

