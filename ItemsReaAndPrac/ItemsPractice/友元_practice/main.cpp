#include <iostream>
#include <Windows.h>
#include "Computer.h"

using namespace std;

//全局函数作为友元函数
//void upgrade(Computer *computer) {
//	computer->cpu = "i7";
//}

int main(void) {
	//计算机类
	Computer computer;
	
	//计算机服务类
	ComputerService service;

	cout << "CPU: " << computer.description() << endl;

	//upgrade(&computer);
	service.upgrade(&computer);
	service.clear(&computer);
	service.kill(&computer);

	cout << "CPU: " << computer.description() << endl;

	system("pause");
	return 0;
}