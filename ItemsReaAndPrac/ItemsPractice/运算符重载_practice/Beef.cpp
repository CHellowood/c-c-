#include "Beef.h"
#include "Money.h"
#include "Pork.h"

Beef::Beef(int weight) {
	this->weight = weight;
}

int Beef::getWeight() const
{
	return weight;
}

//使用成员函数来实现运算符重载
//牛肉 +　牛肉
//Money Beef::operator+(const Beef& beef)
//{
//	int money = (this->weight + beef.weight) * BEEF_MONEY;
//	return Money(money);
//}

//牛肉 + 猪肉
//Money Beef::operator+(const Pork& pork)
//{
//	int money = this->weight * BEEF_MONEY + pork.getWeight() * PORK_MONEY;
//	return Money(money);
//}

//使用全局友元函数来实现运算符重载
//牛肉 + 牛肉
Money operator+(const Beef& beef1, const Beef& beef2) {
	int money = (beef1.weight + beef2.weight) * BEEF_MONEY;
	return Money(money);
}

//牛肉 +　猪肉
Money operator+(const Beef& beef, const Pork& pork) {
	int money = beef.weight * BEEF_MONEY + pork.getWeight() * PORK_MONEY;
	return Money(money);
}
