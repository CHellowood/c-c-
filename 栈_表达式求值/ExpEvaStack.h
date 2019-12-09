//#pragma once
#ifndef _EXPEVASTACK_H_
#define _EXPEVASTACK_H_

/*********************************************************
*  ͷ�ļ�:  Calculation.h
*  cpp�ļ�: Calculation.cpp
*  ����:    �ַ����ֱ��ʽ��ֵ(֧�� ��(+)��(-)��(*)��(/))(��ջʵ��)
**********************************************************/

#include <iostream>
#include "LinkStack.h"


using namespace std;

//�ַ�����ת����(����(0-9))
int char_turn_int(char& ch);

//�ӿ���̨�����ַ����ֱ��ʽ,Ȼ���ַ�����ת���������浽stack.data��,��������浽stack.symbol��
//����̨�����ԵȺ�(=)��β
void input(Stack& stack);

//�ѿ���̨����ĳ���_str[]�������ַ����ֱ��ʽ,_str[]�����ԵȺ�(=)��β,����ͬ��
void input(Stack& stack, char _str[]);

//������,���ȼ��� ��(*)��(/)
void result(Stack& stack);


#endif 
