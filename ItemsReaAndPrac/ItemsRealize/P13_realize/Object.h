#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Object {
public:
	Object();
	Object(string name, int age);// string gender, int age, int yanzhi, int wage);

	string getName() const;
	//string getGender() const;
	int getAge() const;
	//int getYanzhi() const;
	//int getWage() const;

	//bool satisfied(int objectYanzhi, int objectWage) const;
	//string description() const;//描述
	//static void input(vector<Object> &objects);  //输入用户信息

protected:
	string name;     //名字
	//string gender;   //性别
	int age;         //年龄
	//int yanzhi;      //颜值
	//int wage;        //工资
};