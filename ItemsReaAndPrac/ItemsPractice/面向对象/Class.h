#pragma once
#include <string>

using namespace std;

class Class {					        //class: ��
public:							        //���е�
	Class();					        //�ֶ������Ĭ�Ϲ��캯��
	Class(string name, int age);        //�Զ���Ĵ������Ĺ��캯��
	Class(const Class &copy);		    //�������캯��
	Class& operator=(const Class &copy);//��ֵ���캯��
	~Class();                           //��������: �������������в���

	void eat();					        //�Զ���
	void play();				        //��
	void sleep();				        //˯��
	void work();			            //����
	void description() const;           //���� const�޶����������ݵ�ֵ���ܸı�
	string callName() const;
	int callAge() const; 
	int callWage() const;
	void modifyP(char *py);
	static int callClassNum();         //��̬��Ա����

private:						       //˽�е�
	string name;				       //����
	int age;					       //����
	int wage;					       //����
	char *p;
	static int ClassNum;               //��������, ��̬���ݳ�Ա����
};