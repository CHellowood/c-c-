//#pragma once
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include "backtracking.h"

typedef Pos LDataType;

typedef struct _Link {
	LDataType data;
	_Link* former;
	_Link* naxt;
}Link;

typedef struct _Stack {
	Link* top; //Õ»¶¥
	Link* tail;//Õ»µ×
	int size;  //Õ»´óÐ¡
}Stack;

bool initStack(Stack& stack);
bool enterStack(Stack& stack, Link* node);
bool outStack(Stack& stack);
//bool getStackTop(Stack& stack, Link& ret);
void destroyStack(Stack& stack);

#endif 