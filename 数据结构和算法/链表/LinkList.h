//#pragma once
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <vector>

typedef struct LinkNode {
	int data;
	struct LinkNode* naxt;
}LinkHead, LinkList;

//LinkHead : ��ͷ: ��ͷ����������, ֻ������һ������ַ
//LinkLists : ����Ľ��

bool initNode(LinkHead* &link);                  //��ʼ������
bool addNodeHead(LinkHead* &link, int &n);       //��ͷ����ӽ��
bool addNodeTail(LinkHead* &link, int &n);       //��β����ӽ��
bool insertNode(LinkHead* &link, int &i, int &n);//������
bool searchNode(LinkHead* &link, int &i);        //���ݽ��λ�ò��ҽ�㲢�ѽ�����ݴ�ӡ����
bool searchNode(LinkHead* &link, int &i, int &n);//���ݽ��λ�ò��ҽ�㲢�Ѹý������ݷ��ظ� n
void searchData(LinkHead* &link, int &n);        //���ݽ�����ݲ��ҽ�㲢�ѽ���λ�ú����ݴ�ӡ����
bool deleteNode(LinkHead* &link, int &i);        //ɾ�����
void destroyLinkNode(LinkHead* &link);           //��������
void printNode(LinkHead* &link);                 //��ӡ����

#endif 