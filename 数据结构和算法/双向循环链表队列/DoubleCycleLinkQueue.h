//#pragma once
#ifndef _DOUBLECYCLELINKQUEUE_H_
#define _DOUBLECYCLELINKQUEUE_H_

typedef struct DoubleLink {
	DoubleLink* former;
	DoubleLink* naxt;
}DLINK;

typedef int DataType;

typedef struct {
	DataType data;
	DLINK queue;
}QUEUE;

typedef struct {
	DLINK expiredQueue;
}EQUEUE;

//��ʼ������
#define INIT_QUEUE(queue)            \
		(queue)->former = queue;     \
		(queue)->naxt   = queue

//���
#define QUEUE_INSERT_HEAD(queue, node)     \
		(node)->former = queue;            \
		(node)->naxt   = (queue)->naxt;    \
		(node)->naxt->former = node;       \
		(queue)->naxt = node

//����
#define QUEUE_DELETE(queue)                     \
		(queue)->former->naxt = (queue)->naxt;  \
		(queue)->naxt->former = (queue)->former

#define CUT_ADDRESS(node, type, queue)              \
		(type*)((size_t)node - offsetof(type, queue))

#endif 
