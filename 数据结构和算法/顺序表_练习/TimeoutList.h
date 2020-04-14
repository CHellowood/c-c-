//#pragma once
#ifndef _TIMEOUT_LIST_
#define _TIMEOUT_LIST_

#define LIST_MAX 10

typedef struct {
	time_t connectionTime;//����ʱ��
	int fd;            //����
}CONNECTION;

typedef struct {
	CONNECTION* connection;//�����б�
	int lenght;     //�������ݵ�Ԫ�ظ���
	int size;       //˳����С
}CONTIOUT;

bool initList(CONTIOUT& list);
bool addConnection(CONTIOUT& list, CONNECTION n);
bool insertConnection(CONTIOUT& list, int i, CONNECTION n);
bool deleteConnection(CONTIOUT& list, int i);
void destroyList(CONTIOUT& list);
void printList(CONTIOUT& list);

#endif