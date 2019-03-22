#include "stringHelper.h"



stringHelper::stringHelper()
{
}


stringHelper::~stringHelper()
{
}

std::string stringHelper::reduceFloats(float number, int newPrecision)
{
	std::string str = std::to_string(number); 
	str.erase(str.find('.') + 1 + newPrecision, 6); //float has max precision of 6
	return str;
}

std::string stringHelper::reduceFloats(double number, int newPrecision)
{
	std::string str = std::to_string(number);
	str.erase(str.find('.') + 1 + newPrecision, 15); //float has max precision of 15
	return str;
}

std::string stringHelper::reduceFloats(long double number, int newPrecision)
{
	std::string str = std::to_string(number);
	str.erase(str.find('.') + 1 + newPrecision, 19); //float has max precision of 19
	return str;
}