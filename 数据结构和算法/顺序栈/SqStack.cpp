#include "SqStack.h"
#include <iostream>

using namespace std;

//栈是否为空
bool emptyStack(SqStack& stack) {
	if (stack.tail && stack.tail == stack.top) {
		return true;
	}
	return false;
}

//栈是否为满
bool fullStack(SqStack& stack) {
	if (stack.tail && (stack.top - stack.tail) == STACK_SIZE) {
		return true;
	}
	return false;
}

//初始化顺序栈
bool initStack(SqStack& stack) {
	stack.tail = new stack_type[STACK_SIZE];
	if (!stack.tail) {
		cout << "initStack:stack.tail申请内存失败!" << endl;
		return false;
	}

	stack.top = stack.tail;
	return true;
}

//入栈
bool enterStack(SqStack& stack, stack_type& data) {
	if (!stack.tail) {
		cout << "enterStack:stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (fullStack(stack)) {
		cout << "enterStack:stack.tail已满(栈已满)!" << endl;
		return false;
	}

	*(stack.top++) = data;
	return true;
}

//出栈
bool outStack(SqStack& stack, stack_type& ret) {
	if (!stack.tail) {
		cout << "outStack:stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack:stack.tail为空(栈为空)!" << endl;
		return false;
	}

	ret = *(--stack.top);
	return true;
}

//获取栈顶元素
bool getStackTop(SqStack& stack, stack_type& ret) {
	if (!stack.tail) {
		cout << "getStackTop:stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "getStackTop:stack.tail为空(栈为空)!" << endl;
		return false;
	}

	ret = *(stack.top - 1);
	return true;
}

void destroyStack(SqStack& stack) {
	if (!stack.tail) {
		cout << "destroyStack:stack.tail不存在(栈不存在)!" << endl;
		return;
	}

	delete[] stack.tail;
	stack.tail = NULL;
	stack.top = NULL;
}

void printStack(SqStack& stack) {
	if (!stack.tail) {
		cout << "printStack:stack.tail不存在(栈不存在)!" << endl;
		return;
	}
	else if (emptyStack(stack)) {
		cout << "printStack:stack.tail为空(栈为空)!" << endl;
		return;
	}

	for (int i = 0; i < (stack.top - stack.tail); i++) {
		cout << " " << stack.tail[i];
	}
	cout << endl;
}