#include <iostream>
#include "LinkQueue.h"

using namespace std;

bool initQueue(QUEUE* queue) {
	if (!queue) return false;

	queue->head = queue->tail = NULL;
	queue->length = 0;

	return true;
}

bool addNode(QUEUE* queue, DataType* data) {
	if (!queue || !data) return false;

	if (queue->length == QUEUE_MAXLEN) {
		cout << *data << " �޷����,��������!" << endl;
		return false;
	}

	LINK* p = new LINK;
	p->data = *data;
	p->naxt = NULL;

	if (queue->head == NULL) {
		queue->head = queue->tail = p;
		queue->length++;
		return true;
	}
	queue->tail->naxt = p;
	queue->tail = p;
	queue->length++;

	return true;
}

bool deleteNode(QUEUE* queue, DataType* data) {
	if (!queue || !queue->head || !data) return false;

	LINK* p = queue->head;

	*data = p->data;
	queue->head = p->naxt;
	delete p;

	if (queue->head == NULL) queue->tail = NULL;
	queue->length--;
	return true;
}

bool clearQueue(QUEUE* queue) {
	if (!queue || !queue->head) return false;

	LINK* p = queue->head;
	while (queue->head) {
		queue->head = p->naxt;
		delete p;
		p = queue->head;
	}
	queue->tail = NULL;
	queue->length = 0;

	return true;
}

void printQueue(QUEUE* queue) {
	if (!queue || !queue->head) {
		cout << "���в����ڻ����Ϊ��!" << endl;
		return;
	}

	LINK* p = queue->head;
	
	cout << "��ǰ�����Ԫ�ظ���: " << queue->length << "\tʣ��ռ�: " << QUEUE_MAXLEN - queue->length << endl;
	while (p) {
		cout << p->data << "\t";
		p = p->naxt;
	}
	cout << endl;
}