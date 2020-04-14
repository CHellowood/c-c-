//#pragma once

#ifndef _DOUBLELINK_H_
#define _DOUBLELINK_H_

//链表指针域结构体
typedef struct DoubleLink_Pointer {
	DoubleLink_Pointer* former;
	DoubleLink_Pointer* naxt;
}DLink_Pointer;

typedef struct DoubleLinkList{
	int data;             //数据域
	DLink_Pointer pointer;//指针域
}DLink;

DLink* CalculationAddress(DLink_Pointer*& node);                         //根据结点指针域的地址计算结点的首地址
void initDLink(DLink_Pointer& nodeHead);                                 //初始化双向链表
bool addNode_Head(DLink_Pointer& nodeHead, DLink_Pointer& newNode);      //在头部添加结点
bool addNode_Tail(DLink_Pointer& nodeHead, DLink_Pointer& newNode);      //在尾部添加结点
bool insertNode(DLink_Pointer& nodeHead, int& i, DLink_Pointer& newNode);//在链表中插入结点
bool deleteNode(DLink_Pointer& nodeHead, int& i);                        //在链表中删除结点
void destroyDLink(DLink_Pointer& nodeHead);                              //销毁链表
void printDLink(DLink_Pointer& nodeHead);                                //打印链表

#endif 