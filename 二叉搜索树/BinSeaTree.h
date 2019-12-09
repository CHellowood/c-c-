//#pragma once
#ifndef _BINSEATREE_H_
#define _BINSEATREE_H_

typedef int DataType;

typedef struct _BinTree {
	DataType data;
	_BinTree* left_child_node;
	_BinTree* right_child_node;
}BinTree,TreeNode;

bool insertNode(BinTree** tree, TreeNode* node);    //����ڵ�
TreeNode* deleteNode(BinTree** tree, DataType data);//ɾ���ڵ� ����һ
TreeNode* _deleteNode(BinTree** tree, DataType data, TreeNode*& ret);//ɾ���ڵ� ������ �ݹ�
TreeNode* search(BinTree** tree, int data);         //���ҽ��
void printTree_pre(BinTree* tree);                  //ǰ�����
void printTree_midSq(BinTree* tree);                //�������(�������)

#endif 