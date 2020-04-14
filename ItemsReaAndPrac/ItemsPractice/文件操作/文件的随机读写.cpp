#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*获取文件大小:
 *输入:   fileName: 文件名
 *返回值: 文件大小, -1表示文件不存在*/
long long getFileSize(const char* fileName) {
	ifstream infile;

	infile.open(fileName);
	if (!infile.is_open()) {
		return -1;
	}

	/*跳到文件的指定位置(字节)
	 *以读取方式打开文件时使用seekg
	 *以输入方式打开文件时使用seekp
	 *第一个参数: 偏移量
	 *第二个参数: 文件的位置
	 *beg 文件起始位置
	 *cur 文件当前位置
	 *end 文件结束位置*/
	infile.seekg(0, infile.end);

	/*获取起始位置到当前位置距离(字节)
	 *以读取方式打开文件时使用tellg
	 *以输入方式打开文件时使用tellp*/
	long long ret = infile.tellg();
	infile.close();

	return ret;
}

int main(void) {
	cout << getFileSize("文件的随机读写.cpp") << "\n";

	ofstream outfile;
	outfile.open("test.txt");
	if (!outfile.is_open()) {
		system("pause");
		exit(-1);
	}

	outfile << "1234567890";

	outfile.seekp(-5, outfile.end);

	outfile << "???";

	outfile.close();
	system("pause");
	return 0;
}
