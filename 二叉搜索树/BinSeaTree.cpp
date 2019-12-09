#include "BinSeaTree.h"
#include <iostream>

using namespace std;

//����ڵ�
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

//ɾ���ڵ� ����һ
TreeNode* deleteNode(BinTree** tree, DataType data) {
	if (!*tree) return NULL;

	TreeNode* p = *tree, *father = NULL;
	while (p && p->data != data) {//Ѱ��Ҫɾ���Ľ��
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
		cout << data << "������!" << endl;
		return NULL;
	}

	int num = 0;
	TreeNode* naxt = NULL;
	
	if (!p->left_child_node && !p->right_child_node) {
		if (!father) {//fatherΪ�ձ�ʾҪɾ�����Ǹ��ڵ�
			return *tree;
		}
		naxt = NULL;
	}
	else if (p->left_child_node && !p->right_child_node) {
		if (!father) {//fatherΪ�ձ�ʾҪɾ�����Ǹ��ڵ�
			*tree = (*tree)->left_child_node;
			return p;
		}
		naxt = p->left_child_node;
	}
	else if (!p->left_child_node && p->right_child_node) {
		if (!father) {//fatherΪ�ձ�ʾҪɾ�����Ǹ��ڵ�
			*tree = (*tree)->right_child_node;
			return p;
		}
		naxt = p->right_child_node;
	}
	//˼·:Ҫɾ���Ľ����������ӽ��,
	//����������(���ӽ������)����������һ�����,Ȼ���Ҫɾ���Ľ���ֵ���������������Ǹ�����ֵ
	//����������(���ӽ������)������С����һ�����,Ȼ���Ҫɾ���Ľ���ֵ������������С���Ǹ�����ֵ
	//������õ������������Ǹ�����
	else if (p->left_child_node && p->right_child_node) {
		naxt = p->left_child_node;//Ҫɾ���Ľ������ӽ��
		if (naxt->right_child_node == NULL) {//Ҫɾ���Ľ������ӽ������ӽ��Ϊ��
			p->data = naxt->data;
			p->left_child_node = naxt->left_child_node;
			return naxt;
		}
		while (naxt) {//Ѱ�����������Ľ��
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

//�������
TreeNode* findMax(TreeNode* node) {
	if (!node) return NULL;

	if (node->right_child_node) {
		node = findMax(node->right_child_node);
	}
	return node;
}

//ɾ����� ������ �ݹ�
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

	//Ҫɾ���Ľ�㲻���������ӽ��
	if (!(*node)->left_child_node && !(*node)->right_child_node) return NULL;
	
	//Ҫɾ���Ľ��������ӽ��
	if ((*node)->left_child_node && !(*node)->right_child_node)  return (*node)->left_child_node;
	
	//Ҫɾ���Ľ��������ӽ��
	if (!(*node)->left_child_node && (*node)->right_child_node)  return (*node)->right_child_node;
	
	//Ҫɾ���Ľ����������ӽ��
	(*node)->data = (findMax((*node)->left_child_node))->data;
	(*node)->left_child_node = _deleteNode(&(*node)->left_child_node, (*node)->data, ret);
	return *node;
}

//���ҽ��
TreeNode* search(BinTree** tree, int data) {
	if (!*tree) {
		cout << "��Ϊ��!" << endl;
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


//ǰ�����
void printTree_pre(BinTree* tree) {
	if (!tree) return;

	cout  << " " << tree->data;
	printTree_pre(tree->left_child_node);
	printTree_pre(tree->right_child_node);
}


//�������(�������)
void printTree_midSq(BinTree* tree) {
	if (!tree) return;

	printTree_midSq(tree->left_child_node);
	cout << " " << tree->data;
	printTree_midSq(tree->right_child_node);
}