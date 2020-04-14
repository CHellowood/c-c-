#include <iostream>
#include "LinkList.h"

using namespace std;

//初始化链表
bool initNode(LinkHead* &link) {
	link = new LinkList;
	if (!link) return false;
	link->naxt = NULL;

	return true;
}

//在头部添加结点
bool addNodeHead(LinkHead* &link, int &n) {
	if (!link) return false;

	LinkList* naxt = NULL;
	naxt = new LinkList;

	naxt->data = n;
	naxt->naxt = link->naxt;
	link->naxt = naxt;

	return true;
}

//在尾部添加结点
bool addNodeTail(LinkHead* &link, int &n) {
	if (!link) return false;

	LinkList* p = NULL, *l = NULL;
	p = link;
	while (p->naxt) p = p->naxt;

	l = new LinkList;
	l->data = n;
	l->naxt = NULL;
	p->naxt = l;
	
	return true;
}

//插入结点
bool insertNode(LinkHead* &link, int &i, int &n) {
	if (!link) return false;
	
	int j = 0;
	LinkList* p = NULL, *l = NULL;
	p = link;
	
	while (p && j < i - 1) {//寻找要插入位置的结点的上一个结点
		p = p->naxt;
		j++;
	}
	if (!p || j > i - 1) return false;

	l = new LinkList;
	l->naxt = p->naxt;//l的下一个结点指向 p的下一个结点
	l->data = n;      
	p->naxt = l;      //p的下一个结点指向 l

	return true;
}

//根据结点位置查找结点并把结点数据打印出来
bool searchNode(LinkHead* &link, int &i) {
	if (!link || !link->naxt) return false;

	int j = 1;
	LinkList* p = NULL;
	p = link->naxt;
	while (p && j < i) {//寻找第i个结点
		p = p->naxt;
		j++;
	}
	if (!p || j > i) return false;
	cout << "第" << j << "个结点的数据: " << p->data << endl;

	return true;
}

//根据结点位置查找结点并把该结点的数据返回给 n
bool searchNode(LinkHead* &link, int &i, int &n) {
	if (!link || !link->naxt) return false;

	int j = 1;
	LinkList* p = NULL;
	p = link;
	while (p && j < i) {//寻找第i个结点
		p = p->naxt;
		j++;
	}
	if (!p || j > i) return false;
	n = p->data;

	return true;
}

void searchData(LinkHead*& link, int& n) {
	if (!link || !link->naxt) {
		cout << "链表不存在或链表为空!" << endl;
		return;
    }

	LinkList* p = NULL;
	int i = 1;         //记录当前结点是第几个结点
	int j = 0;         //结点数据等于n的结点个数

	p = link->naxt;    //头结点没有数据直接指向下一个结点

	while (p) {
		if (p->data == n) {
			cout << "第" << i << "个结点\t数据:" << p->data << endl;
			j++;
		}

		p = p->naxt;
		i++;
	}
	
	cout << "数据为" << n << "的结点有: " << j << "个" << endl;
}

//删除结点
bool deleteNode(LinkHead* &link, int &i) {
	if (!link || !link->naxt) return false;

	int j = 0;
	LinkList *p = NULL, *l = NULL;
	p = link;

	while (p && j < i - 1) {//找出要删除的结点的上一个结点
		p = p->naxt;
		j++;
	}
	if (!p || j > i - 1 || !p->naxt) return false;

	l = p->naxt;      //l指向 p的下一个结点
	p->naxt = l->naxt;//p的下一个结点指向 l的下一个结点
	delete l;         //删除结点 l

	return true;
}

//销毁链表
void destroyLinkNode(LinkHead*& link) {
	if (!link) return;

	LinkList* p = NULL;
	p = link;

	while (p) {
		link = link->naxt;//link 指向下一个结点
		delete p;         //销毁当前结点
		p = link;         
	}
}

//打印链表
void printNode(LinkHead* &link) {
	if (!link->naxt) {
		cout << "链表为空!" << endl;
		return;
	}

	LinkList* p;
	p = link->naxt;

	while (p) {
		cout << p->data << "  ";
		p = p->naxt;
	}
	cout << endl;
}
