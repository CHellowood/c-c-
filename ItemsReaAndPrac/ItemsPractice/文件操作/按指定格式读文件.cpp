#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>

using namespace std;

int main(void) {
	char name[32];
	int age;
	ifstream infile;

	infile.open("test.txt");

	if (!infile.is_open()) {
		cout << "�ļ���ʧ��!\n";
		system("pause");
		exit(-1);
	}

	while (true) {
		string str;

		/*���ļ����һ������*/
		getline(infile, str);

		/*�Ƿ�����ļ�������*/
		if (infile.eof()) {
			break;
		}

		/*���ַ������ȡ����*/
		sscanf_s(str.c_str(), "����:%s\t\t����:%d", name, sizeof(name), &age);

		cout << name << "\t\t" << age << "\n";
	}

	infile.close();
	system("pause");
	return 0;
}