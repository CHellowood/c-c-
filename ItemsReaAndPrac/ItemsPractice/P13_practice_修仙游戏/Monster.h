#pragma once

#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <string>
//#include "SpriteStone.h"

class SpriteStone; //��ʯ��

enum class MonsterRace {//��������
	//ORC,       //����
	//DENOM,     //��ħ��
	//GHOST,     //����
	EVILKIND,  //����
	RACE_COUNT //������
};

enum class MonsterLevel {//����ȼ�
	LV1,
	LV2,
	LV3,
	LV4,
	LV5,
	LV6,
	LV7,
	LV8,
	LV9,
	LEVEL_COUNT //�ȼ���
};

class Monster // ������
{
public:	
	Monster(std::string kind,
		MonsterRace race = MonsterRace::EVILKIND,
		MonsterLevel level = MonsterLevel::LV1);

	friend std::ostream& operator<<(std::ostream& os,
		                            const Monster monster);
	
	std::string race_str() const;
	std::string level_str() const;

	//��ֵ�����ݹ���ȼ���ȡ��Ӧ�ļ�ֵ
	SpriteStone valueList() const;
	SpriteStone valueList();

	bool operator==(const Monster& monster) const;

	//���޵�ս��ֵ
	int power() const;

private:
	MonsterRace  race;  //���� 
	std::string  kind;  //����
	MonsterLevel level; //�ȼ�
	//SpriteStone  value; //��ֵ

	////��ֵ�����ݹ���ȼ���ȡ��Ӧ�ļ�ֵ
	//SpriteStone valueList();
};

std::ostream& operator<<(std::ostream& os, const Monster monster);

#endif 