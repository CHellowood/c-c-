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

//ʹ�ó�Ա������ʵ�����������
//ţ�� +��ţ��
//Money Beef::operator+(const Beef& beef)
//{
//	int money = (this->weight + beef.weight) * BEEF_MONEY;
//	return Money(money);
//}

//ţ�� + ����
//Money Beef::operator+(const Pork& pork)
//{
//	int money = this->weight * BEEF_MONEY + pork.getWeight() * PORK_MONEY;
//	return Money(money);
//}

//ʹ��ȫ����Ԫ������ʵ�����������
//ţ�� + ţ��
Money operator+(const Beef& beef1, const Beef& beef2) {
	int money = (beef1.weight + beef2.weight) * BEEF_MONEY;
	return Money(money);
}

//ţ�� +������
Money operator+(const Beef& beef, const Pork& pork) {
	int money = beef.weight * BEEF_MONEY + pork.getWeight() * PORK_MONEY;
	return Money(money);
}
