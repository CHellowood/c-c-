//#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include "BinSeaTree.h"

#define QUEUE_MAXLEN 10

typedef TreeNode* QDataType;

typedef struct Link {
	//int vip;      //���ȼ�, ���ȼ�������ö�ٸ���
	QDataType data;
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
bool addNode(QUEUE* queue, QDataType data);//, int* vip);   //���
bool deleteNode(QUEUE* queue, TreeNode** retdata);//����
bool clearQueue(QUEUE* queue);                //��ն���
void printQueue(QUEUE* queue);                //��ӡ����

#endif 