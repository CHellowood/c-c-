#include "ODU.h"
#include <iostream>

ODU::ODU()
{
	TxFre = 34400;
	RxFre = 31100;
	TxPower = 20;
	RxL = 0;
	type = ODU_TYPE::ODU_TYPE_331;
}

int ODU::getTxFre()
{
	return TxFre;
}

bool ODU::setTxFre(int fre)
{
	TxFre = fre;
	std::cout << type_str() << "����Ƶ��������Ϊ" << TxFre << "Hz\n";
	return true;
}

int ODU::getRxFre()
{
	return RxFre;
}

bool ODU::setRxFre(int fre)
{
	RxFre = fre;
	std::cout << type_str() << "����Ƶ��������Ϊ" << RxFre << "Hz\n";
	return true;
}

float ODU::getTxPower()
{
	return TxPower;
}

bool ODU::setTxPower(float power)
{
	TxPower = power;
	std::cout << type_str() << "���书��������Ϊ" << TxPower << "dBm\n";
	return true;
}

float ODU::getRxL()
{
	return RxL;
}

bool ODU::heartBeat()
{
	std::cout << type_str() << "�ֶ�����ģ���ȡ��������" 
		<< ODU_TYPE_ODU331 << "��";
	
	std::string str;
	std::cin >> str;

	if (str == ODU_TYPE_ODU331) {
		return true;
	}
	return false;
}

std::string ODU::type_str()
{
	std::string ret;
	switch (type) {
	case ODU_TYPE::ODU_TYPE_331:
		ret = "ODU331";
		break;
	case ODU_TYPE::ODU_TYPE_335:
		ret = "ODU335";
		break;
	default:
		ret = "unknown";
	}
	return ret;
}

ODU_TYPE ODU::getODUType()
{
	return type;
}
