#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ifstream iffile;/*ֻ�ܶ�ȡ�ļ�*/

	/*ios::in     �Զ��ķ�ʽ���ļ�
	 *ios::binary �Զ�����ģʽ���ļ�*/
	iffile.open("test.dat", ios::in | ios::binary);
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

		char c;
		/*��ȡ�������ļ�ʱ�����Զ������Ʊ��ո񡢵ȷ���
		 *������Ҫ����Щ���Ŷ�ȡ����*/
		iffile.read(&c, sizeof(c));

		/*��ȡ����*/
		iffile.read((char*)&age, sizeof(age));
		cout << age << "\n";
	}

	/*�ر��ļ�*/
	iffile.close();
	system("pause");
	return 0;
}