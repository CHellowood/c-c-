#include <iostream>
#include <Windows.h>
#include "HashSQL.h"

using namespace std;

void printHash(HashChain* hashchain) {
	if (!hashchain) {
		cout << "printHash: hashchain������!" << endl;
		return;
	}
	for (int i = 0; i < hashchain->linenum; i++) {
		for (int j = 0; j < hashchain->hash[i]->size; j++) {
			cout << " [" << hashchain->hash[i]->sql[j].key << "]" << (const char*)hashchain->hash[i]->sql[j].data << endl;
		}
	}
}

int main(void) {
	char str[3][5] = {"qi", "ying", "qiu"};
	cout << endl << "<------��ʼ����ϣ˳���------>" << endl;
	HashChain* hash = initHash(3);

	cout << endl << "<------����------>" << endl;
	insertNode(hash, 1, str[0]);
	insertNode(hash, 2, str[1]);
	insertNode(hash, 3, str[2]);
	printHash(hash);

	cout << endl << "<------����------>" << endl;
	Data* p = search(hash, 3);
	cout << "[" << p->key << "]" << (const char*)p->data;
	//cout << "[" << p->key << "]";
	//char* c = (char*)p->data;
	//while (*c != '\0') cout << *(c++);

	cout << endl << "<------ɾ����------>" << endl;
	deleteNode(hash, 1);
	deleteNode(hash, 2);
	printHash(hash);

	cout << endl << "<------����------>" << endl;
	insertNode(hash, 1, str[1]);
	insertNode(hash, 2, str[0]);

	printHash(hash);

	destroyHash(hash);

	system("pause");
	return 0;
}