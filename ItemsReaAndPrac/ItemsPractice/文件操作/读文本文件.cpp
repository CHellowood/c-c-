#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ifstream iffile;/*只能读取文件*/

	/*ios::in   以读的方式打开文件*/
	iffile.open("test.txt", ios::in);
	if (!iffile.is_open()) {
		cout << "文件打开失败!\n";
		system("pause");
		exit(-1);
	}

	while (true) {
		/*读取姓名*/
		iffile >> name;
		if (iffile.eof()) break;

		cout << name << "\t";

		/*读取年龄*/
		iffile >> age;
		cout << age << "\n";
	}

	/*关闭文件*/
	iffile.close();
	system("pause");
	return 0;
}