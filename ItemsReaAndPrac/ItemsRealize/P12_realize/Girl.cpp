#include "Girl.h"
#include "Boy.h"
#include <sstream>
#include <iomanip>
#include <iostream>

Girl::Girl() : Object() {
	this->gender = "Ů";
	this->yanzhi = 0;
	this->wage = 0;
}

Girl::Girl(string name, int age, int yanzhi, int wage)
	: Object(name, age) {
	this->gender = "Ů";
	this->yanzhi = yanzhi;
	this->wage = wage;
}

//��ȡ�Ա�
string Girl::getGender() const {
	return gender;
}

//��ȡ��ֵ
int Girl::getYanzhi() const {
	return yanzhi;
}

//��ȡн��
int Girl::getWage() const {
	return wage;
}

//�ж�boy�Ƿ���ϸ�girl��Ҫ��
bool Girl::satisfied(Boy &boy) const {
	if (boy.getYanzhi() >= yanzhi - yanzhi * YANZHI_SCALE &&
		boy.getWage() >= wage + wage * WAGE_SCALE) {
		return true;
	}
	return false;
}

//�û�����
string Girl::description() const {
	stringstream ret;
	ret << "����:" 
		<< setw(9) << setiosflags(ios::left)
		<< name
		<< "\t\t�Ա�:Ů"
		<< "\t\t����:" << age
		<< "\t\t��ֵ:"
		<< setw(3) << setiosflags(ios::left) //����һ�����ݵĿ����Ϊ3�����������
		<< yanzhi
		<< "\t\tн��:" << wage;

	return ret.str();
}

//�������û���Ϣ
void Girl::inputGirls(vector<Girl>& girls) {
	int i = 1;
	while (true) {
		string name;
		int age;
		int yanzhi;
		int wage;

		cout << "\t<<��" << i++ << "λgirl>>\n";
		cout << "����[���� end ����]:";
		cin >> name;

		if (name == "end") break;

		cout << "����:";
		cin >> age;

		cout << "��ֵ:";
		cin >> yanzhi;

		cout << "����:";
		cin >> wage;

		girls.push_back(Girl(name, age, yanzhi, wage));
	}
}

//���뵥���û���Ϣ
void Girl::inputGirl(Girl& girl) {
	string name;
	int age;
	int yanzhi;
	int wage;

	cout << "\n����girl����Ϣ>>\n";
	cout << "����:";
	cin >> name;

	cout << "����:";
	cin >> age;

	cout << "��ֵ:";
	cin >> yanzhi;

	cout << "����:";
	cin >> wage;

	girl = Girl(name, age, yanzhi, wage);
}