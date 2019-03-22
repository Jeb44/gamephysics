#pragma once

#include <string>
#include <stdio.h>

class stringHelper
{
public:
	stringHelper();
	~stringHelper();

	static std::string reduceFloats(float number, int newPrecision = 2);
	static std::string reduceFloats(double number, int newPrecision = 2);
	static std::string reduceFloats(long double number, int newPrecision = 2);
};

