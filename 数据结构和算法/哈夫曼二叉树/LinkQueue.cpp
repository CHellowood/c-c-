#include <iostream>
#include "LinkQueue.h"

using namespace std;

bool initQueue(QUEUE* queue) {
	if (!queue) return false;

	queue->head = queue->tail = NULL;
	queue->length = 0;

	return true;
}

bool addNode(QUEUE* queue, QDataType data) {//, int* vip) {
	if (!queue || !data) return false;

	if (queue->length == QUEUE_MAXLEN) {
		cout << data->ch << " �޷����,��������!" << endl;
		return false;
	}

	LINK* p = new LINK;
	p->data = data;
	p->naxt = NULL;

	if (queue->head == NULL) {
		queue->head = queue->tail = p;
		queue->length++;
		return true;
	}
	 p->naxt = queue->head;
	queue->head = p;
	queue->length++;

	return true;
}

//����
bool deleteNode(QUEUE* queue, TreeNode** retdata) {
	if (!queue || !queue->head || !retdata) return false;

	LINK* p = queue->head, *pFormer = NULL;
	LINK* t = queue->head, *tFormer = NULL;

	while (t) {
		if (t->data->vip < p->data->vip) {
			pFormer = tFormer;
			p = t;
		}
		tFormer = t;
		t = t->naxt;
	}

	*retdata = p->data;
	
	if (pFormer) pFormer->naxt = p->naxt;
	else queue->head = p->naxt;
	if (!p->naxt) queue->tail = pFormer;

	delete p;

	if (queue->head == NULL) queue->tail = NULL;
	queue->length--;
	return true;
}

//��ն���
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
		cout << p->data->ch << "\t";
		p = p->naxt;
	}
	cout << endl;
}