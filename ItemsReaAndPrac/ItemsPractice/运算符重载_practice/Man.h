//#pragma once

#ifndef _MAN_H_
#define _MAN_H_

#include <iostream>

class Boy;

class Man
{
public:
	Man(const char* name, int age, int salary);
	Man(const Boy& boy);
	~Man();

	//使用全局友元函数来实现输出运算符重载
	friend std::ostream& operator<<(std::ostream& os, const Man& man);

	////使用全局友元函数来实现输入运算符重载
	//friend std::istream& operator>>(std::istream& is, Man& man);

private:
	char* name;
	int age;
	int salary;
};

std::ostream& operator<<(std::ostream& os, const Man& man);
//std::istream& operator>>(std::istream& is, Man& man);

#endif 