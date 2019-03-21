#include "Vector.h"

Vector::Vector() {}

Vector::~Vector() {}

void Vector::addition(const Vector v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	
}

Vector& Vector::operator+=(const Vector& rhs) {
	// TODO: hier Rückgabeanweisung eingeben
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

char* Vector::print() {
	
}

Vector operator+(Vector lhs, const Vector& rhs) {
	lhs += rhs;
	return lhs;
}
