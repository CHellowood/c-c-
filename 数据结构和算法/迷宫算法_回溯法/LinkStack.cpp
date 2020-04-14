#include "LinkStack.h"
#include <iostream>

using namespace std;

//栈是否为空
bool emptyStack(Stack& stack) {
	if (stack.tail && stack.tail == stack.top) {
		return true;
	}
	return false;
}

//初始化栈
bool initStack(Stack& stack) {
	stack.tail = new Link;
	if (!stack.tail) {
		cout << "initStack:stack.tail内存申请失败!" << endl;
		return false;
	}

	stack.tail->former = NULL;
	stack.tail->naxt = NULL;
	stack.top = stack.tail;
	stack.size = 0;
	
	return true;
}

//入栈
bool enterStack(Stack& stack, Link* node) {
	if (!stack.tail) {
		cout << "enterStack:stack.tail不存在(栈不存在)!" << endl;
		return false;
	}

	node->former = stack.top;
	node->naxt = stack.top->naxt;
	stack.top->naxt = node;
	stack.top = node;
	stack.size++;

	return true;
}

//出栈
bool outStack(Stack& stack) {
	if (!stack.tail) {
		cout << "outStack:stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack:stack.tail为空(栈为空)!" << endl;
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
//获取栈顶元素
bool getStackTop(Stack& stack, Link& ret) {
	if (!stack.tail) {
		cout << "getStackTop:stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "getStackTop:stack.tail为空(栈为空)!" << endl;
		return false;
	}

	ret = *(stack.top);

	return true;
}
*/

//销毁栈
void destroyStack(Stack& stack) {
	if (!stack.tail) {
		cout << "destroyStack:stack.tail不存在(栈不存在)!" << endl;
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

