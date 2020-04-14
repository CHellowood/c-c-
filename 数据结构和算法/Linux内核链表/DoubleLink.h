//#pragma once

#ifndef _DOUBLELINK_H_
#define _DOUBLELINK_H_

//����ָ����ṹ��
typedef struct DoubleLink_Pointer {
	DoubleLink_Pointer* former;
	DoubleLink_Pointer* naxt;
}DLink_Pointer;

typedef struct DoubleLinkList{
	int data;             //������
	DLink_Pointer pointer;//ָ����
}DLink;

DLink* CalculationAddress(DLink_Pointer*& node);                         //���ݽ��ָ����ĵ�ַ��������׵�ַ
void initDLink(DLink_Pointer& nodeHead);                                 //��ʼ��˫������
bool addNode_Head(DLink_Pointer& nodeHead, DLink_Pointer& newNode);      //��ͷ����ӽ��
bool addNode_Tail(DLink_Pointer& nodeHead, DLink_Pointer& newNode);      //��β����ӽ��
bool insertNode(DLink_Pointer& nodeHead, int& i, DLink_Pointer& newNode);//�������в�����
bool deleteNode(DLink_Pointer& nodeHead, int& i);                        //��������ɾ�����
void destroyDLink(DLink_Pointer& nodeHead);                              //��������
void printDLink(DLink_Pointer& nodeHead);                                //��ӡ����

#endif 