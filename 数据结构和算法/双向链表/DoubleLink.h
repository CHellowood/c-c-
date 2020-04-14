//#pragma once

#ifndef _DOUBLELINK_H_
#define _DOUBLELINK_H_

typedef struct DoubleLink {
	int data;
	DoubleLink* former;  //��һ�����
	DoubleLink* naxt;    //��һ�����
}LinkHead, LinkList;

bool initDoubleLink(LinkHead*& link);
bool addNode_Head(LinkHead*& link, int& n);
bool addNode_Tail(LinkHead*& link, int& n);
bool inesrtNode(LinkHead*& link, int& i, int& n);
bool deleteNode(LinkHead*& link, int& i);
void destroyDoubleLink(LinkHead*& link);
void printDoubleLink(LinkHead*& link);

#endif 