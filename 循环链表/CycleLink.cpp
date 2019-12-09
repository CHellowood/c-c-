#include <iostream>
#include "CycleLink.h"

using namespace std;

//初始化循环链表
bool initCycleLink(LinkHead*& link) {
	link = new LinkHead;
	if (!link) return false;

	link->data = -1;
	link->naxt = link;

	return true;
}

//在链表头部添加结点
bool addNode_Head(LinkHead*& link, int& n) {
	if (!link) return false;

	LinkList* p = NULL;

	p = new LinkList;
	if (!p) return false;

	p->data = n;
	p->naxt = link->naxt;
	link->naxt = p;

	return true;
}

//在链表尾部添加结点
bool addNode_Tail(LinkHead*& link, int& n) {
	if (!link) return false;

	LinkList *p = NULL, *t = NULL;
	t = link;

	while (t->naxt != link) t = t->naxt;

	p = new LinkList;
	if (!p) return false;

	p->data = n;
	p->naxt = t->naxt;
	t->naxt = p;

	return true;
}


//插入结点
bool insertNode(LinkHead*& link, int& i, int& n) {
	if (!link) return false;

	LinkList* p = NULL, * t = NULL;
	int j = 0;
/*
	if (i == 1) {
		p = new LinkList;
		if (!p) return false;

		p->data = n;
		p->naxt = link->naxt;
		link->naxt = p;

		return true;
	}
*/
	t = link;

	while (t->naxt != link && j < i - 1) {
		t = t->naxt;
		j++;
	}
	//if (t == link || j > i - 1 || j < i - 1) return false;
	if (j != i - 1) return false;

	p = new LinkList;
	if (!p) return false;

	p->data = n;
	p->naxt = t->naxt;
	t->naxt = p;

	return true;
}

//删除结点
bool deleteNode(LinkHead*& link, int& i) {
	if (!link) return false;

	LinkList* p = NULL, *t = NULL;
	int j = 0;
	t = link;

	while (t->naxt != link && j < i - 1) {
		t = t->naxt;
		j++;
	}
	if (t->naxt == link || j > i - 1) return false;

	p = t->naxt;
	t->naxt = p->naxt;
	delete p;

	return true;
}

//销毁循环链表
void destroyCycleLink(LinkHead*& link) {
	if (!link) return;
	
	LinkList* p = NULL;
	p = link;

	while (p->naxt != link) p = p->naxt;
	p->naxt = NULL;

	p = link;
	while (p) {
		 
		link = link->naxt;
		delete p;
		p = link;
	}
}

//打印循环链表
void printCycleLink(LinkHead*& link) {
	if (!link || link->naxt == link) {
		cout << "循环链表为空!" << endl;
		return;
	}

	LinkList* p = NULL;
	p = link->naxt;
	while (p != link) {
		cout << p->data << "\t";
		p = p->naxt;
	}
	cout << endl;
}