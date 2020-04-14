//#pragma once

#ifndef _MONEY_H_
#define _MONEY_H_

#include <string>

class Money
{
public:
	Money(int money = 0);

	std::string description();

private:
	int money;
};

#endif 