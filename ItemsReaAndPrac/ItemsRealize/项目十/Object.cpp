#include <iostream>
#include <sstream>
#include "Object.h"
Object::Object() {
	name = "";
	gender = "";
	age = 0;
	yanzhi = 0;
	wage = 0;
}

Object::Object(string name, string gender, int age, int yanzhi, int wage, int demandYanzhi, int demandWage) {
	this->name = name;
	this->gender = gender;
	this->age = age;
	this->yanzhi = yanzhi;
	this->wage = wage;
	this->demandYanzhi = demandYanzhi;
	this->demandWage = demandWage;
}

Object::~Object() {

}

string Object::getName() const {
	return name;
}

string Object::getGender() const {
	return gender;
}

int Object::getAge() const {
	return age;
}

int Object::getYanzhi() const {
	return yanzhi;
}

int Object::getWage() const {
	return wage;
}

bool Object::satisfied(int objectYanzhi, int objectWage) const {
	if (objectYanzhi >= demandYanzhi || objectWage >= demandWage) {
		return true;
	}
	else {
		return false;
	}
}

string Object::description() const {
	stringstream ret;
	ret << getName() << "-" << getGender() << "-" << getAge() << "岁-颜值("
		 << getYanzhi() << ")-工资(" << getWage() << ")";
	return ret.str();
}

void Object::input(vector<Object> &objects){
	int i = 1;
	while (true) {
		string name;
		string gender;
		int age;
		int yanzhi;
		int wage;
		int demandYanzhi;
		int demandWage;

		cout << endl << "----------第" << i << "位----------" << endl;
		cout << "名字[输入 end 结束]:";
		cin >> name;

		if (name == "end") {
			break;
		}

		cout << "性别:";
		cin >> gender;

		cout << "年龄:";
		cin >> age;

		cout << "颜值:";
		cin >> yanzhi;

		cout << "工资:";
		cin >> wage;

		cout << "要求对方的颜值至少:";
		cin >> demandYanzhi;

		cout << "要求对方的工资至少:";
		cin >> demandWage;

		objects.push_back(Object(name, gender, age, yanzhi, wage, demandYanzhi, demandWage));
		i++;
	}
}