#include "Money.h"
#include <sstream>

Money::Money(int money) {
	this->money = money;
}

std::string Money::description()
{
	std::stringstream ret;
	ret << money << "¿éÇ®";

	return ret.str();
}
