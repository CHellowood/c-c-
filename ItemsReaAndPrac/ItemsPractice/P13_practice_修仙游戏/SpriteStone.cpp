#include "SpriteStone.h"

SpriteStone::SpriteStone(int count, SpriteStoneLevel level)
{
	this->count = count;
	this->level = level;
}

SpriteStone::SpriteStone(const SpriteStone& stone)
{
	this->count = stone.count;
	this->level = stone.level;
}

//兑换灵石
bool SpriteStone::operator=(const SpriteStoneLevel level)
{
	if (this->level == level) {
		//std::cout << "无法兑换，您的灵石已经是" << (*this)[LEVEL_KEY] << "灵石了\n";
		return false;
	}

	switch (this->level) {
	case SpriteStoneLevel::PRIMARY:
		//初级灵石兑换中级灵石
		if (level == SpriteStoneLevel::MIDDLE 
			&& this->count >= PRIMARY_MIDDLE) {
			
			this->count /= PRIMARY_MIDDLE;
			break;		
		}
		//初级灵石兑换高级灵石
		else if (level == SpriteStoneLevel::ADVANCED 
			&& this->count >= (PRIMARY_MIDDLE * MIDDLE_ADVANCED)) {
			
			this->count /= (PRIMARY_MIDDLE * MIDDLE_ADVANCED);
			break;
		}
		else {
			std::cout << "您的" << (*this)[LEVEL_KEY] << "灵石不足！\n";
			return false;
		}
	case SpriteStoneLevel::MIDDLE:
		//中级灵石兑换初级灵石
		if (level == SpriteStoneLevel::PRIMARY) {
			this->count *= PRIMARY_MIDDLE;
			break;
		}
		//中级灵石兑换高级灵石
		else {
			if (this->count >= MIDDLE_ADVANCED) {
				this->count /= MIDDLE_ADVANCED;
				break;
			}
			else {
				std::cout << "您的" << (*this)[LEVEL_KEY] << "灵石不足！\n";
				return false;
			}
		}
	case SpriteStoneLevel::ADVANCED:
		//高级灵石兑换初级灵石
		if (level == SpriteStoneLevel::PRIMARY) {
			this->count *= MIDDLE_ADVANCED * PRIMARY_MIDDLE;
			break;
		}
		//高级灵石兑换中级灵石
		else {
			this->count *= MIDDLE_ADVANCED;
			break;
		}
	}
	this->level = level;
	return true;
}

////兑换灵石
//const SpriteStone& SpriteStone::operator=(const SpriteStone& stone)
//{
//	if (this->level == stone.level) {
//		this->count = stone.count;
//		return *this;
//	}
//	else if (!(*this >= stone)) {
//		std::cout << "您的" << (*this)[LEVEL_KEY] << "灵石不足！\n";
//		//stone.count = 0;
//		return *this;
//	}
//
//	switch (this->level - stone.level) {
//	//初级灵石兑换高级灵石, this为初级灵石， stone为高级灵石
//	case -2:
//		this->count -= (stone.count * MIDDLE_ADVANCED * PRIMARY_MIDDLE);
//		break;
//	//this比stone低1级
//	case -1:
//		//初级灵石兑换中级灵石
//		if (this->level == PRIMARY) {
//			this->count -= (stone.count * PRIMARY_MIDDLE);
//		}
//		//中级灵石兑换高级灵石
//		else {
//			this->count -= (stone.count * MIDDLE_ADVANCED);
//		}
//		break;
//	//this比stone高1级
//	case 1:
//		//中级灵石兑换初级灵石
//		if (level == PRIMARY) {
//			this->count -= (stone.count / PRIMARY_MIDDLE);
//		}
//		//高级灵石兑换中级灵石
//		else {
//			this->count -= (stone.count / MIDDLE_ADVANCED);
//		}
//		break;
//	//高级灵石兑换初级灵石, this为高级灵石， stone为初级灵石
//	case 2:
//		this->count -= ((stone.count / PRIMARY_MIDDLE) / MIDDLE_ADVANCED);
//		break;
//	}
//	
//	return stone;
//}


//SpriteStone& SpriteStone::operator=(const SpriteStone& stone) {
//	this->count = stone.count;
//	this->level = stone.level;
//	return *this;
//}

