#include "Immortal.h"
#include "SpriteStone.h"
#include "Monster.h"
#include <time.h>

#define IMMORTAL_POWER_FACTOR 1000
//妖兽助攻战力比例 十分之一
#define MONSTER_POWER_PROP    0.1

//概率比例， 百分比
#define PROB_PROP 100

Immortal::Immortal(std::string name, std::string menPai,
	ImmortalLevel level) 
{
	this->name   = name;
	this->menPai = menPai;
	this->level  = level;
	this->ailve  = true;
}

//用来测试的构造函数
Immortal::Immortal(std::string name, std::string menPai, 
	ImmortalLevel level, SpriteStone stone,
	std::vector<Monster> monsters)
{
	this->name = name;
	this->menPai = menPai;
	this->level = level;
	this->stones.push_back(stone);
	addMonsters(monsters);
	this->ailve = true;
}

//到市场出售所有的妖兽
bool Immortal::sell()
{
	if (!ailve) {
		return false;
	}
	else if (monsters.size() < 1) {
		std::cout << "你没有妖兽可以出售！\n";
		return false;
	}
	
	//std::vector<Monster>::iterator iter;

	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		//iter = monsters.begin();

		//把妖兽的价值灵石转成初级灵石以方便计算
		monsters[i].valueList() = SpriteStoneLevel::PRIMARY;
		SpriteStone value = monsters[i].valueList();

		//累加灵石
		stone = stone + value;
	}

	//把计算出来的灵石加到灵石资产里
	stones.push_back(stone);
	//清空所有妖兽
	monsters.clear();
	
	return true;
}

//到市场出售指定的妖兽
bool Immortal::sell(Monster& monster)
{
	/*if (!(exist(monster))) {
		std::cout << "你没有" << monster << std::endl;
		return false;
	}*/

	if (!ailve) {
		return false;
	}

	std::vector<Monster>::iterator iter;
	for (iter = monsters.begin(); iter != monsters.end(); iter++) {
		//指定妖兽存在
		if (*iter == monster) {
			//把出售得到的灵石加到灵石资产里
			stones.push_back(SpriteStone((*iter).valueList()));
			//删除指定妖兽
			monsters.erase(iter);
			return true;
		}
	}
	std::cout << "你没有" << monster << std::endl;
	return false;
}

//把所有的妖兽出售给其他修仙者
bool Immortal::sell(Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		return false;
	}
	//判断vector容器是否为空
	else if (monsters.empty()) {
		std::cout << "你没有妖兽可以出售！\n";
		return false;
	}

	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		//把妖兽的价值灵石转成初级灵石以方便计算
		monsters[i].valueList() = SpriteStoneLevel::PRIMARY;

		SpriteStone value = monsters[i].valueList();
		//累加灵石
		stone = stone + value;
	}

	if (!(other.stonesCount() >= stone)) {
		std::cout << "对方灵石不足！\n";
		return false;
	}

	//把对方的灵石减去妖兽的灵石总数
	other.stonesCount() = other.stonesCount() - stone;
	//把计算出来的妖兽灵石总数加到灵石资产里
	stones.push_back(stone);
	//把妖兽添加到对方的灵石资产里
	other.addMonsters(monsters);
	//清空所有妖兽
	monsters.clear();

	return true;
}

////把指定的妖兽出售给其他修仙者
//bool Immortal::sell(Monster& monster, Immortal& other)
//{
//	if (!this->ailve || !other.ailve) {
//		return false;
//	}
//	//如果对方灵石不足
//	if (!(other.stonesCount() >= monster.valueList())) {
//		return false;
//	}
//
//	std::vector<Monster>::iterator iter;
//	for (iter = monsters.begin(); iter != monsters.end(); iter++) {
//		//指定妖兽存在
//		if (*iter == monster) {
//			SpriteStone value = (*iter).valueList();
//			//把对方的灵石减去妖兽的价值灵石
//			other.stonesCount() = other.stonesCount() - value;
//			//把出售得到的灵石加到灵石资产里
//			stones.push_back(SpriteStone((*iter).valueList()));
//			//把妖兽添加到对方的妖兽资产里
//			other.monsters.push_back(*iter);
//			//删除指定妖兽
//			monsters.erase(iter);
//			return true;
//		}
//	}
//	std::cout << "你没有" << monster << std::endl;
//	return false;
//}

