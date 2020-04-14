#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <string>

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream outfile;/*只能写文件*/

	/*默认会覆盖(相当于把文件清空)存在的文件*/
	outfile.open("test.txt");

	while (true) {
		cout << "姓名[Ctrl+z退出]:";
		cin >> name;

		if (cin.eof()) break;

		cout << "年龄:";
		cin >> age;

		stringstream str;
		str << "姓名:" << name << "\t\t年龄:" << age << "\n";

		outfile << str.str();
	}

	outfile.close();
	system("pause");
	return 0;
}
