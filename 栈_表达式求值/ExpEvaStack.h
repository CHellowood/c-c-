//#pragma once
#ifndef _EXPEVASTACK_H_
#define _EXPEVASTACK_H_

/*********************************************************
*  头文件:  Calculation.h
*  cpp文件: Calculation.cpp
*  功能:    字符数字表达式求值(支持 加(+)减(-)乘(*)除(/))(用栈实现)
**********************************************************/

#include <iostream>
#include "LinkStack.h"


using namespace std;

//字符数字转整数(正数(0-9))
int char_turn_int(char& ch);

//从控制台输入字符数字表达式,然后字符数字转成整数保存到stack.data里,运算符保存到stack.symbol里
//控制台输入以等号(=)结尾
void input(Stack& stack);

//把控制台输入改成用_str[]来接收字符数字表达式,_str[]不用以等号(=)结尾,其余同上
void input(Stack& stack, char _str[]);

//计算结果,优先计算 乘(*)除(/)
void result(Stack& stack);


#endif 
