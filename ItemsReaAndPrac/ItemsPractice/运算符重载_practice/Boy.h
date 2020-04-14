//#pragma once

#ifndef _BOY_H_
#define _BOY_H_

#include <string>
#include <iostream>

#define NULL 0

//#define NAME_KEY       "name"
#define AGE_KEY        "age"
#define SALARY_KEY     "salary"
#define DARK_HORSE_KEY "darkHorse"

//������
#define ID_OUT_WIDTH         10
#define NAME_OUT_WIDTH       10
#define AGE_OUT_WIDTH        3
#define SALARY_OUT_WIDTH     8
#define DARK_HORSE_OUT_WIDTH 3

//�����
#define LEFT std::left

//�Ҷ���
#define RIGHT std::right

//����
#define ALIGN LEFT

typedef enum {
//	NAME,
	AGE,
	SALARY,
	DARK_HORSE
}KEY;


class Boy
{
public:
	Boy(const char* name = NULL, int age = 0,
		int salary = 0, int darkHorse = 0);
	Boy(int salary);
	~Boy();

	//��ֵ���������(�������캯��)
	Boy& operator=(const Boy& boy);

	//��ϵ���������
	bool operator>(const Boy& boy) const;
	bool operator<(const Boy& boy) const;
	bool operator==(const Boy& boy) const;

	//�±����������
	int operator[](std::string index) const;
	int operator[](int index) const;

	////ʹ�ó�Ա������ʵ��������������
	////���Ƽ�ʹ�ó�Ա������ʵ��������������
	//std::ostream& operator<<(const std::ostream& os);

	////ʹ�ó�Ա������ʵ���������������
	////���Ƽ�ʹ�ó�Ա������ʵ���������������
	//std::istream& operator>>(std::istream& is);

	//ʹ��ȫ����Ԫ������ʵ��������������
	friend std::ostream& operator<<(std::ostream& os, const Boy& boy);

	//ʹ��ȫ����Ԫ������ʵ���������������
	friend std::istream& operator>>(std::istream& is, Boy& boy);

	//������ת��ͨ���ͣ�������������أ�
	operator int() const;
	operator char* () const;

	//����
	std::string description() const;

private:
	char* name;             //����
	int   age;              //����
	int salary;             //н��
	int darkHorse;          //����, Ǳ��ֵ
	unsigned id;            //���
	static unsigned LAST_ID;//���(����)�ı��

	int power() const;            //�ۺ�����ֵ
};

std::ostream& operator<<(std::ostream& os, const Boy& boy);
std::istream& operator>>(std::istream& is, Boy& boy);

#endif 