//#pragma once
#ifndef _CYCLELINK_H_
#define _CYCLELINK_H_

typedef struct CycleLink {
	int data;
	CycleLink* naxt;
}LinkHead, LinkList;

bool initCycleLink(LinkHead*& link);             //初始化循环链表
bool addNode_Head(LinkHead*& link, int& n);      //在链表头部添加结点
bool addNode_Tail(LinkHead*& link, int& n);      //在链表尾部添加结点
bool insertNode(LinkHead*& link, int& i, int& n);//插入结点
bool deleteNode(LinkHead*& link, int& i);        //删除结点
void destroyCycleLink(LinkHead*& link);          //销毁循环链表
void printCycleLink(LinkHead*& link);            //打印循环链表

#endif 