#include "BinSeaTree.h"
#include <iostream>

using namespace std;

//插入节点
bool insertNode(BinTree** tree, TreeNode* node) {
	if (!node) return false;

	node->left_child_node = NULL;
	node->right_child_node = NULL;

	if (!*tree) {
		*tree = node;
		return true;
	}

	TreeNode* son = *tree, *father = NULL;
	while (son) {
		father = son;
		if (node->data >= son->data) {
			son = son->right_child_node;
		}
		else {
			son = son->left_child_node;
		}
	}

	if (node->data >= father->data) {
		father->right_child_node = node;
	}
	else {
		father->left_child_node = node;
	}

	return true;
}

//删除节点 方法一
TreeNode* deleteNode(BinTree** tree, DataType data) {
	if (!*tree) return NULL;

	TreeNode* p = *tree, *father = NULL;
	while (p && p->data != data) {//寻找要删除的结点
		father = p;
		if (p->data < data) {
			p = p->right_child_node;
			continue;
		}
		else if (p->data > data) {
			p = p->left_child_node;
			continue;
		}
	}

	if (!p) {
		cout << data << "不存在!" << endl;
		return NULL;
	}

	int num = 0;
	TreeNode* naxt = NULL;
	
	if (!p->left_child_node && !p->right_child_node) {
		if (!father) {//father为空表示要删除的是根节点
			return *tree;
		}
		naxt = NULL;
	}
	else if (p->left_child_node && !p->right_child_node) {
		if (!father) {//father为空表示要删除的是根节点
			*tree = (*tree)->left_child_node;
			return p;
		}
		naxt = p->left_child_node;
	}
	else if (!p->left_child_node && p->right_child_node) {
		if (!father) {//father为空表示要删除的是根节点
			*tree = (*tree)->right_child_node;
			return p;
		}
		naxt = p->right_child_node;
	}
	//思路:要删除的结点存在左右子结点,
	//就在左子树(左子结点下面)里找最大的那一个结点,然后把要删除的结点的值换成左子树最大的那个结点的值
	//或在右子树(右子结点下面)里找最小的那一个结点,然后把要删除的结点的值换成右子树最小的那个结点的值
	//下面采用的是左子树的那个方法
	else if (p->left_child_node && p->right_child_node) {
		naxt = p->left_child_node;//要删除的结点的左子结点
		if (naxt->right_child_node == NULL) {//要删除的结点的左子结点的右子结点为空
			p->data = naxt->data;
			p->left_child_node = naxt->left_child_node;
			return naxt;
		}
		while (naxt) {//寻找左子树最大的结点
			if (naxt->right_child_node == NULL) {
				p->data = naxt->data;
				father->right_child_node = NULL;
				return naxt;
			}
			father = naxt;
			naxt = naxt->right_child_node;
		}
	}

	

	if (father->data > data) {
		father->left_child_node = naxt;
	}
	else {
		father->right_child_node = naxt;
	}
	
	return p;
}

//找最大结点
TreeNode* findMax(TreeNode* node) {
	if (!node) return NULL;

	if (node->right_child_node) {
		node = findMax(node->right_child_node);
	}
	return node;
}

//删除结点 方法二 递归
TreeNode* _deleteNode(BinTree** node, DataType data, TreeNode*& ret) {
	if (!*node) return NULL;

	if ((*node)->data > data) {
		(*node)->left_child_node = _deleteNode(&(*node)->left_child_node, data, ret);
		return *node;
	}
	else if ((*node)->data < data) {
		(*node)->right_child_node = _deleteNode(&(*node)->right_child_node, data, ret);
		return *node;
	}

	ret = *node;

	//要删除的结点不存在左右子结点
	if (!(*node)->left_child_node && !(*node)->right_child_node) return NULL;
	
	//要删除的结点存在左子结点
	if ((*node)->left_child_node && !(*node)->right_child_node)  return (*node)->left_child_node;
	
	//要删除的结点存在右子结点
	if (!(*node)->left_child_node && (*node)->right_child_node)  return (*node)->right_child_node;
	
	//要删除的结点存在左右子结点
	(*node)->data = (findMax((*node)->left_child_node))->data;
	(*node)->left_child_node = _deleteNode(&(*node)->left_child_node, (*node)->data, ret);
	return *node;
}

//查找结点
TreeNode* search(BinTree** tree, int data) {
	if (!*tree) {
		cout << "树为空!" << endl;
		return NULL;
	}

	TreeNode* node = *tree;
	while (node && node->data != data) {
		if (node->data > data) {
			node = node->left_child_node;
		}
		else if (node->data < data) {
			node = node->right_child_node;
		}
	}
	return node;
}


//前序遍历
void printTree_pre(BinTree* tree) {
	if (!tree) return;

	cout  << " " << tree->data;
	printTree_pre(tree->left_child_node);
	printTree_pre(tree->right_child_node);
}


//中序遍历(排序遍历)
void printTree_midSq(BinTree* tree) {
	if (!tree) return;

	printTree_midSq(tree->left_child_node);
	cout << " " << tree->data;
	printTree_midSq(tree->right_child_node);
}