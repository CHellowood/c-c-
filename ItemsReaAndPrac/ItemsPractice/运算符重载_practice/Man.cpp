#include "Man.h"
#include "Boy.h"
#include <string>
#include <iomanip>

Man::Man(const char* name, int age, int salary)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);

	this->age = age;
	this->salary = salary;
}

Man::Man(const Boy& boy)
{
	int len = strlen((char*)boy) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, (char*)boy);

	this->age = boy[AGE];
	this->salary = boy[SALARY];
}

Man::~Man()
{
	delete[] name;
}

//使用全局友元函数来实现输出运算符重载
std::ostream& operator<<(std::ostream& os, const Man& man)
{
	os << "【男人】姓名: " << std::setw(NAME_OUT_WIDTH) << ALIGN << man.name
	   << "\t年龄: " << std::setw(AGE_OUT_WIDTH) << ALIGN << man.age
	   << "\t薪资: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << man.salary;
	return os;
}

////使用全局友元函数来实现输入运算符重载
//std::istream& operator>>(std::istream& is, Man& man)
//{
//	// TODO: 在此处插入 return 语句
//}
