#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream offile;/*只能写入文件*/

	/*ios::out   以写的方式打开文件
	 *ios::trunc 覆盖存在的文件*/
	offile.open("test.txt", ios::out | ios::trunc);

	while (true) {
		cout << "姓名[ctrl+z结束]: ";
		cin >> name;

		if (cin.eof()) break;

		/*写入姓名*/
		offile << name << "\t";

		cout << "年龄: ";
		cin >> age;

		/*写入年龄*/
		offile << age << "\n";
	}

	/*关闭文件*/
	offile.close();
	system("pause");
	return 0;
}
