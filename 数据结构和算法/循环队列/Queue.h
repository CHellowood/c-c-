//#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef int DataType;//数据类型

#define DATASIZE 5

typedef struct {
	DataType data[DATASIZE];
	int head;//队首:第一个元素
	int tail;//队尾:最后一个元素的下一个
}QUEUE;

bool initQueue(QUEUE* queue);
bool addData(QUEUE* queue, int& n);
bool deleteData(QUEUE* queue, DataType& ret);
bool destroyQueue(QUEUE* queue);
void printQueue(QUEUE* queue);

#endif 