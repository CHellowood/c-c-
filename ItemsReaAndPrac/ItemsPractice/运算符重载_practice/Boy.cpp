#include "Boy.h"
#include <sstream>
#include <iomanip>

unsigned Boy::LAST_ID = 0;

Boy::Boy(const char* name, int age, int salary, int darkHorse)
{
	if (!name) {
		name = "未命名";
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);//拷贝

	this->age       = age;
	this->salary    = salary;
	this->darkHorse = darkHorse;
	this->id        = ++LAST_ID;
}

Boy::Boy(int salary)
{
    const char* defaultName = "未命名";
	this->name = new char[strlen(defaultName) + 1];
	strcpy_s(this->name, strlen(defaultName) + 1, defaultName);//拷贝

	this->age = 0;
	this->salary = salary;
	this->darkHorse = 0;
	this->id = ++LAST_ID;
}

Boy::~Boy()
{
	if (name) delete[] name;
}

//赋值运算符重载(拷贝构造函数)
Boy& Boy::operator=(const Boy& boy)
{
	if (name) delete[] name;

	this->name = new char[strlen(boy.name) + 1];
	strcpy_s(this->name, strlen(boy.name) + 1, boy.name);

	this->age       = boy.age;
	this->salary    = boy.salary;
	this->darkHorse = boy.darkHorse;

	return *this;
}

//关系运算符重载
bool Boy::operator>(const Boy& boy) const
{
	if (this->power() > boy.power()) {
		return true;
	}
	return false;
}

//关系运算符重载
bool Boy::operator<(const Boy& boy) const
{
	if (this->power() < boy.power()) {
		return true;
	}
	return false;
}

//关系运算符重载
bool Boy::operator==(const Boy& boy) const
{
	if (this->power() == boy.power()) {
		return true;
	}
	return false;
}

//下标运算符重载
int Boy::operator[](std::string index) const
{
	//if (index == NAME_KEY) {
	//	return (int)name;//数据溢出
	//}
	//else 
	if (index == AGE_KEY) {
		return age;
	}
	else if (index == SALARY_KEY) {
		return salary;
	}
	else if (index == DARK_HORSE_KEY) {
		return darkHorse;
	}
	else {
		return -1;
	}
}

//下标运算符重载
int Boy::operator[](int index) const
{
	switch (index) {
	  //case NAME:       return (int)name;//数据溢出
	  case AGE:        return age;
	  case SALARY:     return salary;
	  case DARK_HORSE: return darkHorse;
	  default:         return -1;
	}
}

////输出运算符重载
//std::ostream& Boy::operator<<(const std::ostream& os)
//{
//	os << "编号: " << std::setw(ID_OUT_WIDTH) << ALIGN << id
//		<< "\t姓名: " << std::setw(NAME_OUT_WIDTH) << ALIGN << name
//		<< "\t年龄: " << std::setw(AGE_OUT_WIDTH) << ALIGN << age
//		<< "\t薪资: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << salary
//		<< "\t潜力值: " << std::setw(DARK_HORSE_OUT_WIDTH) << ALIGN << darkHorse;
//	return os;
//}

////输入运算符重载
//std::istream& Boy::operator>>(std::istream& is)
//{
//	std::string name2;
//	is >> name2 >> age >> salary >> darkHorse;
//
//	if (name) delete[] name;
//
//	name = new char[strlen(name2.c_str()) + 1];
//	strcpy_s(name, strlen(name2.c_str()) + 1, name2.c_str());
//
//	return is;
//}

//类型运算符重载
Boy::operator int() const
{
	return power();
}

//类型运算符重载
Boy::operator char* () const
{
	return name;
}

//描述
std::string Boy::description() const
{
	std::stringstream ret;
	ret << "编号: " << std::setw(ID_OUT_WIDTH) << ALIGN << id
		<< "\t姓名: " << std::setw(NAME_OUT_WIDTH) << ALIGN << name
		<< "\t年龄: " << std::setw(AGE_OUT_WIDTH) << ALIGN << age
		<< "\t薪资: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << salary
		<< "\t潜力值: " << std::setw(DARK_HORSE_OUT_WIDTH) << ALIGN << darkHorse;

	return ret.str();
}

//综合能力值
int Boy::power() const
{
	//设置比较规则: 薪资 * 潜力值 + (100 - 年龄) * 1000
	int ret = salary * darkHorse + (100 - age) * 1000;
	return ret;
}

//使用全局友元函数来实现输出运算符重载
std::ostream& operator<<(std::ostream& os, const Boy& boy) 
{
	os << "编号: " << std::setw(ID_OUT_WIDTH) << ALIGN << boy.id
	   << "\t姓名: " << std::setw(NAME_OUT_WIDTH) << ALIGN << boy.name
   	   << "\t年龄: " << std::setw(AGE_OUT_WIDTH) << ALIGN << boy.age
 	   << "\t薪资: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << boy.salary
	   << "\t潜力值: " << std::setw(DARK_HORSE_OUT_WIDTH) << ALIGN << boy.darkHorse;
	return os;
}

//使用全局友元函数来实现输入运算符重载
std::istream& operator>>(std::istream& is, Boy& boy)
{
	std::string name2;
	is >> name2 >> boy.age >> boy.salary >> boy.darkHorse;
	
	if (boy.name) delete[] boy.name;
	
	boy.name = new char[strlen(name2.c_str()) + 1];
	strcpy_s(boy.name, strlen(name2.c_str()) + 1, name2.c_str());

	return is;
}
