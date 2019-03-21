#include "Test.h"
#include <string>

Test::Test() {}


Test::~Test() {}

std::string Test::print() {
	std::string str = std::string("This is a test class");
	return str;
}

