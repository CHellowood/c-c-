//#pragma once
#ifndef _CYCLELINK_H_
#define _CYCLELINK_H_

typedef struct CycleLink {
	int data;
	CycleLink* naxt;
}LinkHead, LinkList;

bool initCycleLink(LinkHead*& link);             //��ʼ��ѭ������
bool addNode_Head(LinkHead*& link, int& n);      //������ͷ����ӽ��
bool addNode_Tail(LinkHead*& link, int& n);      //������β����ӽ��
bool insertNode(LinkHead*& link, int& i, int& n);//������
bool deleteNode(LinkHead*& link, int& i);        //ɾ�����
void destroyCycleLink(LinkHead*& link);          //����ѭ������
void printCycleLink(LinkHead*& link);            //��ӡѭ������

#endif 