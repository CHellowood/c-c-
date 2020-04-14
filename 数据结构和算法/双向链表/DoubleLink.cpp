#include <iostream>
#include "DoubleLink.h"

using namespace std;

bool initDoubleLink(LinkHead*& link) {
	link = new LinkHead;
	if (!link) return false;

	link->data = -1;
	link->former = NULL;
	link->naxt = NULL;

	return true;
}

bool addNode_Head(LinkHead*& link, int& n) {
	if (!link) return false;

	LinkList* p = NULL;
	
	p = new LinkList;
	if (!p) return false;

	p->data = n;

	//ͷ������һ����Ϊ��
	if (link->naxt) link->naxt->former = p;//ͷ������һ��������һ���������½��
	
	p->former = link;                      //�½�����һ��������ͷ���
	p->naxt = link->naxt;                  //�½�����һ��������ͷ�����һ�����
	link->naxt = p;                        //ͷ������һ���������½��

	return true;
}

bool addNode_Tail(LinkHead*& link, int& n) {
	if (!link) return false;

	LinkList* p = NULL, *t = NULL;
	p = link;

	while (p->naxt) p = p->naxt;

	t = new LinkList;
	if (!t) return false;

	t->data = n;
	t->former = p;
	t->naxt = p->naxt;
	p->naxt = t;

	return true;
}

bool inesrtNode(LinkHead*& link, int& i, int& n) {
	if (!link || !link->naxt || i < 1) return false;

	LinkList* p = NULL, *t = NULL;
	int j = 1;
	
	p = link->naxt;
	while (p && j++ < i) p = p->naxt;

	if (!p)	return false;

	t = new LinkList;
	if (!t) return false;

	t->data = n;
	
	t->former = p->former;
	t->naxt = p;
	if (p->former)p->former->naxt = t;
	p->former = t;

	return true;
}

bool deleteNode(LinkHead*& link, int& i) {
	if (!link || i < 1) return false;

	LinkList* p = NULL;
	int j = 1;
	p = link->naxt;

	while (p && j++ < i) p = p->naxt;

	if (!p) return false;

	p->former->naxt = p->naxt;
	if (p->naxt) p->naxt->former = p->former;

	return true;
}

void destroyDoubleLink(LinkHead*& link) {
	if (!link) {
		cout << "����������!" << endl;
		return;
	}

	LinkList* p = NULL;
	p = link;

	while (p) {
		link = link->naxt;
		delete p;
		p = link;
	}
}

void printDoubleLink(LinkHead*& link) {
	if (!link) {
		cout << "˫������Ϊ��!" << endl;
		return;
	}

	LinkList* p = NULL;
	p = link;

	cout << endl;
	while (p->naxt) {
		cout << p->naxt->data << "\t";
		p = p->naxt;
	}
	
	cout << endl << "�������:" << endl;

	while (p != link) {
		cout << p->data << "\t";
		p = p->former;
	}
	cout << endl;
}