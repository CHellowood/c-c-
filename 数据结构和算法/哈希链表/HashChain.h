//#pragma once
#ifndef _HASHLINK_H_
#define _HASHLINK_H_

////哈希表默认行数(桶数)
#define LINENUM 10

typedef struct _Chain {
	int key;    //编号
	void* data; //数据
	_Chain* naxt;//下一个结点
}Chain, ChainNode;

typedef Chain* List; //表

typedef struct _HashChain {
	int linenum; //哈希表行数(桶数)
	List* hash;
}HashChain;

HashChain* initHash(int linknum);
Chain* search(HashChain* hashchain, int key);
bool insertNode(HashChain* hashchain, int key, void* data);
bool deleteNode(HashChain* hashchain, int key);
void destroyHash(HashChain* hashchain);

#endif 