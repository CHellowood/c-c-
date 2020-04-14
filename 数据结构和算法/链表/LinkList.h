//#pragma once
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <vector>

typedef struct LinkNode {
	int data;
	struct LinkNode* naxt;
}LinkHead, LinkList;

//LinkHead : 链头: 链头不储存数据, 只储存下一个结点地址
//LinkLists : 链表的结点

bool initNode(LinkHead* &link);                  //初始化链表
bool addNodeHead(LinkHead* &link, int &n);       //在头部添加结点
bool addNodeTail(LinkHead* &link, int &n);       //在尾部添加结点
bool insertNode(LinkHead* &link, int &i, int &n);//插入结点
bool searchNode(LinkHead* &link, int &i);        //根据结点位置查找结点并把结点数据打印出来
bool searchNode(LinkHead* &link, int &i, int &n);//根据结点位置查找结点并把该结点的数据返回给 n
void searchData(LinkHead* &link, int &n);        //根据结点数据查找结点并把结点的位置和数据打印出来
bool deleteNode(LinkHead* &link, int &i);        //删除结点
void destroyLinkNode(LinkHead* &link);           //销毁链表
void printNode(LinkHead* &link);                 //打印链表

#endif 