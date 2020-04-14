//#pragma once

#ifndef _PORK_H_
#define _PORK_H_

//假设一斤猪肉30块钱
#define PORK_MONEY 30

class Money;//钱
class Beef; //牛肉

class Pork  //猪肉
{
public:
	Pork(int weight = 0);

	int getWeight() const;

	//// - * / % 这几个运算符的重载和 + 的差不多 
	////使用成员函数来实现运算符重载
	////使用时第一个参数必须为该类的对象, 否则会报错 
	////猪肉 + 猪肉
	//Money operator+(const Pork& pork);

	////猪肉 + 牛肉
	//Money operator+(const Beef& beef);


	//使用全局友元函数来实现运算符重载
	//使用时只需有对应的重载函数即可
	//猪肉 + 猪肉
	friend Money operator+(const Pork& pork1, const Pork& pork2);

	//猪肉 + 牛肉
	friend Money operator+(const Pork& pork, const Beef& beef);

private:
	int weight;//猪肉的重量
};

#endif 