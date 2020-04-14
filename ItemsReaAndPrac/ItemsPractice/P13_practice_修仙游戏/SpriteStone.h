//#pragma once

#ifndef _SPRITE_STONE_H_
#define _SPRITE_STONE_H_

#include <iostream>
#include <string>

//������ʯ���м���ʯ�Ķһ�����
#define PRIMARY_MIDDLE   10

//�м���ʯ�͸߼���ʯ�Ķһ�����
#define MIDDLE_ADVANCED 10

#define LEVEL_KEY "level"
#define COUNT_KEY 1


//typedef enum {
//	PRIMARY, //������ʯ
//	MIDDLE,  //�м���ʯ
//	ADVANCED //�߼���ʯ
//}LEVEL;

enum class SpriteStoneLevel {
	PRIMARY, //������ʯ
	MIDDLE,  //�м���ʯ
	ADVANCED //�߼���ʯ
};

//��ʯ��
class SpriteStone
{
public:
	//Ĭ��Ϊ������ʯ
	SpriteStone(int count = 0, 
		SpriteStoneLevel level = SpriteStoneLevel::PRIMARY);

	SpriteStone(const SpriteStone& stone);

	SpriteStone& operator+(SpriteStone& stone);
	SpriteStone& operator+(int count);

	SpriteStone& operator-(SpriteStone& stone);
	SpriteStone& operator-(int count);

	std::string operator[](std::string KEY) const;
	int         operator[](int KEY) const;

	bool        operator>=(const SpriteStone& stone) const;
	
	bool        operator=(const SpriteStoneLevel level);
	//const SpriteStone& operator=(const SpriteStone& stone);
	//SpriteStone& operator=(const SpriteStone& stone);

	friend std::ostream& operator<<(std::ostream& os, const SpriteStone& stone);

private:
	SpriteStoneLevel level;//��ʯ�ȼ�
	int count; //��ʯ����	
};

std::ostream& operator<<(std::ostream& os, const SpriteStone& stone);

#endif 