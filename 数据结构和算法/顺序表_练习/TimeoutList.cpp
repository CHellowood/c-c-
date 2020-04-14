#include <iostream>
#include "TimeoutList.h"

using namespace std;

//��ʼ��˳���
bool initList(CONTIOUT& list) {
	list.connection = new CONNECTION[LIST_MAX];
	if (!list.connection) return false;

	list.lenght = 0;
	list.size = LIST_MAX;

	return true;
}

//���Ԫ��
bool addConnection(CONTIOUT& list, CONNECTION n) {
	if (list.lenght == list.size) return false;

	list.connection[list.lenght] = n;
	list.lenght++;

	return true;
}

//����Ԫ��
bool insertConnection(CONTIOUT& list, int i, CONNECTION n) {
	if (list.lenght == list.size)  return false;
	if (i < 0 || i >= list.lenght) return false;

	for (int j = list.lenght; j < i; j--) {
		list.connection[j] = list.connection[j - 1];
	}
	list.connection[i] = n;
	list.lenght++;

	return true;
}

//ɾ��Ԫ��
bool deleteConnection(CONTIOUT& list, int i) {
	if (i < 0 || i >= list.lenght) return false;

	for (int j = i; j < list.lenght; j++) {
		list.connection[j] = list.connection[j + 1];
	}
	list.lenght--;

	return true;
}

//����˳���
void destroyList(CONTIOUT& list) {
	if (list.connection) delete[] list.connection;
	list.lenght = 0;
	list.size = 0;
}

void printList(CONTIOUT& list) {
	cout << "��ǰ�ѱ���" << list.lenght << "��Ԫ��" << endl;
	for (int i = 0; i < list.lenght; i++) {
		cout << "fd = " << list.connection[i].fd << ": " << list.connection[i].connectionTime << endl;
	}
	cout << endl;
}