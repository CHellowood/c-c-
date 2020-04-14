#pragma once
#ifndef ROLE_H
#define ROLE_H

#include "resource.h"
#include <graphics.h>

template <typename T = void>
class Role //角色/人物
{
public:
	//Role(const char* imageName, int imageSize = 0, int x = 0, int y = 0);
	Role(ROLE role = ROLE::Tom);

	void display(); //显示图片

	Pos& getPos();
	ROLE& getRole();

private:
	ROLE role;   //保存图片的变量
	Pos pos;     //坐标
	//int imageSize; //图片大小
	//int x; //x轴坐标(单位: imageSize)
	//int y; //y轴坐标(单位: imageSize)


	
};

#endif 