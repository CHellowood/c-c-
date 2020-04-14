#pragma once
#include "Object.h"

/*告诉编译器存在这个类, 然后在cpp文件里包含这个类的头文件*/
class Girl;

/*薪资比例*/
#define WAGE_SCALE 0.1
/*颜值比例*/
#define YANZHI_SCALE 0.1 

class Boy : public Object
{
public:
	Boy();
	Boy(string name, int age, int yanzhi, int wage);

	//获取性别
	string getGender() const;
	
	//获取颜值
	int getYanzhi() const;
	
	//获取薪资
	int getWage() const;

	//判断girl是否符合该boy的要求
	bool satisfied(Girl& girl) const;
	
	//用户描述
	string description() const;

	//输入多个用户信息
	static void inputBoys(vector<Boy> &boys);  

	//输入单个用户信息
	static void inputBoy(Boy &boy);

private:
	string gender;   //性别
	int yanzhi;      //颜值
	int wage;        //工资
};

