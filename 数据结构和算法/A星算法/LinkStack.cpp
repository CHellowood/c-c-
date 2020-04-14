#include "LinkStack.h"
#include <iostream>

using namespace std;

//ջ�Ƿ�Ϊ��
bool emptyStack(Stack& stack) {
	if (stack.tail && stack.tail == stack.top) {
		return true;
	}
	return false;
}

//��ʼ��ջ
bool initStack(Stack& stack) {
	stack.tail = new Link;
	if (!stack.tail) {
		cout << "initStack:stack.tail�ڴ�����ʧ��!" << endl;
		return false;
	}

	stack.tail->former = NULL;
	stack.tail->naxt = NULL;
	stack.top = stack.tail;
	stack.size = 0;
	
	return true;
}

//��ջ
bool enterStack(Stack& stack, Link* node) {
	if (!stack.tail) {
		cout << "enterStack:stack.tail������(ջ������)!" << endl;
		return false;
	}

	node->former = stack.top;
	node->naxt = stack.top->naxt;
	stack.top->naxt = node;
	stack.top = node;
	stack.size++;

	return true;
}

//��ջ
bool outStack(Stack& stack) {
	if (!stack.tail) {
		cout << "outStack:stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack:stack.tailΪ��(ջΪ��)!" << endl;
		return false;
	}
	
	Link* p = stack.top;
	stack.top = p->former;
	stack.top->naxt = p->naxt;
	delete p;
	stack.size--;

	return true;
}

/*
//��ȡջ��Ԫ��
bool getStackTop(Stack& stack, Link& ret) {
	if (!stack.tail) {
		cout << "getStackTop:stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "getStackTop:stack.tailΪ��(ջΪ��)!" << endl;
		return false;
	}

	ret = *(stack.top);

	return true;
}
*/

//����ջ
void destroyStack(Stack& stack) {
	if (!stack.tail) {
		cout << "destroyStack:stack.tail������(ջ������)!" << endl;
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

