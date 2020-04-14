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

//ʹ�ó�Ա������ʵ�����������
//���� + ����
//Money Pork::operator+(const Pork& pork) {
//	int money = (this->weight + pork.weight) * PORK_MONEY;
//	return Money(money);
//}

//���� + ţ��
//Money Pork::operator+(const Beef& beef) {
//	int money = this->weight * PORK_MONEY + beef.getWeight() * BEEF_MONEY;
//	return Money(money);
//}

//ʹ��ȫ����Ԫ������ʵ�����������
//���� + ����
Money operator+(const Pork& pork1, const Pork& pork2) {
	int money = (pork1.weight + pork2.weight) * PORK_MONEY;
	return Money(money);
}

//���� +��ţ��
Money operator+(const Pork& pork, const Beef& beef) {
	int money = pork.weight * PORK_MONEY + beef.getWeight() * BEEF_MONEY;
	return Money(money);
}
