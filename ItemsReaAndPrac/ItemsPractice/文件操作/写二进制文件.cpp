#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	string name;
	int age;
	ofstream offile;/*只能写入文件*/

	/*ios::out    以写的方式打开文件
	 *ios::trunc  覆盖存在的文件
	 *ios::binary 以二进制模式打开文件*/
	offile.open("test.dat", ios::out | ios::trunc | ios::binary);

	while (true) {
		cout << "姓名[ctrl+z结束]: ";
		cin >> name;

		if (cin.eof()) break;

		/*写入姓名*/
		offile << name << "\t";

		cout << "年龄: ";
		cin >> age;

		/*写入年龄*/
		/*默认情况下会自动把整数转成字符再写入文件*/
		//offile << age << "\n";
		
		/*把该整型变量的所有字节(int为4个字节)全部写进去*/
		offile.write((char*)&age, sizeof(age));
	}

	/*关闭文件*/
	offile.close();
	system("pause");
	return 0;
}