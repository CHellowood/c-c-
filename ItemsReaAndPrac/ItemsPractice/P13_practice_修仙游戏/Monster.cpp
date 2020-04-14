#include "Monster.h"
#include "SpriteStone.h"

//妖兽战力系数
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
	//case MonsterRace::ORC:   return "兽族";
	//case MonsterRace::DENOM: return "恶魔族";
	//case MonsterRace::GHOST: return "鬼族";
	case MonsterRace::EVILKIND:return "妖族";
	default:                   return "未知";
	}
}

std::string Monster::level_str() const
{
	switch (level) {
	case MonsterLevel::LV1: return "一级";
	case MonsterLevel::LV2: return "二级";
	case MonsterLevel::LV3: return "三级";
	case MonsterLevel::LV4: return "四级";
	case MonsterLevel::LV5: return "五级";
	case MonsterLevel::LV6: return "六级";
	case MonsterLevel::LV7: return "七级";
	case MonsterLevel::LV8: return "八级";
	case MonsterLevel::LV9: return "九级";
	default:                return "未知";
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

//妖兽战力值
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
	//os << "种族：" << monster.race_str()
	//	<< "\t种类：" << monster.kind
	//	<< "\t等级：" << monster.level_str();
	//	//<< "\t价值：" << monster.value;

	os << monster.race_str() << monster.level_str() << monster.kind;

	return os;
}
