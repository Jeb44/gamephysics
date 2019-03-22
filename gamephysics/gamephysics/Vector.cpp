#include "Vector.h"


Vector::Vector() {
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::~Vector() {}

void Vector::addition(const Vector v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	
}

Vector operator+(Vector lhs, const Vector& rhs) {
	lhs += rhs;
	return lhs;
}
Vector& Vector::operator+=(const Vector& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

void Vector::subtract(const Vector v) {
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

Vector operator-(Vector lhs, const Vector& rhs) {
	lhs -= rhs;
	return lhs;
}
Vector& Vector::operator-=(const Vector& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

bool operator==(const Vector& lhs, const Vector & rhs) {
	if (lhs.x != rhs.x)
		return false;
	if (lhs.y != rhs.y)
		return false;
	if (lhs.z != rhs.z)
		return false;

	return true;
}

bool operator!=(const Vector& lhs, const Vector & rhs) {
	if (lhs.x == rhs.x)
		return false;
	if (lhs.y == rhs.y)
		return false;
	if (lhs.z == rhs.z)
		return false;

	return true;
}




std::string Vector::print() {
	return "(" + stringHelper::reduceFloats(this->x)
		+ ", " + stringHelper::reduceFloats(this->y)
		+ ", " + stringHelper::reduceFloats(this->z) + ")";
}