#include "HashChain.h"
#include <iostream>

using namespace std;

//��ʼ����ϣ����
HashChain* initHash(int linenum) {
	if (linenum <= 0) linenum = LINENUM;
	
	HashChain* hashchain = new HashChain;//��ϣ���������ڴ�
	if (!hashchain) {
		cout << "initHash: hashchain new error!" << endl;
		return NULL;
	}

	hashchain->linenum = linenum;
	hashchain->hash = new Chain*[linenum];//��ϣ����ָ����ͷ��ָ�����������ڴ�
	if (!hashchain->hash) {
		cout << "initHash: hashchain->hash new error!" << endl;
		delete hashchain;
		return NULL;
	}

	for (int i = 0; i < linenum; i++) {
		hashchain->hash[i] = new Chain;//��ϣ������ͷ�����ڴ�
		if (!hashchain->hash[i]) {
			cout << "initHash: hashchain->hash[" << i << "] new error!" << endl;
			delete[] hashchain->hash;
			delete hashchain;
			return NULL;
		}

		//��ʼ����ͷ
		hashchain->hash[i]->data = 0;
		hashchain->hash[i]->key  = 0;
		hashchain->hash[i]->naxt = NULL;
	}
	return hashchain;
}

//�����(key)����
Chain* search(HashChain* hashchain, int key) {
	if (key > 0) {
		Chain* p = hashchain->hash[key % hashchain->linenum]->naxt;

		while (p && p->key != key) p = p->naxt;
		if (!p) return NULL;

		return p;
	}
	else return NULL;
}

//����ڵ�
bool insertNode(HashChain* hashchain, int key, void* data) {
	if (!hashchain) return false;
	if (search(hashchain, key)) {
		cout << "insertNode: ���" << key << "�Ѵ���!" << endl;
		return false;
	}

	Chain* p = new Chain;
	if (!p) {
		cout << "insertNode: p new error!" << endl;
		return false;
	}

	p->data = data;
	p->key = key;
	p->naxt = hashchain->hash[key % hashchain->linenum]->naxt;
	hashchain->hash[key % hashchain->linenum]->naxt = p;

	return true;
}

//ɾ���ڵ�
bool deleteNode(HashChain* hashchain, int key) {
	if (!hashchain) return false;
	if (!search(hashchain, key)) {
		cout << "deleteNode: ���" << key << "������!" << endl;
		return false;
	}

	Chain* p = hashchain->hash[key % hashchain->linenum];
	while (p->naxt && p->naxt->key != key) p = p->naxt;

	if (!p) return false;

	Chain* d = p->naxt;
	p->naxt = d->naxt;
	delete d;

	return true;
}

//���ٹ�ϣ����
void destroyHash(HashChain* hashchain) {
	if (hashchain) {
		for (int i = 0; i < hashchain->linenum; i++) {
			Chain* p = hashchain->hash[i];
			while (p) {
				hashchain->hash[i] = p->naxt;
				delete p;
				p = hashchain->hash[i];
			}
		}
		delete[] hashchain->hash;
		delete hashchain;
	}
}

