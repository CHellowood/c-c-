#include "BinSeaTree.h"
#include <iostream>

using namespace std;

//����ڵ�
bool insertNode(BinTree** tree, TreeNode* node) {
	if (!node) return false;

	node->father_node = NULL;
	node->left_child_node = NULL;
	node->right_child_node = NULL;

	if (!*tree) {
		*tree = node;
		return true;
	}

	TreeNode* son = *tree, *father = NULL;
	while (son) {
		father = son;
		if (node->vip >= son->vip) {
			son = son->right_child_node;
		}
		else {
			son = son->left_child_node;
		}
	}

	node->father_node = father;
	if (node->vip >= father->vip) {
		father->right_child_node = node;
	}
	else {
		father->left_child_node = node;
	}

	return true;
}

//ɾ���ڵ� ����һ
TreeNode* deleteNode(BinTree** tree, TDataType data) {
	if (!*tree) return NULL;

	TreeNode* p = *tree;
	while (p && p->vip != data) {//Ѱ��Ҫɾ���Ľ��
		if (p->vip < data) {
			p = p->right_child_node;
			continue;
		}
		else if (p->vip > data) {
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
		if (!p->father_node) {//fatherΪ�ձ�ʾҪɾ�����Ǹ��ڵ�
			return *tree;
		}
		naxt = NULL;
	}
	else if (p->left_child_node && !p->right_child_node) {
		if (!p->father_node) {//fatherΪ�ձ�ʾҪɾ�����Ǹ��ڵ�
			*tree = (*tree)->left_child_node;
			return p;
		}
		naxt = p->left_child_node;
	}
	else if (!p->left_child_node && p->right_child_node) {
		if (!p->father_node) {//fatherΪ�ձ�ʾҪɾ�����Ǹ��ڵ�
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
			p->vip = naxt->vip;
			p->left_child_node = naxt->left_child_node;
			return naxt;
		}
		while (naxt) {//Ѱ�����������Ľ��
			if (naxt->right_child_node == NULL) {
				p->vip = naxt->vip;
				naxt->father_node->right_child_node = NULL;
				return naxt;
			}
			naxt = naxt->right_child_node;
		}
	}

	

	if (p->father_node->vip > data) {
		p->father_node->left_child_node = naxt;
	}
	else {
		p->father_node->right_child_node = naxt;
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
TreeNode* _deleteNode(BinTree** node, TDataType data, TreeNode*& ret) {
	if (!*node) return NULL;

	if ((*node)->vip > data) {
		(*node)->left_child_node = _deleteNode(&(*node)->left_child_node, data, ret);
		return *node;
	}
	else if ((*node)->vip < data) {
		(*node)->right_child_node = _deleteNode(&(*node)->right_child_node, data, ret);
		return *node;
	}

	ret = *node;

	//Ҫɾ���Ľ�㲻���������ӽ��
	if (!(*node)->left_child_node && !(*node)->right_child_node) return NULL;
	
	//Ҫɾ���Ľ��������ӽ��
	if ((*node)->left_child_node && !(*node)->right_child_node) {
		if ((*node)->left_child_node->left_child_node)
			(*node)->left_child_node->left_child_node->father_node = (*node)->father_node;
		if ((*node)->left_child_node->right_child_node)
			(*node)->left_child_node->right_child_node->father_node = (*node)->father_node;

		return (*node)->left_child_node;
	}

	//Ҫɾ���Ľ��������ӽ��
	if (!(*node)->left_child_node && (*node)->right_child_node) {
		if ((*node)->right_child_node->left_child_node)
			(*node)->right_child_node->left_child_node->father_node = (*node)->father_node;
		if ((*node)->right_child_node->right_child_node)
			(*node)->right_child_node->right_child_node->father_node = (*node)->father_node;

		return (*node)->right_child_node;
	}

	//Ҫɾ���Ľ����������ӽ��
	(*node)->vip = (findMax((*node)->left_child_node))->vip;
	(*node)->left_child_node = _deleteNode(&(*node)->left_child_node, (*node)->vip, ret);
	return *node;
}

//���ҽ��
TreeNode* search(BinTree** tree, int data) {
	if (!*tree) {
		cout << "��Ϊ��!" << endl;
		return NULL;
	}

	TreeNode* node = *tree;
	while (node && node->vip != data) {
		if (node->vip > data) {
			node = node->left_child_node;
			
		}
		else if (node->vip < data) {
			node = node->right_child_node;
			
		}
	}
	
	return node;
}


//ǰ�����
void printTree_pre(BinTree* tree) {
	if (!tree) return;

	cout  << " " << tree->ch;
	printTree_pre(tree->left_child_node);
	printTree_pre(tree->right_child_node);
}


//�������(�������)
void printTree_midSq(BinTree* tree) {
	if (!tree) return;

	printTree_midSq(tree->left_child_node);
	cout << " " << tree->ch;
	printTree_midSq(tree->right_child_node);
}