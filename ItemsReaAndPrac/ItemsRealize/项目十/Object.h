#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Object {
public:
	Object();
	Object(string name, string gender, int age, int yanzhi, int wage, int demandYanzhi, int demandWage);
	~Object();

	string getName() const;
	string getGender() const;
	int getAge() const;
	int getYanzhi() const;
	int getWage() const;

	bool satisfied(int objectYanzhi, int objectWage) const;
	string description() const;//描述
	static void input(vector<Object> &objects);//输入

private:
	string name;     //名字
	string gender;   //性别
	int age;         //年龄
	int yanzhi;      //颜值
	int wage;        //工资
	int demandYanzhi;//要求颜值
	int demandWage;  //要求工资

};