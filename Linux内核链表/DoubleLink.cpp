#include <iostream>
#include "DoubleLink.h"

using namespace std;

DLink* CalculationAddress(DLink_Pointer*& node) {
	int offset = offsetof(DLink, pointer);
	DLink* ret = (DLink*)((size_t)node - offset);

	return ret;
}

void initDLink(DLink_Pointer& nodeHead) {
	nodeHead.former = NULL;
	nodeHead.naxt   = NULL;
}

bool addNode_Head(DLink_Pointer& nodeHead, DLink_Pointer& newNode) {
	newNode.former = &nodeHead;
	newNode.naxt = nodeHead.naxt;

	if (nodeHead.naxt) nodeHead.naxt->former = &newNode;
	nodeHead.naxt = &newNode;

	return true;
}

bool addNode_Tail(DLink_Pointer& nodeHead, DLink_Pointer& newNode) {
	DLink_Pointer* p = &nodeHead;

	while (p->naxt) p = p->naxt;

	newNode.former = p;
	newNode.naxt = p->naxt;
	p->naxt = &newNode;

	return true;
}

bool insertNode(DLink_Pointer& nodeHead, int& i, DLink_Pointer& newNode) {
	if (i < 1) return false;
	
	DLink_Pointer* p = &nodeHead;
	int j = 0;

	while (p && j < i) {
		p = p->naxt;
		j++;
	}

	if (!p) return false;

	newNode.former = p->former;
	newNode.naxt = p;
	p->former->naxt = &newNode;
	p->former = &newNode;

	return true;
}

bool deleteNode(DLink_Pointer& nodeHead, int& i) {
	if (i < 1) return false;

	DLink_Pointer* p = NULL;
	int j = 1;
	p = nodeHead.naxt;

	while (p && j < i) {
		p = p->naxt;
		j++;
	}
	if (!p) return false;

	if (p->naxt)p->naxt->former = p->former;
	p->former->naxt = p->naxt;
	
	auto* release = CalculationAddress(p);
	delete release;

	return true;
}

void destroyDLink(DLink_Pointer& nodeHead) {
	DLink_Pointer* p = &nodeHead, *naxt = NULL;

	while (p) {
		naxt = p->naxt;

		auto* release = CalculationAddress(p);
		delete release;

		p = naxt;
	}
}

void printDLink(DLink_Pointer& nodeHead) {
	DLink_Pointer* p = NULL;
	p = &nodeHead;
	while (p->naxt) {
		p = p->naxt;
		
		auto* print = CalculationAddress(p);
		cout << print->data << "    ";	
	}
	cout << endl;

	while (p != &nodeHead) {
		auto* print = CalculationAddress(p);
		cout << print->data << "    ";
		p = p->former;
	}
	cout << endl;
}