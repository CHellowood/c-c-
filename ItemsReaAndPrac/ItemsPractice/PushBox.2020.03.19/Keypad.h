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
		const char* text = "更改地形", 
		const char* font = "微软雅黑", 
		COLORREF color = RGB(128, 128, 128));

	~Keypad();

	void display(int addcolor = 0);    //显示按键
	bool isInKeypad(MOUSEMSG& m); //鼠标是否在按键上
	bool pressKeypad(MOUSEMSG& m);//鼠标左键是否按下

	Pos getPos1();
	Pos getPos2();
private:
	//按键位置
	Pos pos1;
	Pos pos2;
	int textsize;//文字大小
	char* text;//文字
	char* font;//字体
	COLORREF color;//按键颜色
};

#endif 