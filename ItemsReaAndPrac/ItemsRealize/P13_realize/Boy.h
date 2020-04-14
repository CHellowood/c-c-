#pragma once

#include <iostream> 
#include "Object.h"

/*���߱��������������, Ȼ����cpp�ļ������������ͷ�ļ�*/
class Girl;

/*н�ʱ���*/
#define WAGE_SCALE 0.1
/*��ֵ����*/
#define YANZHI_SCALE 0.1 

class Boy : public Object
{
public:
	Boy();
	Boy(string name, int age, int yanzhi, int wage);

	//��ȡ�Ա�
	string getGender() const;
	
	//��ȡ��ֵ
	int getYanzhi() const;
	
	//��ȡн��
	int getWage() const;

	//�ж�girl�Ƿ���ϸ�boy��Ҫ��
	bool satisfied(const Girl& girl) const;
	
	//�û�����
	string description() const;

	//�������û���Ϣ
	static void inputBoys(vector<Boy> &boys);  

	//���뵥���û���Ϣ
	static void inputBoy(Boy &boy);

	bool operator>(const Boy& boy) const;
	friend ostream& operator<<(ostream& os, const Boy& boy);

private:
	string gender;   //�Ա�
	int yanzhi;      //��ֵ
	int wage;        //����
};

ostream& operator<<(ostream& os, const Boy& boy);