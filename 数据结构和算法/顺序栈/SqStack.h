//#pragma once
#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#define STACK_SIZE 10

typedef int stack_type;

typedef struct _SqStack {
	stack_type* top;
	stack_type* tail;
}SqStack;

bool initStack(SqStack& stack);
bool enterStack(SqStack& stack, stack_type& data);
bool outStack(SqStack& stack, stack_type& ret);
bool getStackTop(SqStack& stack, stack_type& ret);
void destroyStack(SqStack& stack);
void printStack(SqStack& stack);

#endif 