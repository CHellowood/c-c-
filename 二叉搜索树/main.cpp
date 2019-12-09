#include <iostream>
#include <Windows.h>
#include "BinSeaTree.h"

using namespace std;

int main(void) {
	BinTree* tree = NULL;

	cout << endl << "<------������------>" << endl;
	
	int i = 0;
	cout << "���������:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		TreeNode* node = new TreeNode;
		if (!node) {
			cout << "��" << j + 1 << "������ڴ�����ʧ��!" << endl;
			continue;
		}
		cout << "��" << j+1 << "��:";
		cin >> node->data;

		insertNode(&tree, node);
		
		printTree_pre(tree);
		cout << endl;
		printTree_midSq(tree);
		cout << endl;
	}

	cout << endl << "<------ɾ�����------>" << endl;

	cout << "ɾ��������:" << endl;
	cin >> i;

	for (int j = 0, n = 0; j < i; j++) {
		 
		cout << "��" << j + 1 << "��:";
		cin >> n;

		TreeNode* node = NULL;
		_deleteNode(&tree, n, node);
		if (!node) {
			cout << "��������û��" << n << endl;
			continue;
		}

		delete node;
		printTree_pre(tree);
		cout << endl;
		printTree_midSq(tree);
		cout << endl;
	}


	cout << endl << "<------���ҽ��------>" << endl;

	cout << "����:" << endl;
	cin >> i;

	TreeNode* node = search(&tree, i);
	if (!node) {
		cout  << "û���ҵ�" << i  << "!" << endl;
	}
	else {
		cout << node->data << endl;
	}

	system("pause");
	return 0;
}
