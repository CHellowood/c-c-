#include "Pork.h"
#include "Money.h"
#include "Beef.h"

Pork::Pork(int weight) {
	this->weight = weight;
}

int Pork::getWeight() const
{
	return weight;
}

//使用成员函数来实现运算符重载
//猪肉 + 猪肉
//Money Pork::operator+(const Pork& pork) {
//	int money = (this->weight + pork.weight) * PORK_MONEY;
//	return Money(money);
//}

//猪肉 + 牛肉
//Money Pork::operator+(const Beef& beef) {
//	int money = this->weight * PORK_MONEY + beef.getWeight() * BEEF_MONEY;
//	return Money(money);
//}

//使用全局友元函数来实现运算符重载
//猪肉 + 猪肉
Money operator+(const Pork& pork1, const Pork& pork2) {
	int money = (pork1.weight + pork2.weight) * PORK_MONEY;
	return Money(money);
}

//猪肉 +　牛肉
Money operator+(const Pork& pork, const Beef& beef) {
	int money = pork.weight * PORK_MONEY + beef.getWeight() * BEEF_MONEY;
	return Money(money);
}
