#pragma once
#ifndef BOX_H
#define BOX_H

#include <graphics.h>
#include "resource.h"

template <typename T = void>
class Box
{
public:
	Box();
	~Box();

	Box& operator=(const Box& box);

	void display();

	static int getNum();

	Pos& getPos();
	BOX& getBox();

private:
	BOX box;
	Pos pos;
	static int num; //��ǰ��������
	int id;
	//int x;
	//int y;
};

#endif 