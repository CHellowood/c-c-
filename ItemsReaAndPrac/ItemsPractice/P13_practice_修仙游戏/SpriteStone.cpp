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

//�һ���ʯ
bool SpriteStone::operator=(const SpriteStoneLevel level)
{
	if (this->level == level) {
		//std::cout << "�޷��һ���������ʯ�Ѿ���" << (*this)[LEVEL_KEY] << "��ʯ��\n";
		return false;
	}

	switch (this->level) {
	case SpriteStoneLevel::PRIMARY:
		//������ʯ�һ��м���ʯ
		if (level == SpriteStoneLevel::MIDDLE 
			&& this->count >= PRIMARY_MIDDLE) {
			
			this->count /= PRIMARY_MIDDLE;
			break;		
		}
		//������ʯ�һ��߼���ʯ
		else if (level == SpriteStoneLevel::ADVANCED 
			&& this->count >= (PRIMARY_MIDDLE * MIDDLE_ADVANCED)) {
			
			this->count /= (PRIMARY_MIDDLE * MIDDLE_ADVANCED);
			break;
		}
		else {
			std::cout << "����" << (*this)[LEVEL_KEY] << "��ʯ���㣡\n";
			return false;
		}
	case SpriteStoneLevel::MIDDLE:
		//�м���ʯ�һ�������ʯ
		if (level == SpriteStoneLevel::PRIMARY) {
			this->count *= PRIMARY_MIDDLE;
			break;
		}
		//�м���ʯ�һ��߼���ʯ
		else {
			if (this->count >= MIDDLE_ADVANCED) {
				this->count /= MIDDLE_ADVANCED;
				break;
			}
			else {
				std::cout << "����" << (*this)[LEVEL_KEY] << "��ʯ���㣡\n";
				return false;
			}
		}
	case SpriteStoneLevel::ADVANCED:
		//�߼���ʯ�һ�������ʯ
		if (level == SpriteStoneLevel::PRIMARY) {
			this->count *= MIDDLE_ADVANCED * PRIMARY_MIDDLE;
			break;
		}
		//�߼���ʯ�һ��м���ʯ
		else {
			this->count *= MIDDLE_ADVANCED;
			break;
		}
	}
	this->level = level;
	return true;
}

////�һ���ʯ
//const SpriteStone& SpriteStone::operator=(const SpriteStone& stone)
//{
//	if (this->level == stone.level) {
//		this->count = stone.count;
//		return *this;
//	}
//	else if (!(*this >= stone)) {
//		std::cout << "����" << (*this)[LEVEL_KEY] << "��ʯ���㣡\n";
//		//stone.count = 0;
//		return *this;
//	}
//
//	switch (this->level - stone.level) {
//	//������ʯ�һ��߼���ʯ, thisΪ������ʯ�� stoneΪ�߼���ʯ
//	case -2:
//		this->count -= (stone.count * MIDDLE_ADVANCED * PRIMARY_MIDDLE);
//		break;
//	//this��stone��1��
//	case -1:
//		//������ʯ�һ��м���ʯ
//		if (this->level == PRIMARY) {
//			this->count -= (stone.count * PRIMARY_MIDDLE);
//		}
//		//�м���ʯ�һ��߼���ʯ
//		else {
//			this->count -= (stone.count * MIDDLE_ADVANCED);
//		}
//		break;
//	//this��stone��1��
//	case 1:
//		//�м���ʯ�һ�������ʯ
//		if (level == PRIMARY) {
//			this->count -= (stone.count / PRIMARY_MIDDLE);
//		}
//		//�߼���ʯ�һ��м���ʯ
//		else {
//			this->count -= (stone.count / MIDDLE_ADVANCED);
//		}
//		break;
//	//�߼���ʯ�һ�������ʯ, thisΪ�߼���ʯ�� stoneΪ������ʯ
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
	//��ʯ�ȼ����
	if (this->level == stone.level) {
		this->count += stone.count;
	}
	//��ʯ�ȼ������
	else {
		stone = SpriteStoneLevel::PRIMARY;//�һ���ʯ����stone��ʯ�ȼ����ɳ�����ʯ
		*this = SpriteStoneLevel::PRIMARY;//�һ���ʯ����stone��ʯ�ȼ����ɳ�����ʯ
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
		std::cout << "����" << (*this)[LEVEL_KEY] << "��ʯ���㣡\n";
		return *this;
	}

	//��ʯ�ȼ����
	if (this->level == stone.level) {
		this->count -= stone.count;	
	}
	//��ʯ�ȼ������
	else {
		stone = SpriteStoneLevel::PRIMARY;//�һ���ʯ����stone��ʯ�ȼ����ɳ�����ʯ
		*this = SpriteStoneLevel::PRIMARY;//�һ���ʯ����stone��ʯ�ȼ����ɳ�����ʯ
		this->count -= stone.count;
	}
	return *this;
}

