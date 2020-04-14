#pragma once

#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <string>
//#include "SpriteStone.h"

class SpriteStone; //灵石类

enum class MonsterRace {//怪物种族
	//ORC,       //兽族
	//DENOM,     //恶魔族
	//GHOST,     //鬼族
	EVILKIND,  //妖族
	RACE_COUNT //种族数
};

enum class MonsterLevel {//怪物等级
	LV1,
	LV2,
	LV3,
	LV4,
	LV5,
	LV6,
	LV7,
	LV8,
	LV9,
	LEVEL_COUNT //等级数
};

class Monster // 怪物类
{
public:	
	Monster(std::string kind,
		MonsterRace race = MonsterRace::EVILKIND,
		MonsterLevel level = MonsterLevel::LV1);

	friend std::ostream& operator<<(std::ostream& os,
		                            const Monster monster);
	
	std::string race_str() const;
	std::string level_str() const;

	//价值表，根据怪物等级获取对应的价值
	SpriteStone valueList() const;
	SpriteStone valueList();

	bool operator==(const Monster& monster) const;

	//妖兽的战力值
	int power() const;

private:
	MonsterRace  race;  //种族 
	std::string  kind;  //种类
	MonsterLevel level; //等级
	//SpriteStone  value; //价值

	////价值表，根据怪物等级获取对应的价值
	//SpriteStone valueList();
};

std::ostream& operator<<(std::ostream& os, const Monster monster);

#endif 