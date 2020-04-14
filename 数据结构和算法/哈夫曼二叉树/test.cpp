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
			cout << "HuffmanTree:内存不足,node内存申请失败!" << endl;
			continue;
		}
		node->father_node = NULL;
		node->left_child_node = NULL;
		node->right_child_node = NULL;

		cout << "请输入字符和字符出现次数:";
		cin >> node->ch >> node->vip;

		if (addNode(queue, node)) {
			cout << node->ch << "入队成功!" << endl;
		}
		else {
			cout << node->ch << "入队失败!" << endl;
			continue;
		}
	}
	printQueue(queue);

	while (true) {
		TreeNode *node1 = NULL, *node2 = NULL;
		if (queue->head) {
			deleteNode(queue, &node1);
			cout << "出队的是: " << node1->ch << "优先级: " << node1->vip << endl;
		}
		else break;

		if (queue->head) {
			TreeNode* newnode = new TreeNode;
			if (!newnode) {
				cout << "HuffmanTree:内存不足,newnode内存申请失败!" << endl;
				cout << "哈夫曼树生成失败!" << endl;
				break;
			}

			deleteNode(queue, &node2);
			cout << "出队的是: " << node2->ch << "优先级: " << node2->vip << endl;

			node1->father_node = newnode;
			newnode->left_child_node = node1;
			node2->father_node = newnode;
			newnode->right_child_node = node2;

			newnode->ch = '?';
			newnode->vip = node1->vip + node2->vip;
			cout << "新合并的结点是: " << newnode->ch << "优先级: " << newnode->vip << endl;
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