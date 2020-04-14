#pragma once
#ifndef MAP_H
#define MAP_H

#include "resource.h"
#include "Role.h"
#include "Box.h"
#include "Keypad.h"
#include <graphics.h>

template <typename T = void>
class Map
{
public:
	Map(int* map = nullptr, int length = 0, int width = 0,
		bool role = false, bool box = false, bool keypad = false);
	~Map();

	//显示地图
	void display();

	//显示地图上的指定位置
	void display(Pos& pos);

	Input input();//输入
	void move();  //移动

	bool isInMap(MOUSEMSG& m);//鼠标是否在地图上
	bool press(MOUSEMSG& m);  //鼠标是否按下

	Pos getPos(MOUSEMSG& m);//鼠标按下时获取鼠标在地图上的坐标

private:
	int* map;   //地图
	int length;  //长度
	int width;   //宽度
	Role<>* prole;
	Box<>* pbox;
	Keypad<>* pkeypad;
	static Pos mapPos;//鼠标上一次在地图上按下时获取到的鼠标的坐标

	void _Sleep(unsigned _time);
	Input keyboardInput();//键盘输入
	void mouseInput();    //鼠标输入
};

#endif 