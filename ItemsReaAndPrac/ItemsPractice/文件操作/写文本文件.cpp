#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream offile;/*ֻ��д���ļ�*/

	/*ios::out   ��д�ķ�ʽ���ļ�
	 *ios::trunc ���Ǵ��ڵ��ļ�*/
	offile.open("test.txt", ios::out | ios::trunc);

	while (true) {
		cout << "����[ctrl+z����]: ";
		cin >> name;

		if (cin.eof()) break;

		/*д������*/
		offile << name << "\t";

		cout << "����: ";
		cin >> age;

		/*д������*/
		offile << age << "\n";
	}

	/*�ر��ļ�*/
	offile.close();
	system("pause");
	return 0;
}
