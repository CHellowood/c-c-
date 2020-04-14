#include <iostream>
#include "Class.h"

int Class::ClassNum = 0; //静态数据成员定义

Class::Class() {//手动定义的默认构造函数
	name = "hello world!";
	age = 18;
	wage = 4500;

	p = new char[24];
	strcpy(p, "China");

	ClassNum++;
}

Class::Class(string name, int age) {//自定义的带参数的构造函数
	this->name = name;
	this->age = age;
	
	p = new char[24];
	strcpy(p, "China");

	ClassNum++;
}

Class::Class(const Class &copy) {//拷贝构造函数
	name = copy.name;
	age = copy.age;
	wage = copy.wage;

	p = new char[24];
	strcpy(p, copy.p);
}
Class& Class::operator=(const Class &copy) {// 赋值构造函数
	if(this == &copy) {
		return *this;
	}

	name = copy.name;
	age = copy.age;
	wage = copy.wage;

	strcpy(p, copy.p);
	
	return *this;
}

Class::~Class() {//析构函数
	delete[] p;
}
void Class::eat() {
	cout << "吃橘子中... " << endl;
}

void Class::play() {
	cout << "打游戏中..." << endl;
}

void Class::sleep() {
	cout << "睡觉中... " << endl;
}

void Class::work() {
	cout << "工作中... " << endl;
}

string Class::callName() const{
	return name;
}

int Class::callAge() const{
	return age;
}

int Class::callWage() const{
	return wage;
}

void Class::modifyP(char *py) {
	if(!py) {
		return;
	}
	
	strcpy(this->p, py);
}

void Class::description() const{
	cout << "名字: " << callName() << " 年龄: " << callAge() << " 工资: " << callWage() << " 地址: " << p << endl;
}

int Class::callClassNum() {//静态成员函数
	return ClassNum;
}