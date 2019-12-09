#include <iostream>
#include <Windows.h>
#include "BinSeaTree.h"

using namespace std;

int main(void) {
	BinTree* tree = NULL;

	cout << endl << "<------插入结点------>" << endl;
	
	int i = 0;
	cout << "插入结点个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		TreeNode* node = new TreeNode;
		if (!node) {
			cout << "第" << j + 1 << "个结点内存申请失败!" << endl;
			continue;
		}
		cout << "第" << j+1 << "个:";
		cin >> node->data;

		insertNode(&tree, node);
		
		printTree_pre(tree);
		cout << endl;
		printTree_midSq(tree);
		cout << endl;
	}

	cout << endl << "<------删除结点------>" << endl;

	cout << "删除结点个数:" << endl;
	cin >> i;

	for (int j = 0, n = 0; j < i; j++) {
		 
		cout << "第" << j + 1 << "个:";
		cin >> n;

		TreeNode* node = NULL;
		_deleteNode(&tree, n, node);
		if (!node) {
			cout << "二叉树里没有" << n << endl;
			continue;
		}

		delete node;
		printTree_pre(tree);
		cout << endl;
		printTree_midSq(tree);
		cout << endl;
	}


	cout << endl << "<------查找结点------>" << endl;

	cout << "查找:" << endl;
	cin >> i;

	TreeNode* node = search(&tree, i);
	if (!node) {
		cout  << "没有找到" << i  << "!" << endl;
	}
	else {
		cout << node->data << endl;
	}

	system("pause");
	return 0;
}
