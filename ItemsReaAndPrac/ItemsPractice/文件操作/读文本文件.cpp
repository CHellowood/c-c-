#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ifstream iffile;/*ֻ�ܶ�ȡ�ļ�*/

	/*ios::in   �Զ��ķ�ʽ���ļ�*/
	iffile.open("test.txt", ios::in);
	if (!iffile.is_open()) {
		cout << "�ļ���ʧ��!\n";
		system("pause");
		exit(-1);
	}

	while (true) {
		/*��ȡ����*/
		iffile >> name;
		if (iffile.eof()) break;

		cout << name << "\t";

		/*��ȡ����*/
		iffile >> age;
		cout << age << "\n";
	}

	/*�ر��ļ�*/
	iffile.close();
	system("pause");
	return 0;
}