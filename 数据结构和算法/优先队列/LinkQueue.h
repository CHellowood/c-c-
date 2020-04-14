//#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#define QUEUE_MAXLEN 5

typedef int DataType;

typedef struct Link {
	int vip;      //���ȼ�, ��ö�ٸ���
	DataType data;
	Link* naxt;
}LINK;

typedef LINK* LINK_P;

typedef struct Queue {
	int length;
	LINK_P head;
	LINK_P tail;
}QUEUE;

bool initQueue(QUEUE* queue);                 //��ʼ������
//bool emptyQueue(QUEUE* queue);                //���Queue�Ƿ�Ϊ��
//bool fullQueue(QUEUE* queue);                 //���Queue�Ƿ�Ϊ��
bool addNode(QUEUE* queue, DataType* data, int* vip);   //���
bool deleteNode(QUEUE* queue, DataType* data);//����
bool clearQueue(QUEUE* queue);                //��ն���
void printQueue(QUEUE* queue);                //��ӡ����

#endif 