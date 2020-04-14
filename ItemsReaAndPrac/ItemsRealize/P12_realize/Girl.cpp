#include "Girl.h"
#include "Boy.h"
#include <sstream>
#include <iomanip>
#include <iostream>

Girl::Girl() : Object() {
	this->gender = "女";
	this->yanzhi = 0;
	this->wage = 0;
}

Girl::Girl(string name, int age, int yanzhi, int wage)
	: Object(name, age) {
	this->gender = "女";
	this->yanzhi = yanzhi;
	this->wage = wage;
}

//获取性别
string Girl::getGender() const {
	return gender;
}

//获取颜值
int Girl::getYanzhi() const {
	return yanzhi;
}

//获取薪资
int Girl::getWage() const {
	return wage;
}

//判断boy是否符合该girl的要求
bool Girl::satisfied(Boy &boy) const {
	if (boy.getYanzhi() >= yanzhi - yanzhi * YANZHI_SCALE &&
		boy.getWage() >= wage + wage * WAGE_SCALE) {
		return true;
	}
	return false;
}

//用户描述
string Girl::description() const {
	stringstream ret;
	ret << "名字:" 
		<< setw(9) << setiosflags(ios::left)
		<< name
		<< "\t\t性别:女"
		<< "\t\t年龄:" << age
		<< "\t\t颜值:"
		<< setw(3) << setiosflags(ios::left) //把下一个数据的宽度设为3并进行左对齐
		<< yanzhi
		<< "\t\t薪资:" << wage;

	return ret.str();
}

//输入多个用户信息
void Girl::inputGirls(vector<Girl>& girls) {
	int i = 1;
	while (true) {
		string name;
		int age;
		int yanzhi;
		int wage;

		cout << "\t<<第" << i++ << "位girl>>\n";
		cout << "名字[输入 end 结束]:";
		cin >> name;

		if (name == "end") break;

		cout << "年龄:";
		cin >> age;

		cout << "颜值:";
		cin >> yanzhi;

		cout << "工资:";
		cin >> wage;

		girls.push_back(Girl(name, age, yanzhi, wage));
	}
}

//输入单个用户信息
void Girl::inputGirl(Girl& girl) {
	string name;
	int age;
	int yanzhi;
	int wage;

	cout << "\n输入girl的信息>>\n";
	cout << "名字:";
	cin >> name;

	cout << "年龄:";
	cin >> age;

	cout << "颜值:";
	cin >> yanzhi;

	cout << "工资:";
	cin >> wage;

	girl = Girl(name, age, yanzhi, wage);
}