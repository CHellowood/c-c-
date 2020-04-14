#include "Man.h"
#include "Boy.h"
#include <string>
#include <iomanip>

Man::Man(const char* name, int age, int salary)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);

	this->age = age;
	this->salary = salary;
}

Man::Man(const Boy& boy)
{
	int len = strlen((char*)boy) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, (char*)boy);

	this->age = boy[AGE];
	this->salary = boy[SALARY];
}

Man::~Man()
{
	delete[] name;
}

//ʹ��ȫ����Ԫ������ʵ��������������
std::ostream& operator<<(std::ostream& os, const Man& man)
{
	os << "�����ˡ�����: " << std::setw(NAME_OUT_WIDTH) << ALIGN << man.name
	   << "\t����: " << std::setw(AGE_OUT_WIDTH) << ALIGN << man.age
	   << "\tн��: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << man.salary;
	return os;
}

////ʹ��ȫ����Ԫ������ʵ���������������
//std::istream& operator>>(std::istream& is, Man& man)
//{
//	// TODO: �ڴ˴����� return ���
//}
