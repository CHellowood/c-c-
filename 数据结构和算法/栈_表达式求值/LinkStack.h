//#pragma once
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

//˫������
typedef struct _Link {
	int data;       //���������ı���
	char symbol;    //�������
	_Link* former;  //��һ�����
	_Link* naxt;    //��һ�����
}Link;

//��ʽջ
typedef struct _Stack {
	Link* top;      //ջ��(���һ�����)
	Link* tail;     //ջ��(ͷ���)
	int size;       //��ǰ������
}Stack;

bool emptyStack(Stack& stack);              //ջ�Ƿ�Ϊ��
bool initStack(Stack& stack);               //��ʼ��ջ
bool enterStack(Stack& stack, Link& link);  //��ջ
bool outStack(Stack& stack, Link& link);    //ջ����ջ
bool outStack(Stack& stack, Link* link);    //ָ������ջ
void destroyStack(Stack& stack);            //����ջ
void printStack(Stack& stack);              //��ӡջ����

#endif 