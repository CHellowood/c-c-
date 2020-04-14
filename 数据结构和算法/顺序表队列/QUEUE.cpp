#include <iostream>
#include "QUEUE.h"

using namespace std;

bool initQueue(QUEUE* queue) {
	if (!queue) {
		cout << "无法初始化,该队列不存在!" << endl;
		return false;
	}

	queue->head = queue->tail = 0;

	return true;
}

bool addData(QUEUE* queue, int& n) {
	if (!queue) {
		cout << "无法入队,该队列不存在!" << endl;
		return false;
	}
	else if (queue->tail == DATASIZE) {
		cout << n << " 无法入队, 队列已满!" << endl;
		return false;
	}

	queue->data[queue->tail] = n;
	queue->tail++;

	return true;
}

bool deleteData(QUEUE* queue, DataType& ret) {
	if (!queue) {
		cout << "无法出队,该队列不存在!" << endl;
		return false;
	}
	else if (queue->head == queue->tail) {
		cout << "无法出队,该队列为空!" << endl;
		return false;
	}

	ret = queue->data[queue->head];
	for (int i = queue->head + 1; i < queue->tail; i++) {
		queue->data[i - 1] = queue->data[i];
	}
	queue->tail--;

	return true;
}

bool destroyQueue(QUEUE* queue) {
	if (!queue) {
		cout << "无法销毁,该队列不存在!" << endl;
		return false;
	}

	delete queue;
	return true;
}

void printQueue(QUEUE* queue) {
	if (!queue) {
		cout << "无法打印,该队列不存在!" << endl;
		return;
	}
	else if (queue->head == queue->tail) {
		cout << "无法打印,该队列为空!" << endl;
		return;
	}

	cout << "已入队元素个数: " << queue->tail << "\t剩余空间: " << DATASIZE - queue->tail << endl;
	for (int i = queue->head; i < queue->tail; i++) {
		cout << queue->data[i] << "    ";
	}
	cout << endl;
}