//把指定的妖兽出售给其他修仙者
bool Immortal::sell(Monster& monster, Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		return false;
	}
	//如果对方灵石不足, 或没有该妖兽
	if (!(other.stonesCount() >= monster.valueList()) ||
		!this->exist(monster)) {
		return false;
	}

	SpriteStone value = monster.valueList();
	//把对方的灵石减去妖兽的价值灵石
	other.stonesCount() = other.stonesCount() - value;
	//把出售得到的灵石加到灵石资产里
	this->stones.push_back(SpriteStone(value));
	//把妖兽添加到对方的妖兽资产里
	other.monsters.push_back(monster);
	//删除指定妖兽
	this->deleteMonster(monster);
	
	return true;
}

//到市场购买指定的妖兽
bool Immortal::purchase(Monster& monster)
{
	if (!ailve) {
		return false;
	}

	if (this->stonesCount() >= monster.valueList()) {
		SpriteStone value = monster.valueList();
		//减去妖兽价值灵石
		this->stonesCount() = this->stonesCount() - value;
		//把妖兽添加到妖兽资产里
		this->monsters.push_back(monster);
		
		return true;
	}
	return false;
}

////向其他修仙者购买指定妖兽
//bool Immortal::purchase(Monster& monster, Immortal& other)
//{
//	if (!this->ailve || !other.ailve) {
//		return false;
//	}
//
//	std::vector<Monster>::iterator iter;
//	for (iter = other.monsters.begin(); 
//		iter != other.monsters.end(); iter++) {
//		
//		if (*iter == monster 
//			&& this->stonesCount() >= monster.valueList()) {
//			SpriteStone value = iter->valueList();
//			//减去妖兽价值灵石
//			this->stonesCount() = this->stonesCount() - value;
//			//把妖兽价值灵石添加到对方的灵石资产里
//			other.stones.push_back(value);
//			//把妖兽添加到妖兽资产里
//			this->monsters.push_back(*iter);
//			//从对方妖兽资产里删除该妖兽
//			other.monsters.erase(iter);
//
//			return true;
//		}
//	}
//	return false;
//}

//向其他修仙者购买指定妖兽
bool Immortal::purchase(Monster& monster, Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		return false;
	}
	if (!(this->stonesCount() >= monster.valueList()) || 
		!other.exist(monster)) {
		return false;
	}

	SpriteStone value = monster.valueList();
	//减去妖兽价值灵石
	this->stonesCount() = this->stonesCount() - value;
	//把妖兽价值灵石添加到对方的灵石资产里
	other.stones.push_back(value);
	//把妖兽添加到妖兽资产里
	this->monsters.push_back(monster);
	//从对方妖兽资产里删除该妖兽
	other.deleteMonster(monster);

	return true;
}

//挖矿
void Immortal::mining()
{
	stones.push_back(SpriteStone(100));
}

//修仙者战力值
int Immortal::power() const
{
	int power = ((int)level + 1) * IMMORTAL_POWER_FACTOR;

	for (int i = 0; i < monsters.size(); i++) {
		power += monsters[i].power() * MONSTER_POWER_PROP;
	}

	return power;
}

//捕捉妖兽
bool Immortal::seize(Monster& monster)
{
	if (!ailve) return false;

	int immortalPower = this->power();
	int monsterPower = monster.power();

	int num = -1;

	//捕捉妖兽成功概率, 50%
	int prob = PROB_PROP / 2;

	if (immortalPower == monsterPower) {
		num = rand() % PROB_PROP;
		
		//如果修仙者有妖兽
		if (!this->monsters.empty()) {
			//每只妖兽增加10%概率
			for (int i = 0; this->monsters.size(); i++) {
				//概率为100%时结束循环
				if (prob == PROB_PROP) break;

				//增加概率
				prob += PROB_PROP / 10;
			}
		}
	}

	//修仙者战力大于妖兽战力，　捕捉成功
	if (immortalPower > monsterPower || 
		(prob >= 0 && num >= PROB_PROP - prob)) {

		this->monsters.push_back(monster);
	}
	//修仙者战力小于妖兽战力，捕捉失败，阵亡
	else {
		death();
	}

	return this->ailve;
}

//添加一群妖兽
void Immortal::addMonsters(std::vector<Monster>& monsters)
{
	for (int i = 0; i < monsters.size(); i++) {
		this->monsters.push_back(monsters[i]);
	}
}

//把对应的等级转成字符串， 以方便输出
std::string Immortal::level_str() const
{
	switch (this->level) {
	case ImmortalLevel::LIAN_QI:   return "练气期";
	case ImmortalLevel::ZHU_JI:    return "筑基期";
	case ImmortalLevel::JIE_DAN:   return "结丹期";
	case ImmortalLevel::YUAN_YING: return "元婴期";
	case ImmortalLevel::HUA_SHEN:  return "化神期";
	case ImmortalLevel::LIAN_XU:   return "炼虚期";
	case ImmortalLevel::HE_TI:     return "合体期";
	case ImmortalLevel::DA_CHENG:  return "大乘期";
	case ImmortalLevel::DU_JIE:    return "渡劫期";
	default:                       return "未知";
	}
}

