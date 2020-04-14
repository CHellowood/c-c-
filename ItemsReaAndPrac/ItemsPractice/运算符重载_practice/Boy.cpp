#include "Boy.h"
#include <sstream>
#include <iomanip>

unsigned Boy::LAST_ID = 0;

Boy::Boy(const char* name, int age, int salary, int darkHorse)
{
	if (!name) {
		name = "δ����";
	}

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);//����

	this->age       = age;
	this->salary    = salary;
	this->darkHorse = darkHorse;
	this->id        = ++LAST_ID;
}

Boy::Boy(int salary)
{
    const char* defaultName = "δ����";
	this->name = new char[strlen(defaultName) + 1];
	strcpy_s(this->name, strlen(defaultName) + 1, defaultName);//����

	this->age = 0;
	this->salary = salary;
	this->darkHorse = 0;
	this->id = ++LAST_ID;
}

Boy::~Boy()
{
	if (name) delete[] name;
}

//��ֵ���������(�������캯��)
Boy& Boy::operator=(const Boy& boy)
{
	if (name) delete[] name;

	this->name = new char[strlen(boy.name) + 1];
	strcpy_s(this->name, strlen(boy.name) + 1, boy.name);

	this->age       = boy.age;
	this->salary    = boy.salary;
	this->darkHorse = boy.darkHorse;

	return *this;
}

//��ϵ���������
bool Boy::operator>(const Boy& boy) const
{
	if (this->power() > boy.power()) {
		return true;
	}
	return false;
}

//��ϵ���������
bool Boy::operator<(const Boy& boy) const
{
	if (this->power() < boy.power()) {
		return true;
	}
	return false;
}

//��ϵ���������
bool Boy::operator==(const Boy& boy) const
{
	if (this->power() == boy.power()) {
		return true;
	}
	return false;
}

//�±����������
int Boy::operator[](std::string index) const
{
	//if (index == NAME_KEY) {
	//	return (int)name;//�������
	//}
	//else 
	if (index == AGE_KEY) {
		return age;
	}
	else if (index == SALARY_KEY) {
		return salary;
	}
	else if (index == DARK_HORSE_KEY) {
		return darkHorse;
	}
	else {
		return -1;
	}
}

//�±����������
int Boy::operator[](int index) const
{
	switch (index) {
	  //case NAME:       return (int)name;//�������
	  case AGE:        return age;
	  case SALARY:     return salary;
	  case DARK_HORSE: return darkHorse;
	  default:         return -1;
	}
}

////������������
//std::ostream& Boy::operator<<(const std::ostream& os)
//{
//	os << "���: " << std::setw(ID_OUT_WIDTH) << ALIGN << id
//		<< "\t����: " << std::setw(NAME_OUT_WIDTH) << ALIGN << name
//		<< "\t����: " << std::setw(AGE_OUT_WIDTH) << ALIGN << age
//		<< "\tн��: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << salary
//		<< "\tǱ��ֵ: " << std::setw(DARK_HORSE_OUT_WIDTH) << ALIGN << darkHorse;
//	return os;
//}

////�������������
//std::istream& Boy::operator>>(std::istream& is)
//{
//	std::string name2;
//	is >> name2 >> age >> salary >> darkHorse;
//
//	if (name) delete[] name;
//
//	name = new char[strlen(name2.c_str()) + 1];
//	strcpy_s(name, strlen(name2.c_str()) + 1, name2.c_str());
//
//	return is;
//}

//�������������
Boy::operator int() const
{
	return power();
}

//�������������
Boy::operator char* () const
{
	return name;
}

//����
std::string Boy::description() const
{
	std::stringstream ret;
	ret << "���: " << std::setw(ID_OUT_WIDTH) << ALIGN << id
		<< "\t����: " << std::setw(NAME_OUT_WIDTH) << ALIGN << name
		<< "\t����: " << std::setw(AGE_OUT_WIDTH) << ALIGN << age
		<< "\tн��: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << salary
		<< "\tǱ��ֵ: " << std::setw(DARK_HORSE_OUT_WIDTH) << ALIGN << darkHorse;

	return ret.str();
}

//�ۺ�����ֵ
int Boy::power() const
{
	//���ñȽϹ���: н�� * Ǳ��ֵ + (100 - ����) * 1000
	int ret = salary * darkHorse + (100 - age) * 1000;
	return ret;
}

//ʹ��ȫ����Ԫ������ʵ��������������
std::ostream& operator<<(std::ostream& os, const Boy& boy) 
{
	os << "���: " << std::setw(ID_OUT_WIDTH) << ALIGN << boy.id
	   << "\t����: " << std::setw(NAME_OUT_WIDTH) << ALIGN << boy.name
   	   << "\t����: " << std::setw(AGE_OUT_WIDTH) << ALIGN << boy.age
 	   << "\tн��: " << std::setw(SALARY_OUT_WIDTH) << ALIGN << boy.salary
	   << "\tǱ��ֵ: " << std::setw(DARK_HORSE_OUT_WIDTH) << ALIGN << boy.darkHorse;
	return os;
}

//ʹ��ȫ����Ԫ������ʵ���������������
std::istream& operator>>(std::istream& is, Boy& boy)
{
	std::string name2;
	is >> name2 >> boy.age >> boy.salary >> boy.darkHorse;
	
	if (boy.name) delete[] boy.name;
	
	boy.name = new char[strlen(name2.c_str()) + 1];
	strcpy_s(boy.name, strlen(name2.c_str()) + 1, name2.c_str());

	return is;
}
