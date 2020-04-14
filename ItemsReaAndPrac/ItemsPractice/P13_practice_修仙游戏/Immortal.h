#pragma once

#ifndef _IMMORTAL_H_
#define _IMMORTAL_H_

#include <iostream>
#include <string>
#include <vector>

class SpriteStone; //��ʯ��
class Monster;     //������

enum class ImmortalLevel {//�����ߵȼ�
	LIAN_QI,    //������
	ZHU_JI,     //������
	JIE_DAN,    //�ᵤ��
	YUAN_YING,  //ԪӤ��
	HUA_SHEN,   //������
	LIAN_XU,    //������
	HE_TI,      //������
	DA_CHENG,   //�����
	DU_JIE,     //�ɽ���
	LEVEL_COUNT //�ȼ���
};

class Immortal //��������
{
public:
	Immortal(std::string name, std::string menPai = "ɢ��", 
		ImmortalLevel level = ImmortalLevel::LIAN_QI);
	
	//�������ԵĹ��캯��, ������ɺ���ע�͵���ɾ����
	Immortal(std::string name, std::string menPai,
		ImmortalLevel level, SpriteStone stone,
		std::vector<Monster> monsters);

	//���г��������е�����
	bool sell(); 
	//���г�����ָ��������
	bool sell(Monster& monster);
	//�����е����޳��۸�����������
	bool sell(Immortal& other);
	//��ָ�������޳��۸�����������
	bool sell(Monster& monster, Immortal& other);
	
	//���г�����ָ��������
	bool purchase(Monster& monster);
	//�����������߹���ָ������
	bool purchase(Monster& monster, Immortal& other);

	//�ڿ�
	void mining();

	//������ս��ֵ
	int power() const;

	//��׽����
	bool seize(Monster& monster);

	//���һȺ����
	void addMonsters(std::vector<Monster>& monsters);

	friend std::ostream& operator<<(std::ostream& os, 
		Immortal& immortal);

	//�Ѷ�Ӧ�ĵȼ�ת���ַ����� �Է������
	std::string level_str() const;

	std::string getName() const;

	//���䣬 �д�
	void fight(const Immortal& other) const;
	//����
	void deathFight(Immortal& other);

	//�չؽ���
	bool upgrade();

	//������������Ĵ���
	void death();

private:
	std::string name;  
	std::string menPai; //����
	ImmortalLevel level;
	std::vector<SpriteStone> stones; //��ʯ�ʲ�
	std::vector<Monster> monsters;   //�����ʲ�
	bool ailve; //����״̬

	//�ж��������Ƿ����ָ��������
	bool exist(const Monster& monster) const;
	
	//ɾ��ָ������
	void deleteMonster(const Monster& monster);

	//������ʯ�ʲ�����ʯ����������������ʯ��������
	SpriteStone& stonesCount();
};

std::ostream& operator<<(std::ostream& os, Immortal& immortal);

#endif 