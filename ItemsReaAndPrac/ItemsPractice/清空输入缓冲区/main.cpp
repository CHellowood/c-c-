#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	while(true) {
		int i=0;
		cout << "----------" << endl;
		while(!(cin >> i)) {
			cin.clear();//清除读取出错的标志
			cin.sync(); //清空输入缓冲区
			//cin.ignore('\n');//读取指定个数的字符(默认1个) 或 读取字符直到读到指定字符(默认EOF)

			cout << "输入出错!" << endl << "----------" << endl;
		}

		cout << i << endl;
	}
	system("pause");
	return 0;
	
}