#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream outfile;/*ֻ��д�ļ�*/

	/*Ĭ�ϻḲ��(�൱�ڰ��ļ����)���ڵ��ļ�*/
	outfile.open("test.txt");

	while (true) {
		cout << "����[Ctrl+z�˳�]:";
		cin >> name;

		if (cin.eof()) break;

		cout << "����:";
		cin >> age;

		stringstream str;
		str << "����:" << name << "\t\t����:" << age << "\n";

		outfile << str.str();
	}

	outfile.close();
	system("pause");
	return 0;
}
