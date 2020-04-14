#include <iostream>
#include <Windows.h>
#include "DoubleLink.h"
#include <typeinfo>


using namespace std;

int main(void) {
	DLink* link = NULL;
	int i=0;

	cout << endl << "<<----------初始化链表---------->>" << endl;
	
	link = new DLink;
	
	if (!link) {
		cout << "初始化链表失败!" << endl;
		exit(-1);
	}

	link->data = -1;
	initDLink(link->pointer);//初始化指针域

	cout << "初始化链表成功!" << endl;

	cout << endl << "<<----------在链表头部添加结点---------->>" << endl;

	cout << "要添加的结点个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		DLink* newNode = new DLink;
		if (!newNode) {
			cout << "第" << j + 1 << "个结点申请内存失败!" << endl;
			continue;
		}

		cout << "第" << j + 1 << "个结点的数据:";
		cin >> newNode->data;

		addNode_Head(link->pointer, newNode->pointer);
	}

	printDLink(link->pointer);

	cout << endl << "<<----------在链表尾部添加结点---------->>" << endl;

	cout << "要添加的结点个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		DLink* newNode = new DLink;
		if (!newNode) {
			cout << "第" << j + 1 << "个结点申请内存失败!" << endl;
			continue;
		}

		cout << "第" << j + 1 << "个结点的数据:";
		cin >> newNode->data;

		addNode_Tail(link->pointer, newNode->pointer);
	}

	printDLink(link->pointer);

	cout << endl << "<<----------在链表中插入结点---------->>" << endl;

	cout << "要插入的结点个数:";
	cin >> i;

	for (int j = 0, n = 0; j < i; j++) {
		DLink* newNode = new DLink;
		if (!newNode) {
			cout << "第" << j + 1 << "个结点申请内存失败!" << endl;
			continue;
		}

		cout << "第" << j + 1 << "个结点的位置和数据:";
		cin >> n >> newNode->data;

		if (!insertNode(link->pointer, n, newNode->pointer)) {
			cout << "插入失败!" << endl;
			delete newNode;
			continue;
		}
		cout << "插入成功!" << endl;
		printDLink(link->pointer);
	}

	cout << endl << "<<----------在链表中删除结点---------->>" << endl;

	cout << "要删除的结点个数:";
	cin >> i;

	for (int j = 0, n = 0; j < i; j++) {
		cout << "第" << j + 1 << "个结点的位置:";
		cin >> n;

		if (!deleteNode(link->pointer, n)) {
			cout << "删除失败!" << endl;
			continue;
		}

		cout << "删除成功!" << endl;
		printDLink(link->pointer);
	}

	cout << endl << "<<----------销毁链表---------->>" << endl;

	destroyDLink(link->pointer);

	system("pause");
	return 0;
}