//SpriteStone& SpriteStone::operator-(SpriteStone& stone) 
//{	
//	if (!(*this >= stone)) {
//		std::cout << "����" << (*this)[LEVEL_KEY] << "��ʯ���㣡\n";
//		return *this;
//	}
//
//	//��ʯ�ȼ����
//	if (this->level == stone.level) {
//		this->count -= stone.count;
//	}
//	//��ʯ�ȼ������
//	else {
//		//�һ���ʯ����*this�һ���stone.count��stount.level�ȼ�����ʯ
//		//����ֱ�Ӽ�ȥ������ʱ�᷵��һ��stone;
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
		std::cout << "������ʯ���㣡\n";
	}
	return *this;
}

std::string SpriteStone::operator[](std::string KEY) const
{
	switch (this->level) {
	case SpriteStoneLevel::PRIMARY:
		return "����";
	case SpriteStoneLevel::MIDDLE:
		return "�м�";
	case SpriteStoneLevel::ADVANCED:
		return "�߼�";
	default:
		return "δ֪";
	}
}

int SpriteStone::operator[](int KEY) const
{
	return this->count;
}

//�жϵ�ǰ��ʯ�Ƿ���ڻ�����������ʯ
bool SpriteStone::operator>=(const SpriteStone& stone) const
{
	switch ((int)(this->level) - (int)(stone.level)) {
	  //this��stone��2����thisΪ������ʯ�� stoneΪ�߼���ʯ
	  case -2: 
		  return this->count >= (stone.count * MIDDLE_ADVANCED * PRIMARY_MIDDLE);
	  //this��stone��1��
	  case -1:
		  //thisΪ������ʯ�� stoneΪ�м���ʯ
		  if (this->level == SpriteStoneLevel::PRIMARY) {
			  return this->count >= (stone.count * PRIMARY_MIDDLE);
		  }
		  //thisΪ�м���ʯ�� stoneΪ�߼���ʯ
		  else {
			  return this->count >= (stone.count * MIDDLE_ADVANCED);
		  }
	  //this��stone�ȼ�һ��
	  case  0: 
		  return this->count >= stone.count;
	  //this��stone��1��
	  case  1:
		  //thisΪ�м���ʯ�� stoneΪ������ʯ
		  if (this->level == SpriteStoneLevel::MIDDLE) {
			  return (this->count * PRIMARY_MIDDLE) >= stone.count;
		  }
		  //thisΪ�߼���ʯ�� stoneΪ�м���ʯ
		  else {
			  return (this->count * MIDDLE_ADVANCED) >= stone.count;
		  }
	  //this��stone��2����thisΪ�߼���ʯ�� stoneΪ������ʯ
	  case  2:
		  return (this->count * MIDDLE_ADVANCED * PRIMARY_MIDDLE) >= stone.count;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const SpriteStone& stone)
{
	os << stone[COUNT_KEY] << "��" << stone[LEVEL_KEY] << "��ʯ";
	return os;
}
