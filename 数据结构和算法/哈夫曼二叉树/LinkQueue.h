//#pragma once
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include "BinSeaTree.h"

#define QUEUE_MAXLEN 10

typedef TreeNode* QDataType;

typedef struct Link {
	//int vip;      //优先级, 优先级类型用枚举更好
	QDataType data;
	Link* naxt;
}LINK;

typedef LINK* LINK_P;

typedef struct Queue {
	int length;
	LINK_P head;
	LINK_P tail;
}QUEUE;

bool initQueue(QUEUE* queue);                 //初始化队列
//bool emptyQueue(QUEUE* queue);                //检查Queue是否为空
//bool fullQueue(QUEUE* queue);                 //检查Queue是否为满
bool addNode(QUEUE* queue, QDataType data);//, int* vip);   //入队
bool deleteNode(QUEUE* queue, TreeNode** retdata);//出队
bool clearQueue(QUEUE* queue);                //清空队列
void printQueue(QUEUE* queue);                //打印队列

#endif 