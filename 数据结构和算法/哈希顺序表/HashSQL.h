//#pragma once
#ifndef _HASHLINK_H_
#define _HASHLINK_H_

//哈希表默认行数(桶数)
#define LINENUM 10
//顺序表大小
#define SQLSIZE 5

typedef struct _Data {
	int key;
	void* data;
}Data;

typedef struct _SQL{
	Data* sql;
	int maxsize;//总大小
	int size;   //当前大小
}SQL;

typedef SQL* List; //表

typedef struct _HashChain {
	int linenum; //哈希顺序表行数(桶数)
	List* hash;
}HashChain;

HashChain* initHash(int linknum);
Data* search(HashChain* hashchain, int key);
bool insertNode(HashChain* hashchain, int key, void* data);
bool deleteNode(HashChain* hashchain, int key);
void destroyHash(HashChain* hashchain);

#endif 