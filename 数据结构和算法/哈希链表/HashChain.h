//#pragma once
#ifndef _HASHLINK_H_
#define _HASHLINK_H_

////��ϣ��Ĭ������(Ͱ��)
#define LINENUM 10

typedef struct _Chain {
	int key;    //���
	void* data; //����
	_Chain* naxt;//��һ�����
}Chain, ChainNode;

typedef Chain* List; //��

typedef struct _HashChain {
	int linenum; //��ϣ������(Ͱ��)
	List* hash;
}HashChain;

HashChain* initHash(int linknum);
Chain* search(HashChain* hashchain, int key);
bool insertNode(HashChain* hashchain, int key, void* data);
bool deleteNode(HashChain* hashchain, int key);
void destroyHash(HashChain* hashchain);

#endif 