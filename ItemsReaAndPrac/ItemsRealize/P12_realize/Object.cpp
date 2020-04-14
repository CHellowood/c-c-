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
	ret << "名字:" << name 
		<< "\t\t性别:" << gender 
		<< "\t\t年龄:" << age 
		<< "\t\t颜值:" 
		<< setw(3) << setiosflags(ios::left) //把下一个数据的宽度设为3并进行左对齐
		<< yanzhi
		<< "\t\t薪资:" << wage;

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

		cout << "\t<<第" << i++ << "位>>\n";
		cout << "名字[输入 end 结束]:";
		cin >> name;

		if (name == "end") break;

		cout << "性别:";
		cin >> gender;

		cout << "年龄:";
		cin >> age;

		cout << "颜值:";
		cin >> yanzhi;

		cout << "工资:";
		cin >> wage;

		objects.push_back(Object(name, gender, age, yanzhi, wage));
	}
}
*/
