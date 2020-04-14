#include <iostream>
#include <Windows.h>
#include "BinSeaTree.h"
#include "LinkQueue.h"

using namespace std;

void HuffmanTree(BinTree** tree, int num) {
	QUEUE* queue = new QUEUE;

	initQueue(queue);

	for (int i = 0; i < num; i++) {
		TreeNode* node = new TreeNode;
		if (!node) {
			cout << "HuffmanTree:�ڴ治��,node�ڴ�����ʧ��!" << endl;
			continue;
		}
		node->father_node = NULL;
		node->left_child_node = NULL;
		node->right_child_node = NULL;

		cout << "�������ַ����ַ����ִ���:";
		cin >> node->ch >> node->vip;

		if (addNode(queue, node)) {
			cout << node->ch << "��ӳɹ�!" << endl;
		}
		else {
			cout << node->ch << "���ʧ��!" << endl;
			continue;
		}
	}
	printQueue(queue);

	while (true) {
		TreeNode *node1 = NULL, *node2 = NULL;
		if (queue->head) {
			deleteNode(queue, &node1);
			cout << "���ӵ���: " << node1->ch << "���ȼ�: " << node1->vip << endl;
		}
		else break;

		if (queue->head) {
			TreeNode* newnode = new TreeNode;
			if (!newnode) {
				cout << "HuffmanTree:�ڴ治��,newnode�ڴ�����ʧ��!" << endl;
				cout << "������������ʧ��!" << endl;
				break;
			}

			deleteNode(queue, &node2);
			cout << "���ӵ���: " << node2->ch << "���ȼ�: " << node2->vip << endl;

			node1->father_node = newnode;
			newnode->left_child_node = node1;
			node2->father_node = newnode;
			newnode->right_child_node = node2;

			newnode->ch = '?';
			newnode->vip = node1->vip + node2->vip;
			cout << "�ºϲ��Ľ����: " << newnode->ch << "���ȼ�: " << newnode->vip << endl;
			addNode(queue, newnode);
		}
		else {
			*tree = node1;
			break;
		}
	}
	delete queue;
}

int main(void) {
	BinTree* tree = NULL;

	HuffmanTree(&tree, 7);
	printTree_pre(tree);

	

	system("pause");
	return 0;
}