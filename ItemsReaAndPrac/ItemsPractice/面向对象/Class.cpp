#include <iostream>
#include "Class.h"

int Class::ClassNum = 0; //��̬���ݳ�Ա����

Class::Class() {//�ֶ������Ĭ�Ϲ��캯��
	name = "hello world!";
	age = 18;
	wage = 4500;

	p = new char[24];
	strcpy(p, "China");

	ClassNum++;
}

Class::Class(string name, int age) {//�Զ���Ĵ������Ĺ��캯��
	this->name = name;
	this->age = age;
	
	p = new char[24];
	strcpy(p, "China");

	ClassNum++;
}

Class::Class(const Class &copy) {//�������캯��
	name = copy.name;
	age = copy.age;
	wage = copy.wage;

	p = new char[24];
	strcpy(p, copy.p);
}
Class& Class::operator=(const Class &copy) {// ��ֵ���캯��
	if(this == &copy) {
		return *this;
	}

	name = copy.name;
	age = copy.age;
	wage = copy.wage;

	strcpy(p, copy.p);
	
	return *this;
}

Class::~Class() {//��������
	delete[] p;
}
void Class::eat() {
	cout << "��������... " << endl;
}

void Class::play() {
	cout << "����Ϸ��..." << endl;
}

void Class::sleep() {
	cout << "˯����... " << endl;
}

void Class::work() {
	cout << "������... " << endl;
}

string Class::callName() const{
	return name;
}

int Class::callAge() const{
	return age;
}

int Class::callWage() const{
	return wage;
}

void Class::modifyP(char *py) {
	if(!py) {
		return;
	}
	
	strcpy(this->p, py);
}

void Class::description() const{
	cout << "����: " << callName() << " ����: " << callAge() << " ����: " << callWage() << " ��ַ: " << p << endl;
}

int Class::callClassNum() {//��̬��Ա����
	return ClassNum;
}