#pragma once

#ifndef _IMMORTAL_H_
#define _IMMORTAL_H_

#include <iostream>
#include <string>
#include <vector>

class SpriteStone; //灵石类
class Monster;     //怪物类

enum class ImmortalLevel {//修仙者等级
	LIAN_QI,    //练气期
	ZHU_JI,     //筑基期
	JIE_DAN,    //结丹期
	YUAN_YING,  //元婴期
	HUA_SHEN,   //化神期
	LIAN_XU,    //炼虚期
	HE_TI,      //合体期
	DA_CHENG,   //大乘期
	DU_JIE,     //渡劫期
	LEVEL_COUNT //等级数
};

class Immortal //修仙者类
{
public:
	Immortal(std::string name, std::string menPai = "散修", 
		ImmortalLevel level = ImmortalLevel::LIAN_QI);
	
	//用来测试的构造函数, 测试完成后请注释掉或删除掉
	Immortal(std::string name, std::string menPai,
		ImmortalLevel level, SpriteStone stone,
		std::vector<Monster> monsters);

	//到市场出售所有的妖兽
	bool sell(); 
	//到市场出售指定的妖兽
	bool sell(Monster& monster);
	//把所有的妖兽出售给其他修仙者
	bool sell(Immortal& other);
	//把指定的妖兽出售给其他修仙者
	bool sell(Monster& monster, Immortal& other);
	
	//到市场购买指定的妖兽
	bool purchase(Monster& monster);
	//向其他修仙者购买指定妖兽
	bool purchase(Monster& monster, Immortal& other);

	//挖矿
	void mining();

	//修仙者战力值
	int power() const;

	//捕捉妖兽
	bool seize(Monster& monster);

	//添加一群妖兽
	void addMonsters(std::vector<Monster>& monsters);

	friend std::ostream& operator<<(std::ostream& os, 
		Immortal& immortal);

	//把对应的等级转成字符串， 以方便输出
	std::string level_str() const;

	std::string getName() const;

	//比武， 切磋
	void fight(const Immortal& other) const;
	//死斗
	void deathFight(Immortal& other);

	//闭关进阶
	bool upgrade();

	//修仙者死亡后的处理
	void death();

private:
	std::string name;  
	std::string menPai; //门派
	ImmortalLevel level;
	std::vector<SpriteStone> stones; //灵石资产
	std::vector<Monster> monsters;   //妖兽资产
	bool ailve; //生死状态

	//判断修仙者是否存在指定的妖兽
	bool exist(const Monster& monster) const;
	
	//删除指定妖兽
	void deleteMonster(const Monster& monster);

	//计算灵石资产的灵石总数，并把所有灵石整合起来
	SpriteStone& stonesCount();
};

std::ostream& operator<<(std::ostream& os, Immortal& immortal);

#endif 