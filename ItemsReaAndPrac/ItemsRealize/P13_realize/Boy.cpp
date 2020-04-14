#include "Boy.h"
#include "Girl.h"
#include <sstream>
#include <iomanip>
#include <iostream>

Boy::Boy() : Object() {
	this->gender = "��";
	this->yanzhi = 0;
	this->wage = 0;
}

Boy::Boy(string name, int age, int yanzhi, int wage) 
	: Object(name, age) {
	this->gender = "��";
	this->yanzhi = yanzhi;
	this->wage   = wage;
}

//��ȡ�Ա�
string Boy::getGender() const {
	return gender;
}

//��ȡ��ֵ
int Boy::getYanzhi() const {
	return yanzhi;
}

//��ȡн��
int Boy::getWage() const {
	return wage;
}

//�ж�girl�Ƿ���ϸ�boy��Ҫ��
bool Boy::satisfied(const Girl &girl) const {
	int Yanzhi = yanzhi + yanzhi * YANZHI_SCALE;
	
	if (//girl.getWage() >= wage - wage * WAGE_SCALE && 
		girl.getYanzhi() >= (Yanzhi > 100 ? 100 : Yanzhi)) {
		return true;
	}
	return false;
}

//�û�����
string Boy::description() const {
	stringstream ret;
	ret << "����:" 
		<< setw(9) << setiosflags(ios::left) 
		<< name
		<< "\t\t�Ա�:��"
		<< "\t\t����:" << age
		<< "\t\t��ֵ:"
		<< setw(3) << setiosflags(ios::left) //����һ�����ݵĿ����Ϊ3�����������
		<< yanzhi
		<< "\t\tн��:" << wage;

	return ret.str();
}

//�������û���Ϣ
void Boy::inputBoys(vector<Boy>& boys) {
	int i = 1;
	while (true) {
		string name;
		int age;
		int yanzhi;
		int wage;

		cout << "\t<<��" << i++ << "λboy>>\n";
		cout << "����[���� end ����]:";
		cin >> name;

		if (name == "end") break;

		cout << "����:";
		cin >> age;

		cout << "��ֵ:";
		cin >> yanzhi;

		cout << "����:";
		cin >> wage;

		boys.push_back(Boy(name, age, yanzhi, wage));
	}
}

//���뵥���û���Ϣ
void Boy::inputBoy(Boy &boy) {
	string name;
	int age;
	int yanzhi;
	int wage;

	cout << "\n<<����boy����Ϣ>>\n";
	cout << "����:";
	cin >> name;

	cout << "����:";
	cin >> age;

	cout << "��ֵ:";
	cin >> yanzhi;

	cout << "����:";
	cin >> wage;

	boy = Boy(name, age, yanzhi, wage);
}

bool Boy::operator>(const Boy& boy) const
{
	return wage > boy.wage;
}

ostream& operator<<(ostream& os, const Boy& boy)
{
	os << "����:" << setw(9) << setiosflags(ios::left) << boy.name
		<< "\t\t�Ա�:��"
		<< "\t\t����:" << boy.age
		/*����һ�����ݵĿ����Ϊ3�����������*/
		<< "\t\t��ֵ:" << setw(3) << setiosflags(ios::left) << boy.yanzhi
		<< "\t\tн��:" << boy.wage;

	return os;
}
