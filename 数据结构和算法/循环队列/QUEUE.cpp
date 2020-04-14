#include <iostream>
#include "QUEUE.h"

using namespace std;

bool initQueue(QUEUE* queue) {
	if (!queue) {
		cout << "�޷���ʼ��,�ö��в�����!" << endl;
		return false;
	}

	queue->head = queue->tail = 0;

	return true;
}

bool addData(QUEUE* queue, int& n) {
	if (!queue) {
		cout << "�޷����,�ö��в�����!" << endl;
		return false;
	}
	else if (((queue->tail + 1) % DATASIZE) == queue->head) {
		cout << n << " �޷����, ��������!" << endl;
		return false;
	}

	queue->data[queue->tail] = n;
	queue->tail = (queue->tail + 1) % DATASIZE;

	return true;
}

bool deleteData(QUEUE* queue, DataType& ret) {
	if (!queue) {
		cout << "�޷�����,�ö��в�����!" << endl;
		return false;
	}
	else if (queue->head == queue->tail) {
		cout << "�޷�����,�ö���Ϊ��!" << endl;
		return false;
	}

	ret = queue->data[queue->head];
	queue->head = (queue->head + 1) % DATASIZE;

	return true;
}

bool destroyQueue(QUEUE* queue) {
	if (!queue) {
		cout << "�޷�����,�ö��в�����!" << endl;
		return false;
	}

	delete queue;
	return true;
}

void printQueue(QUEUE* queue) {
	if (!queue) {
		cout << "�޷���ӡ,�ö��в�����!" << endl;
		return;
	}
	else if (queue->head == queue->tail) {
		cout << "�޷���ӡ,�ö���Ϊ��!" << endl;
		return;
	}

	cout << "�����Ԫ�ظ���: " << (queue->tail - queue->head + DATASIZE) % DATASIZE << "\tʣ��ռ�: " << DATASIZE - 1 - (queue->tail - queue->head + DATASIZE) % DATASIZE << endl;
	for (int i = queue->head; i%DATASIZE != queue->tail; i++) {
		cout << queue->data[i % DATASIZE] << "    ";
	}
	cout << endl;
}