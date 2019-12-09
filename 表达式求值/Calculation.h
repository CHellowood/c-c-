//#pragma once
#ifndef _CALCULATION_H_
#define _CALCULATION_H_

/*********************************************************
*  头文件:  Calculation.h
*  cpp文件: Calculation.cpp
*  功能:    字符数字表达式求值(支持 加(+)减(-)乘(*)除(/))(用vector实现)
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

//字符数字转整数(正数(0-9))
int char_turn_int(char& ch); 

//从控制台输入字符数字表达式,然后字符数字转成整数保存到number里,运算符保存到str里
//控制台输入以等号(=)结尾
void input(vector<int>& number, vector<char>& str);

//把控制台输入改成用_str[]来接收字符数字表达式,_str[]不用以等号(=)结尾,其余同上
void input(vector<int>& number, vector<char>& str, char _str[]);

//计算结果,公式: number[i] str[i] number[i+1],
//假设number[i]=2,str[i]='+',number[i+1]=5,结果就是2+5   
//优先计算 乘(*)除(/)
void result(vector<int>& number, vector<char>& str);


#endif 