#include <iostream>
#include <Windows.h>
#include <time.h>
#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"



void testSpriteStone() {
	SpriteStone stone1(100);
	SpriteStone stone2(10, SpriteStoneLevel::MIDDLE);
	SpriteStone stone3(2, SpriteStoneLevel::ADVANCED);

	std::cout << "�һ�ǰ��\n";
	std::cout << stone1 << std::endl;
	std::cout << stone2 << std::endl;
	std::cout << stone3 << std::endl;

	stone1 = SpriteStoneLevel::MIDDLE;
	stone2 = stone2 + stone1;
	stone3 = stone3 - stone2;

	std::cout << "�һ���\n";
	std::cout << stone1 << std::endl;
	std::cout << stone2 << std::endl;
	std::cout << stone3 << std::endl;
}

void testMonster() {
	Monster monster("����", MonsterRace::EVILKIND, MonsterLevel::LV9);

	std::cout << monster << std::endl;
}

void testImmortal() {
	SpriteStone stone(1000000, SpriteStoneLevel::PRIMARY);
	Monster monster("����", MonsterRace::EVILKIND, MonsterLevel::LV9);
	Monster monster1("������", MonsterRace::EVILKIND, MonsterLevel::LV9);
	Monster monster2("��β��", MonsterRace::EVILKIND, MonsterLevel::LV8);

	std::vector<Monster> monsters;

	Immortal immortal1("����", "��ʦ��", ImmortalLevel::HE_TI,
		stone, monsters);

	monsters.push_back(monster);
	monsters.push_back(monster1);
	monsters.push_back(monster2);

	Immortal immortal("����", "��ʦ��", ImmortalLevel::DA_CHENG, 
		stone, monsters);
	
	std::cout << "��ʼ״̬:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------�ڿ����----------
	for (int i = 0; i < 10; i++) {
		immortal.mining();
	}
	std::cout << "\n" << immortal.getName() << "����10�ο�֮��:\n";
	std::cout << immortal << std::endl;

	//-----------���г�����ָ�������޲���----------
	immortal.sell(monster1);
	std::cout << "\n" << immortal.getName() << "����" << monster1 
		<< "֮��:\n";
	std::cout << immortal << std::endl;

	//-----------���г�����ȫ�������޲���----------
	immortal.sell();
	std::cout << "\n" << immortal.getName() << "����ȫ������֮��:\n";
	std::cout << immortal << std::endl;

	//-----------���г�����ָ�������޲���----------
	immortal.purchase(monster1);
	std::cout << "\n" << immortal.getName() << "����" << monster1 
		<< "֮��:\n";
	std::cout << immortal << std::endl;

	//-----------���һȺ���޲���----------
	immortal.addMonsters(monsters);
	std::cout << "\n" << immortal.getName() << "���һȺ����֮��:\n";
	std::cout << immortal << std::endl;

	//-----------��ָ�������޳��۸����������߲���----------
	immortal.sell(monster1, immortal1);
	std::cout << "\n" << immortal.getName() << "��" << monster1
		<< "���۸�" << immortal1.getName() << "֮��:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------��ȫ�����޳��۸����������߲���----------
	immortal.sell(immortal1);
	std::cout << "\n" << immortal.getName() << "��ȫ�����޳��۸�"
		<< immortal1.getName() << "֮��:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------�����������߹���ָ�������޲���----------
	immortal.purchase(monster1, immortal1);
	std::cout << "\n" << immortal.getName() << "��"
		<< immortal1.getName() << "����" << monster1 << "֮��:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------��׽���޲���----------
	//�����ߵȼ��������ޣ� �ɹ���100%
	//�����ߵȼ��������ޣ� �ɹ���50%
	//�����ߵȼ��������ޣ� �ɹ���0%
	std::cout << "\n��׽����\n";

	if (immortal.seize(monster2)) {
		std::cout << immortal.getName() 
			<< "��׽" << monster2 << "�ɹ�\n";
	}
	else {
		std::cout << immortal.getName() << "��׽" 
			<< monster2 << "ʧ��\n";
	}
	std::cout << immortal << std::endl;

	//-----------�������----------
	immortal.fight(immortal1);
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------��������----------
	immortal.deathFight(immortal1);
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------�չأ����ײ���----------
	if (immortal.upgrade()) {
		std::cout << "���׳ɹ���\n";
	}
	else {
		std::cout << "����ʧ�ܣ�\n";
	}
	
	std::cout << immortal << std::endl;
}


int main(void) {
	srand((unsigned)time(NULL));
	//testSpriteStone();

	//testMonster();

	testImmortal();

	system("pause");
	return 0;
}