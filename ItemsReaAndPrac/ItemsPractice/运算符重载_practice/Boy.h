//#pragma once

#ifndef _BOY_H_
#define _BOY_H_

#include <string>
#include <iostream>

#define NULL 0

//#define NAME_KEY       "name"
#define AGE_KEY        "age"
#define SALARY_KEY     "salary"
#define DARK_HORSE_KEY "darkHorse"

//输出宽度
#define ID_OUT_WIDTH         10
#define NAME_OUT_WIDTH       10
#define AGE_OUT_WIDTH        3
#define SALARY_OUT_WIDTH     8
#define DARK_HORSE_OUT_WIDTH 3

//左对齐
#define LEFT std::left

//右对齐
#define RIGHT std::right

//对齐
#define ALIGN LEFT

typedef enum {
//	NAME,
	AGE,
	SALARY,
	DARK_HORSE
}KEY;


class Boy
{
public:
	Boy(const char* name = NULL, int age = 0,
		int salary = 0, int darkHorse = 0);
	Boy(int salary);
	~Boy();

	//赋值运算符重载(拷贝构造函数)
	Boy& operator=(const Boy& boy);

	//关系运算符重载
	bool operator>(const Boy& boy) const;
	bool operator<(const Boy& boy) const;
	bool operator==(const Boy& boy) const;

	//下标运算符重载
	int operator[](std::string index) const;
	int operator[](int index) const;

	////使用成员函数来实现输出运算符重载
	////不推荐使用成员函数来实现输出运算符重载
	//std::ostream& operator<<(const std::ostream& os);

	////使用成员函数来实现输入运算符重载
	////不推荐使用成员函数来实现输入运算符重载
	//std::istream& operator>>(std::istream& is);

	//使用全局友元函数来实现输出运算符重载
	friend std::ostream& operator<<(std::ostream& os, const Boy& boy);

	//使用全局友元函数来实现输入运算符重载
	friend std::istream& operator>>(std::istream& is, Boy& boy);

	//类类型转普通类型（类型运算符重载）
	operator int() const;
	operator char* () const;

	//描述
	std::string description() const;

private:
	char* name;             //姓名
	int   age;              //年龄
	int salary;             //薪资
	int darkHorse;          //黑马, 潜力值
	unsigned id;            //编号
	static unsigned LAST_ID;//最后(最新)的编号

	int power() const;            //综合能力值
};

std::ostream& operator<<(std::ostream& os, const Boy& boy);
std::istream& operator>>(std::istream& is, Boy& boy);

#endif 