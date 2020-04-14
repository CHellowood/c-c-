#pragma once
#include "Object.h"

/*���߱��������������, Ȼ����cpp�ļ������������ͷ�ļ�*/
class Boy;

/*н�ʱ���*/
#define WAGE_SCALE 0.1
/*��ֵ����*/
#define YANZHI_SCALE 0.1 

class Girl : public Object
{
public:
	Girl();
	Girl(string name, int age, int yanzhi, int wage);

	//��ȡ�Ա�
	string getGender() const;

	//��ȡ��ֵ
	int getYanzhi() const;

	//��ȡн��
	int getWage() const;

	//�ж�boy�Ƿ���ϸ�girl��Ҫ��
	bool satisfied(Boy& boy) const;

	//�û�����
	string description() const;

	//�������û���Ϣ
	static void inputGirls(vector<Girl>& girls);

	//���뵥���û���Ϣ
	static void inputGirl(Girl& girl);

private:
	string gender;   //�Ա�
	int yanzhi;      //��ֵ
	int wage;        //����
};

