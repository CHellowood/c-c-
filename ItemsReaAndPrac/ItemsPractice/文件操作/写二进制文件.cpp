#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream offile;/*ֻ��д���ļ�*/

	/*ios::out    ��д�ķ�ʽ���ļ�
	 *ios::trunc  ���Ǵ��ڵ��ļ�
	 *ios::binary �Զ�����ģʽ���ļ�*/
	offile.open("test.dat", ios::out | ios::trunc | ios::binary);

	while (true) {
		cout << "����[ctrl+z����]: ";
		cin >> name;

		if (cin.eof()) break;

		/*д������*/
		offile << name << "\t";

		cout << "����: ";
		cin >> age;

		/*д������*/
		/*Ĭ������»��Զ�������ת���ַ���д���ļ�*/
		//offile << age << "\n";
		
		/*�Ѹ����ͱ����������ֽ�(intΪ4���ֽ�)ȫ��д��ȥ*/
		offile.write((char*)&age, sizeof(age));
	}

	/*�ر��ļ�*/
	offile.close();
	system("pause");
	return 0;
}