std::string Immortal::getName() const
{
	return name;
}

//比武， 切磋
void Immortal::fight(const Immortal& other) const
{
	if (!this->ailve || !other.ailve) {
		std::cout << (this->ailve == false ? this->name : other.name) 
			<< "已死亡， 无法进行比武！\n";
		return;
	}

	std::cout << this->name << "和" << other.name << "进行比武切磋，";
	if (this->power() > other.power()) {
		std::cout << this->name << "胜出！\n";
	}
	else if (this->power() < other.power()) {
		std::cout << other.name << "胜出！\n";
	}
	else {
		std::cout << "两人旗鼓相当！\n";
	}
}

//死斗
void Immortal::deathFight(Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		std::cout << (this->ailve == false ? this->name : other.name)
			<< "已死亡， 无法进行比武！\n";
		return;
	}

	std::cout << "\n" << this->name << "和" 
		<< other.name << "进行死斗，";

	if (this->power() > other.power()) {
		std::cout << this->name << "胜出，" 
			<< other.name << "阵亡！\n";

		//把阵亡者的所有资产添加到胜出者的资产里
		this->stones.push_back(other.stonesCount());
		this->addMonsters(other.monsters);

		other.death();
	}
	else if (this->power() < other.power()) {
		std::cout << other.name << "胜出，" 
			<< this->name << "阵亡！\n";

		//把阵亡者的所有资产添加到胜出者的资产里
		other.stones.push_back(this->stonesCount());
		other.addMonsters(this->monsters);

		this->death();
	}
	else {
		std::cout << "两人旗鼓相当！\n";
	}
}

//闭关进阶
bool Immortal::upgrade()
{
	//修仙者死亡， 或已经满级
	if (!this->ailve || this->level == ImmortalLevel::DU_JIE) 
		return false;

	if ((rand() % 2) == 0) {
		//进阶成功， 修为更进一步
		this->level = (ImmortalLevel)((int)this->level + 1);
		return true;
	}
	else {
		//进阶失败， 修为倒退一步
		this->level = (ImmortalLevel)((int)this->level - 1);
		return false;
	}
}

//修仙者死亡后的处理
void Immortal::death()
{
	ailve = false;
	//清空所有元素
	stones.erase(stones.begin(), stones.end());
	monsters.erase(monsters.begin(), monsters.end());
}


//判断修仙者是否存在指定的妖兽
bool Immortal::exist(const Monster& monster) const
{
	for (int i = 0; i < monsters.size(); i++) {
		if (monsters[i] == monster) {
			return true;
		}
	}
	return false;
}

//删除指定妖兽
void Immortal::deleteMonster(const Monster& monster)
{
	std::vector<Monster>::iterator iter;
	for (iter = monsters.begin(); iter != monsters.end();) {
		//当前妖兽等于要删除的妖兽
		if (*iter == monster) {
			iter = monsters.erase(iter);
			break;
		}
		else {
			iter++;
		}
	}
}

//计算灵石总数并返回
SpriteStone& Immortal::stonesCount()
{
	//灵石资产为空
	if (stones.empty()) {
		//添加一个空的灵石， 防止返回时越界
		stones.push_back(SpriteStone(0));
		return stones[0];
	}
	//只有一个元素或已经计算过灵石总数而且没有新的灵石收入 
	else if (stones.size() == 1) {
		return stones[0];
	}

	int count = 0;
	for (int i = 0; i < stones.size(); i++) {
		//把灵石转成初级灵石以方便计算
		stones[i] = SpriteStoneLevel::PRIMARY;
		count += stones[i][COUNT_KEY];
	}
	//清空所有灵石
	stones.clear();

	//把计算出来的灵石总数添加到灵石资产里
	stones.push_back(SpriteStone(count));

	return stones[0];
}

std::ostream& operator<<(std::ostream& os, Immortal& immortal)
{
	os << "[修仙者]" << immortal.name
		<< (immortal.ailve == true ? "[存活中]" : "[已死亡]") 
		<< "\t门派:" << immortal.menPai 
		<< "\t等级:" << immortal.level_str() 
		<< "\t灵石:" << immortal.stonesCount() 
		<< "\t妖兽:" << immortal.monsters.size() << "只";
	return os;
}
