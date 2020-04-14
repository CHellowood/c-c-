//#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int DataType;//��������

#define DATASIZE 5

typedef struct {
	DataType data[DATASIZE];
	int head;//����:��һ��Ԫ��
	int tail;//��β:���һ��Ԫ�ص���һ��
}QUEUE;

bool initQueue(QUEUE* queue);
bool addData(QUEUE* queue, int& n);
bool deleteData(QUEUE* queue, DataType& ret);
bool destroyQueue(QUEUE* queue);
void printQueue(QUEUE* queue);

#endif 