SpriteStone& SpriteStone::operator+(SpriteStone& stone)
{
	//灵石等级相等
	if (this->level == stone.level) {
		this->count += stone.count;
	}
	//灵石等级不相等
	else {
		stone = SpriteStoneLevel::PRIMARY;//兑换灵石，把stone灵石等级换成初级灵石
		*this = SpriteStoneLevel::PRIMARY;//兑换灵石，把stone灵石等级换成初级灵石
		this->count += stone.count;
	}
	return *this;
}

SpriteStone& SpriteStone::operator+(int count)
{
	this->count += count;
	return *this;
}

SpriteStone& SpriteStone::operator-(SpriteStone& stone)
{
	if (!(*this >= stone)) {
		std::cout << "您的" << (*this)[LEVEL_KEY] << "灵石不足！\n";
		return *this;
	}

	//灵石等级相等
	if (this->level == stone.level) {
		this->count -= stone.count;	
	}
	//灵石等级不相等
	else {
		stone = SpriteStoneLevel::PRIMARY;//兑换灵石，把stone灵石等级换成初级灵石
		*this = SpriteStoneLevel::PRIMARY;//兑换灵石，把stone灵石等级换成初级灵石
		this->count -= stone.count;
	}
	return *this;
}

//SpriteStone& SpriteStone::operator-(SpriteStone& stone) 
//{	
//	if (!(*this >= stone)) {
//		std::cout << "您的" << (*this)[LEVEL_KEY] << "灵石不足！\n";
//		return *this;
//	}
//
//	//灵石等级相等
//	if (this->level == stone.level) {
//		this->count -= stone.count;
//	}
//	//灵石等级不相等
//	else {
//		//兑换灵石，把*this兑换成stone.count块stount.level等级的灵石
//		//并且直接减去，结束时会返回一个stone;
//		*this = stone;
//	}
//	return *this;
//}

SpriteStone& SpriteStone::operator-(int count)
{
	if (this->count >= count) {
		this->count -= count;
	}
	else {
		std::cout << "您的灵石不足！\n";
	}
	return *this;
}

std::string SpriteStone::operator[](std::string KEY) const
{
	switch (this->level) {
	case SpriteStoneLevel::PRIMARY:
		return "初级";
	case SpriteStoneLevel::MIDDLE:
		return "中级";
	case SpriteStoneLevel::ADVANCED:
		return "高级";
	default:
		return "未知";
	}
}

int SpriteStone::operator[](int KEY) const
{
	return this->count;
}

//判断当前灵石是否大于或等于需求的灵石
bool SpriteStone::operator>=(const SpriteStone& stone) const
{
	switch ((int)(this->level) - (int)(stone.level)) {
	  //this比stone低2级，this为初级灵石， stone为高级灵石
	  case -2: 
		  return this->count >= (stone.count * MIDDLE_ADVANCED * PRIMARY_MIDDLE);
	  //this比stone低1级
	  case -1:
		  //this为初级灵石， stone为中级灵石
		  if (this->level == SpriteStoneLevel::PRIMARY) {
			  return this->count >= (stone.count * PRIMARY_MIDDLE);
		  }
		  //this为中级灵石， stone为高级灵石
		  else {
			  return this->count >= (stone.count * MIDDLE_ADVANCED);
		  }
	  //this与stone等级一致
	  case  0: 
		  return this->count >= stone.count;
	  //this比stone高1级
	  case  1:
		  //this为中级灵石， stone为初级灵石
		  if (this->level == SpriteStoneLevel::MIDDLE) {
			  return (this->count * PRIMARY_MIDDLE) >= stone.count;
		  }
		  //this为高级灵石， stone为中级灵石
		  else {
			  return (this->count * MIDDLE_ADVANCED) >= stone.count;
		  }
	  //this比stone高2级，this为高级灵石， stone为初级灵石
	  case  2:
		  return (this->count * MIDDLE_ADVANCED * PRIMARY_MIDDLE) >= stone.count;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const SpriteStone& stone)
{
	os << stone[COUNT_KEY] << "块" << stone[LEVEL_KEY] << "灵石";
	return os;
}
