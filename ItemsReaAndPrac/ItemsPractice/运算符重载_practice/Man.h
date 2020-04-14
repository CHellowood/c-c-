//#pragma once

#ifndef _MAN_H_
#define _MAN_H_

#include <iostream>

class Boy;

class Man
{
public:
	Man(const char* name, int age, int salary);
	Man(const Boy& boy);
	~Man();

	//ʹ��ȫ����Ԫ������ʵ��������������
	friend std::ostream& operator<<(std::ostream& os, const Man& man);

	////ʹ��ȫ����Ԫ������ʵ���������������
	//friend std::istream& operator>>(std::istream& is, Man& man);

private:
	char* name;
	int age;
	int salary;
};

std::ostream& operator<<(std::ostream& os, const Man& man);
//std::istream& operator>>(std::istream& is, Man& man);

#endif 