#include "ODU335.h"
#include <iostream>

ODU335::ODU335()
{
	TxFre = 32200;
	RxFre = 31000;
	TxPower = 28;
	RxL = 0;
	type = ODU_TYPE::ODU_TYPE_335;
}

bool ODU335::heartBeat()
{
	std::cout << type_str() << "�ֶ�����ģ���ȡ��������"
		<< ODU_TYPE_ODU335 << "��";

	std::string str;
	std::cin >> str;

	if (str == ODU_TYPE_ODU335) {
		return true;
	}
	return false;
}
