#include "LinkStack.h"
#include <iostream>

using namespace  std;

//ջ�Ƿ�Ϊ��
bool emptyStack(Stack& stack) {
	if (stack.tail && stack.top == stack.tail) {
		return true;
	}
	return false;
}

//��ʼ��ջ
bool initStack(Stack& stack) {
	stack.tail = new Link;
	if (!stack.tail) {
		cout << "initStack: stack.tail��ʼ��ʧ��(ջ��ʼ��ʧ��)!" << endl;
		return false;
	}

	stack.tail->data   = -1;
	stack.tail->symbol = '?';
	stack.tail->former = NULL;
	stack.tail->naxt   = NULL;
	stack.top = stack.tail;
	stack.size = 0;

	return true;
}

//��ջ
bool enterStack(Stack& stack, Link& link) {
	if (!stack.tail) {
		cout << "enterStack: stack.tail������(ջ������)!" << endl;
		return false;
	}
	
	link.former = stack.top;
	link.naxt = stack.top->naxt;
	stack.top->naxt = &link;
	stack.top = &link;
	stack.size++;

	return true;
}

//ջ����ջ
bool outStack(Stack& stack, Link& link) {
	if (!stack.tail) {
		cout << "outStack: stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack: stack.tailΪ��(ջΪ��)!" << endl;
		return false;
	}
	Link* p = stack.top;
	link = *p;
	stack.top = p->former;
	delete p;
	stack.size--;

	return true;
}

//ָ������ջ
bool outStack(Stack& stack, Link* link) {
	if (!stack.tail) {
		cout << "outStack: stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack: stack.tailΪ��(ջΪ��)!" << endl;
		return false;
	}
	//Link* p = stack.tail;

	//while (p && p != link) p = p->naxt;

	link->former->naxt = link->naxt;
	if (link->naxt) link->naxt->former = link->former;

	if (link == stack.top)stack.top = link->former;
	delete link;
	stack.size--;

	return true;
}

//����ջ
void destroyStack(Stack& stack) {
	if (!stack.tail) {
		cout << "destroyStack: stack.tail������(ջ������)!" << endl;
		return;
	}

	Link* p = stack.tail;
	while (p) {
		stack.tail = p->naxt;
		delete p;
		p = stack.tail;
	}

	stack.top = NULL;
	stack.tail = NULL;
	stack.size = 0;
}

void printStack(Stack& stack) {
	if (!stack.tail) {
		cout << "printStack: stack.tail������(ջ������)!" << endl;
		return;
	}
	else if (emptyStack(stack)) {
		cout << "printStack: stack.tailΪ��(ջΪ��)!" << endl;
		return;
	}

	Link* p = stack.tail->naxt;
	while (p) {
		cout << " " << p->data << " " << p->symbol;

		p = p->naxt;
	}
}