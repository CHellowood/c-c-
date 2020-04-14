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
		cout << "文件打开失败!\n";
		system("pause");
		exit(-1);
	}

	while (true) {
		string str;

		/*从文件里读一行数据*/
		getline(infile, str);

		/*是否读到文件结束符*/
		if (infile.eof()) {
			break;
		}

		/*从字符串里读取数据*/
		sscanf_s(str.c_str(), "姓名:%s\t\t年龄:%d", name, sizeof(name), &age);

		cout << name << "\t\t" << age << "\n";
	}

	infile.close();
	system("pause");
	return 0;
}