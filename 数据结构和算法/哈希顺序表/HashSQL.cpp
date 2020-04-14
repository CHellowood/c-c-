#include "HashSQL.h"
#include <iostream>

using namespace std;

//��ʼ����ϣ˳���
HashChain* initHash(int linenum) {
	if (linenum <= 0) linenum = LINENUM;
	
	HashChain* hashchain = new HashChain;//��ϣ˳��������ڴ�
	if (!hashchain) {
		cout << "initHash: hashchain new error!" << endl;
		return NULL;
	}

	hashchain->linenum = linenum;
	hashchain->hash = new SQL * [linenum];//��ϣ˳���ָ��˳����ָ�����������ڴ�
	if (!hashchain->hash) {
		cout << "initHash: hashchain->hash new error!" << endl;
		delete hashchain;
		return NULL;
	}

	//��ʼ��˳���
	for (int i = 0; i < linenum; i++) {
		hashchain->hash[i] = new SQL;
		hashchain->hash[i]->sql = new Data[SQLSIZE];
		if (!hashchain->hash[i]->sql) {
			cout << "initHash: hashchain->hash[" << i << "]->sql new error!" << endl;
			delete[] hashchain->hash;
			delete hashchain;
			return NULL;
		}

		hashchain->hash[i]->maxsize = SQLSIZE;
		hashchain->hash[i]->size = 0;
	}

	return hashchain;
}

//�����(key)����
Data* search(HashChain* hashchain, int key) {
	if (key > 0) {
		SQL* p = hashchain->hash[key % hashchain->linenum];

		for (int i = 0; i < p->size; i++) {
			if (p->sql[i].key == key) return &(p->sql[i]);
		}
	}
	return NULL;
}

//����ڵ�
bool insertNode(HashChain* hashchain, int key, void* data) {
	if (!hashchain) return false;
	if (search(hashchain, key)) {
		cout << "insertNode: ���" << key << "�Ѵ���!" << endl;
		return false;
	}
	SQL* p = hashchain->hash[key % hashchain->linenum];
	
	if (p->size == p->maxsize) {
		printf("insertNode: hashchain->hash[%d]����!", key % hashchain->linenum);
		return false;
	}
	
	p->sql[p->size].data = data;
	p->sql[p->size++].key = key;

	return true;
}

//ɾ���ڵ�
bool deleteNode(HashChain* hashchain, int key) {
	if (!hashchain) return false;
	if (!search(hashchain, key)) {
		cout << "deleteNode: ���" << key << "������!" << endl;
		return false;
	}

	SQL* p = hashchain->hash[key % hashchain->linenum];
	
	for (int i = 0; i < p->size; i++) {
		if (p->sql[i].key == key) {
			p->sql[i] = p->sql[--p->size];
			break;
		}
	}
	return true;
}

//���ٹ�ϣ����
void destroyHash(HashChain* hashchain) {
	if (hashchain) {
		for (int i = 0; i < hashchain->linenum; i++) {
			delete[] hashchain->hash[i]->sql;
			delete hashchain->hash[i];
		}
		delete[] hashchain->hash;
		delete hashchain;
	}
}


