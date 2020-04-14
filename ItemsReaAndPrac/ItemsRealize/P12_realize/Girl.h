#pragma once
#include "Object.h"

/*告诉编译器存在这个类, 然后在cpp文件里包含这个类的头文件*/
class Boy;

/*薪资比例*/
#define WAGE_SCALE 0.1
/*颜值比例*/
#define YANZHI_SCALE 0.1 

class Girl : public Object
{
public:
	Girl();
	Girl(string name, int age, int yanzhi, int wage);

	//获取性别
	string getGender() const;

	//获取颜值
	int getYanzhi() const;

	//获取薪资
	int getWage() const;

	//判断boy是否符合该girl的要求
	bool satisfied(Boy& boy) const;

	//用户描述
	string description() const;

	//输入多个用户信息
	static void inputGirls(vector<Girl>& girls);

	//输入单个用户信息
	static void inputGirl(Girl& girl);

private:
	string gender;   //性别
	int yanzhi;      //颜值
	int wage;        //工资
};

