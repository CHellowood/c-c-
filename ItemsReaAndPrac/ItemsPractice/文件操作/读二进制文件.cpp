#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ifstream iffile;/*只能读取文件*/

	/*ios::in     以读的方式打开文件
	 *ios::binary 以二进制模式打开文件*/
	iffile.open("test.dat", ios::in | ios::binary);
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

		char c;
		/*读取二进制文件时不会自动跳过制表、空格、等符号
		 *所以需要把这些符号读取出来*/
		iffile.read(&c, sizeof(c));

		/*读取年龄*/
		iffile.read((char*)&age, sizeof(age));
		cout << age << "\n";
	}

	/*关闭文件*/
	iffile.close();
	system("pause");
	return 0;
}