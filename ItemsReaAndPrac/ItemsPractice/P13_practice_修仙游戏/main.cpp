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

	std::cout << "兑换前：\n";
	std::cout << stone1 << std::endl;
	std::cout << stone2 << std::endl;
	std::cout << stone3 << std::endl;

	stone1 = SpriteStoneLevel::MIDDLE;
	stone2 = stone2 + stone1;
	stone3 = stone3 - stone2;

	std::cout << "兑换后：\n";
	std::cout << stone1 << std::endl;
	std::cout << stone2 << std::endl;
	std::cout << stone3 << std::endl;
}

void testMonster() {
	Monster monster("蛟龙", MonsterRace::EVILKIND, MonsterLevel::LV9);

	std::cout << monster << std::endl;
}

void testImmortal() {
	SpriteStone stone(1000000, SpriteStoneLevel::PRIMARY);
	Monster monster("蛟龙", MonsterRace::EVILKIND, MonsterLevel::LV9);
	Monster monster1("吞天鲲", MonsterRace::EVILKIND, MonsterLevel::LV9);
	Monster monster2("九尾狐", MonsterRace::EVILKIND, MonsterLevel::LV8);

	std::vector<Monster> monsters;

	Immortal immortal1("无名", "天师道", ImmortalLevel::HE_TI,
		stone, monsters);

	monsters.push_back(monster);
	monsters.push_back(monster1);
	monsters.push_back(monster2);

	Immortal immortal("云杨", "天师道", ImmortalLevel::DA_CHENG, 
		stone, monsters);
	
	std::cout << "初始状态:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------挖矿测试----------
	for (int i = 0; i < 10; i++) {
		immortal.mining();
	}
	std::cout << "\n" << immortal.getName() << "挖完10次矿之后:\n";
	std::cout << immortal << std::endl;

	//-----------到市场出售指定的妖兽测试----------
	immortal.sell(monster1);
	std::cout << "\n" << immortal.getName() << "出售" << monster1 
		<< "之后:\n";
	std::cout << immortal << std::endl;

	//-----------到市场出售全部的妖兽测试----------
	immortal.sell();
	std::cout << "\n" << immortal.getName() << "出售全部妖兽之后:\n";
	std::cout << immortal << std::endl;

	//-----------在市场购买指定的妖兽测试----------
	immortal.purchase(monster1);
	std::cout << "\n" << immortal.getName() << "购买" << monster1 
		<< "之后:\n";
	std::cout << immortal << std::endl;

	//-----------添加一群妖兽测试----------
	immortal.addMonsters(monsters);
	std::cout << "\n" << immortal.getName() << "添加一群妖兽之后:\n";
	std::cout << immortal << std::endl;

	//-----------把指定的妖兽出售给其他修仙者测试----------
	immortal.sell(monster1, immortal1);
	std::cout << "\n" << immortal.getName() << "把" << monster1
		<< "出售给" << immortal1.getName() << "之后:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------把全部妖兽出售给其他修仙者测试----------
	immortal.sell(immortal1);
	std::cout << "\n" << immortal.getName() << "把全部妖兽出售给"
		<< immortal1.getName() << "之后:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------向其他修仙者购买指定的妖兽测试----------
	immortal.purchase(monster1, immortal1);
	std::cout << "\n" << immortal.getName() << "向"
		<< immortal1.getName() << "购买" << monster1 << "之后:\n";
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------捕捉妖兽测试----------
	//修仙者等级高于妖兽， 成功率100%
	//修仙者等级等于妖兽， 成功率50%
	//修仙者等级低于妖兽， 成功率0%
	std::cout << "\n捕捉妖兽\n";

	if (immortal.seize(monster2)) {
		std::cout << immortal.getName() 
			<< "捕捉" << monster2 << "成功\n";
	}
	else {
		std::cout << immortal.getName() << "捕捉" 
			<< monster2 << "失败\n";
	}
	std::cout << immortal << std::endl;

	//-----------比武测试----------
	immortal.fight(immortal1);
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------死斗测试----------
	immortal.deathFight(immortal1);
	std::cout << immortal << std::endl;
	std::cout << immortal1 << std::endl;

	//-----------闭关，进阶测试----------
	if (immortal.upgrade()) {
		std::cout << "进阶成功！\n";
	}
	else {
		std::cout << "进阶失败！\n";
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