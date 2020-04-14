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
	ret << getName() << "-" << getGender() << "-" << getAge() << "��-��ֵ("
		 << getYanzhi() << ")-����(" << getWage() << ")";
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

		cout << endl << "----------��" << i << "λ----------" << endl;
		cout << "����[���� end ����]:";
		cin >> name;

		if (name == "end") {
			break;
		}

		cout << "�Ա�:";
		cin >> gender;

		cout << "����:";
		cin >> age;

		cout << "��ֵ:";
		cin >> yanzhi;

		cout << "����:";
		cin >> wage;

		cout << "Ҫ��Է�����ֵ����:";
		cin >> demandYanzhi;

		cout << "Ҫ��Է��Ĺ�������:";
		cin >> demandWage;

		objects.push_back(Object(name, gender, age, yanzhi, wage, demandYanzhi, demandWage));
		i++;
	}
}