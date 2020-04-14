#include <iostream>
#include <Windows.h>
#include "Computer.h"

using namespace std;

//ȫ�ֺ�����Ϊ��Ԫ����
//void upgrade(Computer *computer) {
//	computer->cpu = "i7";
//}

int main(void) {
	//�������
	Computer computer;
	
	//�����������
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