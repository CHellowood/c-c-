#pragma once
#ifndef ROLE_H
#define ROLE_H

#include "resource.h"
#include <graphics.h>

template <typename T = void>
class Role //��ɫ/����
{
public:
	//Role(const char* imageName, int imageSize = 0, int x = 0, int y = 0);
	Role(ROLE role = ROLE::Tom);

	void display(); //��ʾͼƬ

	Pos& getPos();
	ROLE& getRole();

private:
	ROLE role;   //����ͼƬ�ı���
	Pos pos;     //����
	//int imageSize; //ͼƬ��С
	//int x; //x������(��λ: imageSize)
	//int y; //y������(��λ: imageSize)


	
};

#endif 