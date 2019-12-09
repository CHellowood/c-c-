#include <iostream>
#include <Windows.h>
#include "LinkQueue.h"

using namespace std;

int main(void) {
	QUEUE* queue = new QUEUE;
	if (!queue) {
		cout << "queue内存申请失败!" << endl;
		system("pause");
		exit(-1);
	}

	cout << endl << "<<----------初始化单链表队列---------->>" << endl;
	if (!initQueue(queue)) {
		cout << "单链表队列初始化失败!" << endl;
		delete queue;
		system("pause");
		exit(-1);
	}
	cout << "单链表队列初始化成功!" << endl;

	cout << endl << "<<----------单链表队列入队---------->>" << endl;
	int i = 0, n = 0;

	cout << "要入队的元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << endl << "第" << j + 1 << "个:";
		cin >> n;

		if (!addNode(queue, &n)) {
			cout << "入队失败!" << endl;
			continue;
		}
		cout << "入队成功!" << endl;
		printQueue(queue);
	}
	cout << endl << "<<----------单链表队列出队---------->>" << endl;

	cout << "要出队的元素个数:";
	cin >> i;

	if (i > queue->length) {
		cout << endl << i << "已超出当前已入队元素个数 " << queue->length << endl;
		i = queue->length;
		cout << "已将 " << i << "当前已入队元素个数 " << queue->length << endl;
	}

	for (int j = 0; j < i; j++) {
		DataType num = 0;
		if (!deleteNode(queue, &num)) {
			cout << "出队失败!" << endl;
			continue;
		}
		cout << endl << "出队成功,出队的是:" << num << endl;
		printQueue(queue);
	}

	cout << endl << "<<----------清空队列---------->>" << endl;

	clearQueue(queue);

	system("pause");
	return 0;
}
