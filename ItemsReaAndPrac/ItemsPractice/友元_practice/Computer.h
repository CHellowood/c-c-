//#pragma once
#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <string>
#include "ComputerService.h"

class Computer
{
public:
	Computer();
	std::string description();

private:
	std::string cpu;

	//ȫ�ֺ�����Ϊ��Ԫ����
	//friend void upgrade(Computer *computer);

	//������ĳ�Ա������Ϊ��Ԫ����
	//friend void ComputerService::upgrade(Computer* computer);

	//��Ԫ��
	friend class ComputerService;
};




#endif 