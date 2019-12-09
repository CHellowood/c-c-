//#pragma once
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

//双向链表
typedef struct _Link {
	int data;       //保存整数的变量
	char symbol;    //保存符号
	_Link* former;  //上一个结点
	_Link* naxt;    //下一个结点
}Link;

//链式栈
typedef struct _Stack {
	Link* top;      //栈顶(最后一个结点)
	Link* tail;     //栈底(头结点)
	int size;       //当前结点个数
}Stack;

bool emptyStack(Stack& stack);              //栈是否为空
bool initStack(Stack& stack);               //初始化栈
bool enterStack(Stack& stack, Link& link);  //入栈
bool outStack(Stack& stack, Link& link);    //栈顶出栈
bool outStack(Stack& stack, Link* link);    //指定结点出栈
void destroyStack(Stack& stack);            //销毁栈
void printStack(Stack& stack);              //打印栈数据

#endif 