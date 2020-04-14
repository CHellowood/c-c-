//#pragma once

#ifndef _BEEF_H_
#define _BEEF_H_

//假设一斤牛肉40块钱
#define BEEF_MONEY 40

class Money;//钱
class Pork; //猪肉

class Beef  //牛肉
{
public:
	Beef(int weight = 0);

	int getWeight() const;

	//// - * / % 这几个运算符的重载和 + 的差不多 
	////使用成员函数来实现运算符重载
	////使用时第一个参数必须为该类的对象, 否则会报错 
	////牛肉 + 牛肉
	//Money operator+(const Beef& beef);

	////牛肉 + 猪肉
	//Money operator+(const Pork& pork);


	//使用全局友元函数来实现运算符重载
	//使用时只需有对应的重载函数即可
	//牛肉 + 牛肉
	friend Money operator+(const Beef& beef1, const Beef& beef2);

	//牛肉 + 猪肉
	friend Money operator+(const Beef& beef, const Pork& pork);

private:
	int weight;
};

#endif 