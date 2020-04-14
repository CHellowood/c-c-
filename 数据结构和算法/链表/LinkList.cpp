#include <iostream>
#include "LinkList.h"

using namespace std;

//��ʼ������
bool initNode(LinkHead* &link) {
	link = new LinkList;
	if (!link) return false;
	link->naxt = NULL;

	return true;
}

//��ͷ����ӽ��
bool addNodeHead(LinkHead* &link, int &n) {
	if (!link) return false;

	LinkList* naxt = NULL;
	naxt = new LinkList;

	naxt->data = n;
	naxt->naxt = link->naxt;
	link->naxt = naxt;

	return true;
}

//��β����ӽ��
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

//������
bool insertNode(LinkHead* &link, int &i, int &n) {
	if (!link) return false;
	
	int j = 0;
	LinkList* p = NULL, *l = NULL;
	p = link;
	
	while (p && j < i - 1) {//Ѱ��Ҫ����λ�õĽ�����һ�����
		p = p->naxt;
		j++;
	}
	if (!p || j > i - 1) return false;

	l = new LinkList;
	l->naxt = p->naxt;//l����һ�����ָ�� p����һ�����
	l->data = n;      
	p->naxt = l;      //p����һ�����ָ�� l

	return true;
}

//���ݽ��λ�ò��ҽ�㲢�ѽ�����ݴ�ӡ����
bool searchNode(LinkHead* &link, int &i) {
	if (!link || !link->naxt) return false;

	int j = 1;
	LinkList* p = NULL;
	p = link->naxt;
	while (p && j < i) {//Ѱ�ҵ�i�����
		p = p->naxt;
		j++;
	}
	if (!p || j > i) return false;
	cout << "��" << j << "����������: " << p->data << endl;

	return true;
}

//���ݽ��λ�ò��ҽ�㲢�Ѹý������ݷ��ظ� n
bool searchNode(LinkHead* &link, int &i, int &n) {
	if (!link || !link->naxt) return false;

	int j = 1;
	LinkList* p = NULL;
	p = link;
	while (p && j < i) {//Ѱ�ҵ�i�����
		p = p->naxt;
		j++;
	}
	if (!p || j > i) return false;
	n = p->data;

	return true;
}

void searchData(LinkHead*& link, int& n) {
	if (!link || !link->naxt) {
		cout << "�������ڻ�����Ϊ��!" << endl;
		return;
    }

	LinkList* p = NULL;
	int i = 1;         //��¼��ǰ����ǵڼ������
	int j = 0;         //������ݵ���n�Ľ�����

	p = link->naxt;    //ͷ���û������ֱ��ָ����һ�����

	while (p) {
		if (p->data == n) {
			cout << "��" << i << "�����\t����:" << p->data << endl;
			j++;
		}

		p = p->naxt;
		i++;
	}
	
	cout << "����Ϊ" << n << "�Ľ����: " << j << "��" << endl;
}

//ɾ�����
bool deleteNode(LinkHead* &link, int &i) {
	if (!link || !link->naxt) return false;

	int j = 0;
	LinkList *p = NULL, *l = NULL;
	p = link;

	while (p && j < i - 1) {//�ҳ�Ҫɾ���Ľ�����һ�����
		p = p->naxt;
		j++;
	}
	if (!p || j > i - 1 || !p->naxt) return false;

	l = p->naxt;      //lָ�� p����һ�����
	p->naxt = l->naxt;//p����һ�����ָ�� l����һ�����
	delete l;         //ɾ����� l

	return true;
}

//��������
void destroyLinkNode(LinkHead*& link) {
	if (!link) return;

	LinkList* p = NULL;
	p = link;

	while (p) {
		link = link->naxt;//link ָ����һ�����
		delete p;         //���ٵ�ǰ���
		p = link;         
	}
}

//��ӡ����
void printNode(LinkHead* &link) {
	if (!link->naxt) {
		cout << "����Ϊ��!" << endl;
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
