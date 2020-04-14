//#pragma once
#ifndef _HASHLINK_H_
#define _HASHLINK_H_

//��ϣ��Ĭ������(Ͱ��)
#define LINENUM 10
//˳����С
#define SQLSIZE 5

typedef struct _Data {
	int key;
	void* data;
}Data;

typedef struct _SQL{
	Data* sql;
	int maxsize;//�ܴ�С
	int size;   //��ǰ��С
}SQL;

typedef SQL* List; //��

typedef struct _HashChain {
	int linenum; //��ϣ˳�������(Ͱ��)
	List* hash;
}HashChain;

HashChain* initHash(int linknum);
Data* search(HashChain* hashchain, int key);
bool insertNode(HashChain* hashchain, int key, void* data);
bool deleteNode(HashChain* hashchain, int key);
void destroyHash(HashChain* hashchain);

#endif 