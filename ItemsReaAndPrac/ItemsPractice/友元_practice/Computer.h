//#pragma once
#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <string>
#include "ComputerService.h"

class Computer
{
public:
	Computer();
	std::string description();

private:
	std::string cpu;

	//全局函数作为友元函数
	//friend void upgrade(Computer *computer);

	//其他类的成员函数作为友元函数
	//friend void ComputerService::upgrade(Computer* computer);

	//友元类
	friend class ComputerService;
};




#endif 