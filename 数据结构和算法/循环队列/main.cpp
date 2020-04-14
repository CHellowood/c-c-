#include <iostream>
#include <Windows.h>
#include "Queue.h"

using namespace std;

int main(void) {
	QUEUE* queue = NULL;

	queue = new QUEUE;
	if (!queue) {
		cout << "queue内存申请失败!" << endl;
		system("pause");
		exit(-1);
	}

	cout << endl << "<<----------初始化队列---------->>" << endl;
	
	if (!initQueue(queue)) {
		cout << "队列初始化失败!" << endl;
		delete queue;
		system("pause");
		exit(-1);
	}
	cout << "队列初始化成功!" << endl;

	cout << endl << "<<----------元素入队---------->>" << endl;
	int i = 0, n = 0;

	cout << "要入队的元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << endl << "第" << j + 1 << "个:";
		cin >> n;

		addData(queue, n);
		printQueue(queue);
	}

	cout << endl << "<<----------元素出队---------->>" << endl;
	cout << queue->head << "    " << queue->tail << endl;

	for (int j = 0; j < 4;j++) {
		DataType num = 0;
		deleteData(queue, num);
		cout << endl << "出队的元素是: " << num << endl;
		printQueue(queue);
	}

	cout << endl << "<<----------元素入队---------->>" << endl;

	cout << "要入队的元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << endl << "第" << j + 1 << "个:";
		cin >> n;

		addData(queue, n);
		printQueue(queue);
	}

	cout << endl << "<<----------销毁队列---------->>" << endl;
	destroyQueue(queue);


	system("pause");
	return 0;
}
