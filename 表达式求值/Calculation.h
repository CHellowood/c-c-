//#pragma once
#ifndef _CALCULATION_H_
#define _CALCULATION_H_

/*********************************************************
*  ͷ�ļ�:  Calculation.h
*  cpp�ļ�: Calculation.cpp
*  ����:    �ַ����ֱ��ʽ��ֵ(֧�� ��(+)��(-)��(*)��(/))(��vectorʵ��)
**********************************************************/

#include <iostream>
#include <vector>

using namespace std;

//�ַ�����ת����(����(0-9))
int char_turn_int(char& ch); 

//�ӿ���̨�����ַ����ֱ��ʽ,Ȼ���ַ�����ת���������浽number��,��������浽str��
//����̨�����ԵȺ�(=)��β
void input(vector<int>& number, vector<char>& str);

//�ѿ���̨����ĳ���_str[]�������ַ����ֱ��ʽ,_str[]�����ԵȺ�(=)��β,����ͬ��
void input(vector<int>& number, vector<char>& str, char _str[]);

//������,��ʽ: number[i] str[i] number[i+1],
//����number[i]=2,str[i]='+',number[i+1]=5,�������2+5   
//���ȼ��� ��(*)��(/)
void result(vector<int>& number, vector<char>& str);


#endif 