//#pragma once
#ifndef _TIMEOUT_LIST_
#define _TIMEOUT_LIST_

#define LIST_MAX 10

typedef struct {
	time_t connectionTime;//连接时间
	int fd;            //代号
}CONNECTION;

typedef struct {
	CONNECTION* connection;//连接列表
	int lenght;     //已有数据的元素个数
	int size;       //顺序表大小
}CONTIOUT;

bool initList(CONTIOUT& list);
bool addConnection(CONTIOUT& list, CONNECTION n);
bool insertConnection(CONTIOUT& list, int i, CONNECTION n);
bool deleteConnection(CONTIOUT& list, int i);
void destroyList(CONTIOUT& list);
void printList(CONTIOUT& list);

#endif