#include "LinkStack.h"
#include <iostream>

using namespace  std;

//栈是否为空
bool emptyStack(Stack& stack) {
	if (stack.tail && stack.top == stack.tail) {
		return true;
	}
	return false;
}

//初始化栈
bool initStack(Stack& stack) {
	stack.tail = new Link;
	if (!stack.tail) {
		cout << "initStack: stack.tail初始化失败(栈初始化失败)!" << endl;
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

//入栈
bool enterStack(Stack& stack, Link& link) {
	if (!stack.tail) {
		cout << "enterStack: stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	
	link.former = stack.top;
	link.naxt = stack.top->naxt;
	stack.top->naxt = &link;
	stack.top = &link;
	stack.size++;

	return true;
}

//栈顶出栈
bool outStack(Stack& stack, Link& link) {
	if (!stack.tail) {
		cout << "outStack: stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack: stack.tail为空(栈为空)!" << endl;
		return false;
	}
	Link* p = stack.top;
	link = *p;
	stack.top = p->former;
	delete p;
	stack.size--;

	return true;
}

//指定结点出栈
bool outStack(Stack& stack, Link* link) {
	if (!stack.tail) {
		cout << "outStack: stack.tail不存在(栈不存在)!" << endl;
		return false;
	}
	else if (emptyStack(stack)) {
		cout << "outStack: stack.tail为空(栈为空)!" << endl;
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

//销毁栈
void destroyStack(Stack& stack) {
	if (!stack.tail) {
		cout << "destroyStack: stack.tail不存在(栈不存在)!" << endl;
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
		cout << "printStack: stack.tail不存在(栈不存在)!" << endl;
		return;
	}
	else if (emptyStack(stack)) {
		cout << "printStack: stack.tail为空(栈为空)!" << endl;
		return;
	}

	Link* p = stack.tail->naxt;
	while (p) {
		cout << " " << p->data << " " << p->symbol;

		p = p->naxt;
	}
}