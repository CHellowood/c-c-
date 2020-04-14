#include "SqStack.h"
#include <iostream>

using namespace std;

//ջ�Ƿ�Ϊ��
bool emptyStack(SqStack& stack) {
	if (stack.tail && stack.tail == stack.top) {
		return true;
	}
	return false;
}

//ջ�Ƿ�Ϊ��
bool fullStack(SqStack& stack) {
	if (stack.tail && (stack.top - stack.tail) == STACK_SIZE) {
		return true;
	}
	return false;
}

//��ʼ��˳��ջ
bool initStack(SqStack& stack) {
	stack.tail = new stack_type[STACK_SIZE];
	if (!stack.tail) {
		cout << "initStack:stack.tail�����ڴ�ʧ��!" << endl;
		return false;
	}

	stack.top = stack.tail;
	return true;
}

//��ջ
bool enterStack(SqStack& stack, stack_type& data) {
	if (!stack.tail) {
		cout << "enterStack:stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (fullStack(stack)) {
		cout << "enterStack:stack.tail����(ջ����)!" << endl;
		return false;
	}

	*(stack.top++) = data;
	return true;
}

//��ջ
bool outStack(SqStack& stack, stack_type& ret) {
	if (!stack.tail) {
		cout << "outStack:stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack:stack.tailΪ��(ջΪ��)!" << endl;
		return false;
	}

	ret = *(--stack.top);
	return true;
}

//��ȡջ��Ԫ��
bool getStackTop(SqStack& stack, stack_type& ret) {
	if (!stack.tail) {
		cout << "getStackTop:stack.tail������(ջ������)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "getStackTop:stack.tailΪ��(ջΪ��)!" << endl;
		return false;
	}

	ret = *(stack.top - 1);
	return true;
}

void destroyStack(SqStack& stack) {
	if (!stack.tail) {
		cout << "destroyStack:stack.tail������(ջ������)!" << endl;
		return;
	}

	delete[] stack.tail;
	stack.tail = NULL;
	stack.top = NULL;
}

void printStack(SqStack& stack) {
	if (!stack.tail) {
		cout << "printStack:stack.tail������(ջ������)!" << endl;
		return;
	}
	else if (emptyStack(stack)) {
		cout << "printStack:stack.tailΪ��(ջΪ��)!" << endl;
		return;
	}

	for (int i = 0; i < (stack.top - stack.tail); i++) {
		cout << " " << stack.tail[i];
	}
	cout << endl;
}