//#pragma once

#ifndef _PORK_H_
#define _PORK_H_

//����һ������30��Ǯ
#define PORK_MONEY 30

class Money;//Ǯ
class Beef; //ţ��

class Pork  //����
{
public:
	Pork(int weight = 0);

	int getWeight() const;

	//// - * / % �⼸������������غ� + �Ĳ�� 
	////ʹ�ó�Ա������ʵ�����������
	////ʹ��ʱ��һ����������Ϊ����Ķ���, ����ᱨ�� 
	////���� + ����
	//Money operator+(const Pork& pork);

	////���� + ţ��
	//Money operator+(const Beef& beef);


	//ʹ��ȫ����Ԫ������ʵ�����������
	//ʹ��ʱֻ���ж�Ӧ�����غ�������
	//���� + ����
	friend Money operator+(const Pork& pork1, const Pork& pork2);

	//���� + ţ��
	friend Money operator+(const Pork& pork, const Beef& beef);

private:
	int weight;//���������
};

#endif 