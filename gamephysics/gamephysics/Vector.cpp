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

Vector& Vector::operator-=(const Vector& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

Vector operator-(Vector lhs, const Vector& rhs) {
	lhs -= rhs;
	return lhs;
}

void Vector::multiplication(const float scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

Vector & Vector::operator*=(const float & scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;

	return *this;
}

Vector operator*(Vector lhs, const float & scalar) {
	lhs.x *= scalar;
	lhs.y *= scalar;
	lhs.z *= scalar;
	return lhs;
}

Vector Vector::negate() {
	return *this *= -1.0f;
}

float Vector::length() {	
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

Vector Vector::normalize() {
	*this *= (1 / this->length());
	return *this;
}

float Vector::dot(const Vector& rhs) {
	return this->x * rhs.x + 
			this->y * rhs.y +
			this->z * rhs.z;
}

Vector Vector::project(const Vector& rhs) {
	float s = this->dot(rhs) / pow(this->length(), 2);
	return *this * s;
}

Vector Vector::cross(const Vector & rhs) {
	return Vector(this->y * rhs.z - this->z * rhs.y,
		this->z * rhs.x - this->x * rhs.z,
		this->x * rhs.y - this->y * rhs.x);
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


