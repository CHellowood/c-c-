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

	//��ʾ��ͼ
	void display();

	//��ʾ��ͼ�ϵ�ָ��λ��
	void display(Pos& pos);

	Input input();//����
	void move();  //�ƶ�

	bool isInMap(MOUSEMSG& m);//����Ƿ��ڵ�ͼ��
	bool press(MOUSEMSG& m);  //����Ƿ���

	Pos getPos(MOUSEMSG& m);//��갴��ʱ��ȡ����ڵ�ͼ�ϵ�����

private:
	int* map;   //��ͼ
	int length;  //����
	int width;   //���
	Role<>* prole;
	Box<>* pbox;
	Keypad<>* pkeypad;
	static Pos mapPos;//�����һ���ڵ�ͼ�ϰ���ʱ��ȡ������������

	void _Sleep(unsigned _time);
	Input keyboardInput();//��������
	void mouseInput();    //�������
};

#endif 