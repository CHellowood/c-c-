#include <iostream>
#include "TimeoutList.h"

using namespace std;

//初始化顺序表
bool initList(CONTIOUT& list) {
	list.connection = new CONNECTION[LIST_MAX];
	if (!list.connection) return false;

	list.lenght = 0;
	list.size = LIST_MAX;

	return true;
}

//添加元素
bool addConnection(CONTIOUT& list, CONNECTION n) {
	if (list.lenght == list.size) return false;

	list.connection[list.lenght] = n;
	list.lenght++;

	return true;
}

//插入元素
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

//删除元素
bool deleteConnection(CONTIOUT& list, int i) {
	if (i < 0 || i >= list.lenght) return false;

	for (int j = i; j < list.lenght; j++) {
		list.connection[j] = list.connection[j + 1];
	}
	list.lenght--;

	return true;
}

//销毁顺序表
void destroyList(CONTIOUT& list) {
	if (list.connection) delete[] list.connection;
	list.lenght = 0;
	list.size = 0;
}

void printList(CONTIOUT& list) {
	cout << "当前已保存" << list.lenght << "个元素" << endl;
	for (int i = 0; i < list.lenght; i++) {
		cout << "fd = " << list.connection[i].fd << ": " << list.connection[i].connectionTime << endl;
	}
	cout << endl;
}