//#include <iostream>
//#include <sstream>
//#include <iomanip>
#include "Object.h"

Object::Object() {
	name = "???";
	//gender = "";
	age = 0;
	//yanzhi = 0;
	//wage = 0;
}


Object::Object(string name, int age) {//string gender, int age, int yanzhi, int wage) {
	this->name = name;
	//this->gender = gender;
	this->age = age;
	//this->yanzhi = yanzhi;
	//this->wage = wage;
}

string Object::getName() const {
	return name;
}

/*
string Object::getGender() const {
	return gender;
}
*/

int Object::getAge() const {
	return age;
}

/*
int Object::getYanzhi() const {
	return yanzhi;
}

int Object::getWage() const {
	return wage;
}

bool Object::satisfied(int objectYanzhi, int objectWage) const {
	if (objectYanzhi >= yanzhi - yanzhi / 10 || 
		objectWage >= wage + wage / 10) {
		return true;
	}
	return false;
}

string Object::description() const {
	stringstream ret;
	ret << "����:" << name 
		<< "\t\t�Ա�:" << gender 
		<< "\t\t����:" << age 
		<< "\t\t��ֵ:" 
		<< setw(3) << setiosflags(ios::left) //����һ�����ݵĿ����Ϊ3�����������
		<< yanzhi
		<< "\t\tн��:" << wage;

	return ret.str();
}

void Object::input(vector<Object>& objects){
	int i = 1;
	while (true) {
		string name;
		string gender;
		int age;
		int yanzhi;
		int wage;

		cout << "\t<<��" << i++ << "λ>>\n";
		cout << "����[���� end ����]:";
		cin >> name;

		if (name == "end") break;

		cout << "�Ա�:";
		cin >> gender;

		cout << "����:";
		cin >> age;

		cout << "��ֵ:";
		cin >> yanzhi;

		cout << "����:";
		cin >> wage;

		objects.push_back(Object(name, gender, age, yanzhi, wage));
	}
}
*/
