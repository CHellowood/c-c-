#pragma once
#include <string>

using namespace std;

class Class {					        //class: 类
public:							        //公有的
	Class();					        //手动定义的默认构造函数
	Class(string name, int age);        //自定义的带参数的构造函数
	Class(const Class &copy);		    //拷贝构造函数
	Class& operator=(const Class &copy);//赋值构造函数
	~Class();                           //析构函数: 析构函数不能有参数

	void eat();					        //吃东西
	void play();				        //玩
	void sleep();				        //睡觉
	void work();			            //工作
	void description() const;           //描述 const限定函数内数据的值不能改变
	string callName() const;
	int callAge() const; 
	int callWage() const;
	void modifyP(char *py);
	static int callClassNum();         //静态成员函数

private:						       //私有的
	string name;				       //名字
	int age;					       //年龄
	int wage;					       //工资
	char *p;
	static int ClassNum;               //对象数量, 静态数据成员声明
};