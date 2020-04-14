//#pragma once

#ifndef _SPRITE_STONE_H_
#define _SPRITE_STONE_H_

#include <iostream>
#include <string>

//初级灵石和中级灵石的兑换比例
#define PRIMARY_MIDDLE   10

//中级灵石和高级灵石的兑换比例
#define MIDDLE_ADVANCED 10

#define LEVEL_KEY "level"
#define COUNT_KEY 1


//typedef enum {
//	PRIMARY, //初级灵石
//	MIDDLE,  //中级灵石
//	ADVANCED //高级灵石
//}LEVEL;

enum class SpriteStoneLevel {
	PRIMARY, //初级灵石
	MIDDLE,  //中级灵石
	ADVANCED //高级灵石
};

//灵石类
class SpriteStone
{
public:
	//默认为初级灵石
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
	SpriteStoneLevel level;//灵石等级
	int count; //灵石数量	
};

std::ostream& operator<<(std::ostream& os, const SpriteStone& stone);

#endif 