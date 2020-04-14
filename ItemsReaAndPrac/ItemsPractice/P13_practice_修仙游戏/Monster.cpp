#include "Monster.h"
#include "SpriteStone.h"

//����ս��ϵ��
#define MONSTER_POWER_FACTOR 1000

Monster::Monster(std::string kind, MonsterRace race, 
	MonsterLevel level)
{
	this->race  = race;
	this->kind  = kind;
	this->level = level;
	//this->value = valueList();
}

std::string Monster::race_str() const
{
	switch (race) {
	//case MonsterRace::ORC:   return "����";
	//case MonsterRace::DENOM: return "��ħ��";
	//case MonsterRace::GHOST: return "����";
	case MonsterRace::EVILKIND:return "����";
	default:                   return "δ֪";
	}
}

std::string Monster::level_str() const
{
	switch (level) {
	case MonsterLevel::LV1: return "һ��";
	case MonsterLevel::LV2: return "����";
	case MonsterLevel::LV3: return "����";
	case MonsterLevel::LV4: return "�ļ�";
	case MonsterLevel::LV5: return "�弶";
	case MonsterLevel::LV6: return "����";
	case MonsterLevel::LV7: return "�߼�";
	case MonsterLevel::LV8: return "�˼�";
	case MonsterLevel::LV9: return "�ż�";
	default:                return "δ֪";
	}
}

bool Monster::operator==(const Monster& monster) const
{
	if (this->race == monster.race
		&& this->kind == monster.kind
		&& this->level == monster.level) {
		return true;
	}
	return false;
}

//����ս��ֵ
int Monster::power() const
{
	int power = ((int)level + 1) * MONSTER_POWER_FACTOR;
	return power;
}

SpriteStone Monster::valueList() const
{
	switch (level) {
	case MonsterLevel::LV1: return SpriteStone(100);
	case MonsterLevel::LV2: return SpriteStone(200);
	case MonsterLevel::LV3: return SpriteStone(500);
	case MonsterLevel::LV4: return SpriteStone(1000);
	case MonsterLevel::LV5: return SpriteStone(2000);
	case MonsterLevel::LV6: return SpriteStone(5000);
	case MonsterLevel::LV7: return SpriteStone(10000);
	case MonsterLevel::LV8: return SpriteStone(20000);
	case MonsterLevel::LV9: return SpriteStone(100000);
	default:                return SpriteStone(0);
	}
}

SpriteStone Monster::valueList()
{
	switch (level) {
	case MonsterLevel::LV1: return SpriteStone(100);
	case MonsterLevel::LV2: return SpriteStone(200);
	case MonsterLevel::LV3: return SpriteStone(500);
	case MonsterLevel::LV4: return SpriteStone(1000);
	case MonsterLevel::LV5: return SpriteStone(2000);
	case MonsterLevel::LV6: return SpriteStone(5000);
	case MonsterLevel::LV7: return SpriteStone(10000);
	case MonsterLevel::LV8: return SpriteStone(20000);
	case MonsterLevel::LV9: return SpriteStone(100000);
	default:                return SpriteStone(0);
	}
}

std::ostream& operator<<(std::ostream& os, const Monster monster)
{
	//os << "���壺" << monster.race_str()
	//	<< "\t���ࣺ" << monster.kind
	//	<< "\t�ȼ���" << monster.level_str();
	//	//<< "\t��ֵ��" << monster.value;

	os << monster.race_str() << monster.level_str() << monster.kind;

	return os;
}
