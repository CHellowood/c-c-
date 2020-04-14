#include <iostream>
#include <Windows.h>
#include "LinkList.h"

using namespace std;

int main(void) {
	LinkHead* link = NULL;
	int i = 0, n = 0;

	cout << endl << "<<----------初始化链表----------<<" << endl;

	if (initNode(link)) {
		cout << "链表初始化成功!" << endl;
	}
	else {
		cout << "链表初始化失败!" << endl;
		system("pause");
		return 0;
	}

	cout << endl << "<<----------在链表头部添加元素----------<<" << endl;

	cout << "请输入要在链表头部添加的元素个数:";
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "在头部添加的第" << j+1 << "个元素的数据:";
		cin >> n;

		if (addNodeHead(link, n)) {
			cout << "在头部添加元素成功!" << endl;
		}
		else {
			cout << "在头部添加元素失败!" << endl;
		}

		printNode(link);
	}

	cout << endl << "<<----------在链表尾部添加元素----------<<" << endl;

	cout << "请输入要在链表尾部添加的元素个数:";
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "在尾部添加的第" << j + 1 << "个元素的数据:";
		cin >> n;

		if (addNodeTail(link, n)) {
			cout << "在尾部添加元素成功!" << endl;
		}
		else {
			cout << "在尾部添加元素失败!" << endl;
		}

		printNode(link);
	}
/*
	cout << endl << "<<----------在链表中插入元素----------<<" << endl;
	
	int num = 0;
	cout << "请输入要在链表中插入的元素个数:";
	cin >> num;
	for (int j = 0; j < num; j++) {
		cout << "要插入的第" << j+1 << "个元素的位置和数据:";
		cin >> i >> n;

		if (insertNode(link, i, n)) {
			cout << "第" << j + 1 << "个元素插入成功!" << endl;
		}
		else {
			cout << "第" << j + 1 << "个元素插入失败!" << endl;
		}

		printNode(link);
	}

	cout << endl << "<<----------根据结点位置在链表中查找结点----------<<" << endl;

	cout << "该结点在链表中的位置:";
	cin >> i;

	if (!searchNode(link, i)) {
		cout << "该结点不存在!" << endl;
	}
*/
	cout << endl << "<<----------根据结点数据在链表中查找结点----------<<" << endl;
	
	cout << "输入要查找的数据:";
	cin >> n;

	searchData(link, n);

	cout << endl << "<<----------在链表中删除结点----------<<" << endl;
	
	cout << "请输入要在链表中删除的元素个数:";
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "要删除的第" << j + 1 << "个结点的位置:";
		cin >> n;

		if (deleteNode(link, n)) {
			cout << "删除结点成功!" << endl;
		}
		else {
			cout << "删除结点失败!" << endl;
		}

		printNode(link);
	}

	cout << endl << "<<----------销毁链表----------<<" << endl;
	destroyLinkNode(link);

	system("pause");
	return 0;
}