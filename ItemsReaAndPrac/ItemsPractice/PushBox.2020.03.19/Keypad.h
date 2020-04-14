#pragma once
#ifndef KEYPAD_H
#define KEYPAD_H

#include <graphics.h>
#include "resource.h"

template <typename T = void>
class Keypad
{
public:
	Keypad(Pos pos1 = keypadsPos[0], Pos pos2 = keypadsPos[1],
		int textsize = 25, 
		const char* text = "���ĵ���", 
		const char* font = "΢���ź�", 
		COLORREF color = RGB(128, 128, 128));

	~Keypad();

	void display(int addcolor = 0);    //��ʾ����
	bool isInKeypad(MOUSEMSG& m); //����Ƿ��ڰ�����
	bool pressKeypad(MOUSEMSG& m);//�������Ƿ���

	Pos getPos1();
	Pos getPos2();
private:
	//����λ��
	Pos pos1;
	Pos pos2;
	int textsize;//���ִ�С
	char* text;//����
	char* font;//����
	COLORREF color;//������ɫ
};

#endif 