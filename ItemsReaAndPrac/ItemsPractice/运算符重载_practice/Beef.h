//#pragma once

#ifndef _BEEF_H_
#define _BEEF_H_

//����һ��ţ��40��Ǯ
#define BEEF_MONEY 40

class Money;//Ǯ
class Pork; //����

class Beef  //ţ��
{
public:
	Beef(int weight = 0);

	int getWeight() const;

	//// - * / % �⼸������������غ� + �Ĳ�� 
	////ʹ�ó�Ա������ʵ�����������
	////ʹ��ʱ��һ����������Ϊ����Ķ���, ����ᱨ�� 
	////ţ�� + ţ��
	//Money operator+(const Beef& beef);

	////ţ�� + ����
	//Money operator+(const Pork& pork);


	//ʹ��ȫ����Ԫ������ʵ�����������
	//ʹ��ʱֻ���ж�Ӧ�����غ�������
	//ţ�� + ţ��
	friend Money operator+(const Beef& beef1, const Beef& beef2);

	//ţ�� + ����
	friend Money operator+(const Beef& beef, const Pork& pork);

private:
	int weight;
};

#endif 