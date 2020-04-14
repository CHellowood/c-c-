//#pragma once
#ifndef _BINSEATREE_H_
#define _BINSEATREE_H_

typedef int TDataType;

typedef struct _BinTree {
	char ch;
	TDataType vip;
	_BinTree* father_node;
	_BinTree* left_child_node;
	_BinTree* right_child_node;
}BinTree,TreeNode;

bool insertNode(BinTree** tree, TreeNode* node);    //插入节点
TreeNode* deleteNode(BinTree** tree, TDataType data);//删除节点 方法一
TreeNode* _deleteNode(BinTree** tree, TDataType data, TreeNode*& ret);//删除节点 方法二 递归
TreeNode* search(BinTree** tree, int data);         //查找结点
void printTree_pre(BinTree* tree);                  //前序遍历
void printTree_midSq(BinTree* tree);                //中序遍历(排序遍历)

#endif 