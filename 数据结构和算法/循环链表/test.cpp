#include <iostream>
#include <Windows.h>
#include "CycleLink.h"

using namespace std;

int main(void) {
	LinkHead* link = NULL;
	int i = 0, n = 0;

	cout << endl << "<<----------初始化循环链表---------->>" << endl;

	if (!initCycleLink(link)) {
		cout << "循环链表初始化失败!" << endl;
		exit(1);
	}
	cout << "循环链表初始化成功!" << endl;

	cout << endl << "<<----------在链表头部添加结点---------->>" << endl;

	cout << "要添加的结点个数:";
	cin >> i;

	while (i > 0) {
		i--;

		cout << "结点数据:";
		cin >> n;

		if (!addNode_Head(link, n)) {
			cout << "添加失败!" << endl;
			continue;
		}
		cout << "添加成功!" << endl;
	}

	printCycleLink(link);

	cout << endl << "<<----------在链表尾部添加结点---------->>" << endl;

	cout << "要添加的结点个数:";
	cin >> i;

	while (i > 0) {
		i--;

		cout << "结点数据:";
		cin >> n;

		if (!addNode_Tail(link, n)) {
			cout << "添加失败!" << endl;
			continue;
		}
		cout << "添加成功!" << endl;
	}

	printCycleLink(link);

	cout << endl << "<<----------在链表中插入结点---------->>" << endl;
	int num = 0;

	cout << "要插入的结点个数:";
	cin >> num;

	while (num > 0) {
		num--;

		cout << "结点的位置和数据:";
		cin >> i >> n;

		if (!insertNode(link, i, n)) {
			cout << "插入失败!" << endl;
			continue;
		}
		cout << "插入成功!" << endl;
		printCycleLink(link);
	}

	cout << endl << "<<----------在链表中删除结点---------->>" << endl;

	cout << "要删除的结点个数:";
	cin >> n;

	while (num > 0) {
		n--;

		cout << "结点位置:";
		cin >> i;

		if (!deleteNode(link, i)) {
			cout << "删除失败!" << endl;
			continue;
		}
		cout << "删除成功!" << endl;
		printCycleLink(link);
	}

	cout << endl << "<<----------销毁链表---------->>" << endl;

	destroyCycleLink(link);

	system("pause");
	return 0;
}