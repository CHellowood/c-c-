#include "Immortal.h"
#include "SpriteStone.h"
#include "Monster.h"
#include <time.h>

#define IMMORTAL_POWER_FACTOR 1000
//��������ս������ ʮ��֮һ
#define MONSTER_POWER_PROP    0.1

//���ʱ����� �ٷֱ�
#define PROB_PROP 100

Immortal::Immortal(std::string name, std::string menPai,
	ImmortalLevel level) 
{
	this->name   = name;
	this->menPai = menPai;
	this->level  = level;
	this->ailve  = true;
}

//�������ԵĹ��캯��
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

//���г��������е�����
bool Immortal::sell()
{
	if (!ailve) {
		return false;
	}
	else if (monsters.size() < 1) {
		std::cout << "��û�����޿��Գ��ۣ�\n";
		return false;
	}
	
	//std::vector<Monster>::iterator iter;

	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		//iter = monsters.begin();

		//�����޵ļ�ֵ��ʯת�ɳ�����ʯ�Է������
		monsters[i].valueList() = SpriteStoneLevel::PRIMARY;
		SpriteStone value = monsters[i].valueList();

		//�ۼ���ʯ
		stone = stone + value;
	}

	//�Ѽ����������ʯ�ӵ���ʯ�ʲ���
	stones.push_back(stone);
	//�����������
	monsters.clear();
	
	return true;
}

//���г�����ָ��������
bool Immortal::sell(Monster& monster)
{
	/*if (!(exist(monster))) {
		std::cout << "��û��" << monster << std::endl;
		return false;
	}*/

	if (!ailve) {
		return false;
	}

	std::vector<Monster>::iterator iter;
	for (iter = monsters.begin(); iter != monsters.end(); iter++) {
		//ָ�����޴���
		if (*iter == monster) {
			//�ѳ��۵õ�����ʯ�ӵ���ʯ�ʲ���
			stones.push_back(SpriteStone((*iter).valueList()));
			//ɾ��ָ������
			monsters.erase(iter);
			return true;
		}
	}
	std::cout << "��û��" << monster << std::endl;
	return false;
}

//�����е����޳��۸�����������
bool Immortal::sell(Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		return false;
	}
	//�ж�vector�����Ƿ�Ϊ��
	else if (monsters.empty()) {
		std::cout << "��û�����޿��Գ��ۣ�\n";
		return false;
	}

	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		//�����޵ļ�ֵ��ʯת�ɳ�����ʯ�Է������
		monsters[i].valueList() = SpriteStoneLevel::PRIMARY;

		SpriteStone value = monsters[i].valueList();
		//�ۼ���ʯ
		stone = stone + value;
	}

	if (!(other.stonesCount() >= stone)) {
		std::cout << "�Է���ʯ���㣡\n";
		return false;
	}

	//�ѶԷ�����ʯ��ȥ���޵���ʯ����
	other.stonesCount() = other.stonesCount() - stone;
	//�Ѽ��������������ʯ�����ӵ���ʯ�ʲ���
	stones.push_back(stone);
	//��������ӵ��Է�����ʯ�ʲ���
	other.addMonsters(monsters);
	//�����������
	monsters.clear();

	return true;
}

////��ָ�������޳��۸�����������
//bool Immortal::sell(Monster& monster, Immortal& other)
//{
//	if (!this->ailve || !other.ailve) {
//		return false;
//	}
//	//����Է���ʯ����
//	if (!(other.stonesCount() >= monster.valueList())) {
//		return false;
//	}
//
//	std::vector<Monster>::iterator iter;
//	for (iter = monsters.begin(); iter != monsters.end(); iter++) {
//		//ָ�����޴���
//		if (*iter == monster) {
//			SpriteStone value = (*iter).valueList();
//			//�ѶԷ�����ʯ��ȥ���޵ļ�ֵ��ʯ
//			other.stonesCount() = other.stonesCount() - value;
//			//�ѳ��۵õ�����ʯ�ӵ���ʯ�ʲ���
//			stones.push_back(SpriteStone((*iter).valueList()));
//			//��������ӵ��Է��������ʲ���
//			other.monsters.push_back(*iter);
//			//ɾ��ָ������
//			monsters.erase(iter);
//			return true;
//		}
//	}
//	std::cout << "��û��" << monster << std::endl;
//	return false;
//}

//��ָ�������޳��۸�����������
bool Immortal::sell(Monster& monster, Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		return false;
	}
	//����Է���ʯ����, ��û�и�����
	if (!(other.stonesCount() >= monster.valueList()) ||
		!this->exist(monster)) {
		return false;
	}

	SpriteStone value = monster.valueList();
	//�ѶԷ�����ʯ��ȥ���޵ļ�ֵ��ʯ
	other.stonesCount() = other.stonesCount() - value;
	//�ѳ��۵õ�����ʯ�ӵ���ʯ�ʲ���
	this->stones.push_back(SpriteStone(value));
	//��������ӵ��Է��������ʲ���
	other.monsters.push_back(monster);
	//ɾ��ָ������
	this->deleteMonster(monster);
	
	return true;
}

//���г�����ָ��������
bool Immortal::purchase(Monster& monster)
{
	if (!ailve) {
		return false;
	}

	if (this->stonesCount() >= monster.valueList()) {
		SpriteStone value = monster.valueList();
		//��ȥ���޼�ֵ��ʯ
		this->stonesCount() = this->stonesCount() - value;
		//��������ӵ������ʲ���
		this->monsters.push_back(monster);
		
		return true;
	}
	return false;
}

////�����������߹���ָ������
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
//			//��ȥ���޼�ֵ��ʯ
//			this->stonesCount() = this->stonesCount() - value;
//			//�����޼�ֵ��ʯ��ӵ��Է�����ʯ�ʲ���
//			other.stones.push_back(value);
//			//��������ӵ������ʲ���
//			this->monsters.push_back(*iter);
//			//�ӶԷ������ʲ���ɾ��������
//			other.monsters.erase(iter);
//
//			return true;
//		}
//	}
//	return false;
//}

//�����������߹���ָ������
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
	//��ȥ���޼�ֵ��ʯ
	this->stonesCount() = this->stonesCount() - value;
	//�����޼�ֵ��ʯ��ӵ��Է�����ʯ�ʲ���
	other.stones.push_back(value);
	//��������ӵ������ʲ���
	this->monsters.push_back(monster);
	//�ӶԷ������ʲ���ɾ��������
	other.deleteMonster(monster);

	return true;
}

//�ڿ�
void Immortal::mining()
{
	stones.push_back(SpriteStone(100));
}

//������ս��ֵ
int Immortal::power() const
{
	int power = ((int)level + 1) * IMMORTAL_POWER_FACTOR;

	for (int i = 0; i < monsters.size(); i++) {
		power += monsters[i].power() * MONSTER_POWER_PROP;
	}

	return power;
}

//��׽����
bool Immortal::seize(Monster& monster)
{
	if (!ailve) return false;

	int immortalPower = this->power();
	int monsterPower = monster.power();

	int num = -1;

	//��׽���޳ɹ�����, 50%
	int prob = PROB_PROP / 2;

	if (immortalPower == monsterPower) {
		num = rand() % PROB_PROP;
		
		//���������������
		if (!this->monsters.empty()) {
			//ÿֻ��������10%����
			for (int i = 0; this->monsters.size(); i++) {
				//����Ϊ100%ʱ����ѭ��
				if (prob == PROB_PROP) break;

				//���Ӹ���
				prob += PROB_PROP / 10;
			}
		}
	}

	//������ս����������ս��������׽�ɹ�
	if (immortalPower > monsterPower || 
		(prob >= 0 && num >= PROB_PROP - prob)) {

		this->monsters.push_back(monster);
	}
	//������ս��С������ս������׽ʧ�ܣ�����
	else {
		death();
	}

	return this->ailve;
}

//���һȺ����
void Immortal::addMonsters(std::vector<Monster>& monsters)
{
	for (int i = 0; i < monsters.size(); i++) {
		this->monsters.push_back(monsters[i]);
	}
}

//�Ѷ�Ӧ�ĵȼ�ת���ַ����� �Է������
std::string Immortal::level_str() const
{
	switch (this->level) {
	case ImmortalLevel::LIAN_QI:   return "������";
	case ImmortalLevel::ZHU_JI:    return "������";
	case ImmortalLevel::JIE_DAN:   return "�ᵤ��";
	case ImmortalLevel::YUAN_YING: return "ԪӤ��";
	case ImmortalLevel::HUA_SHEN:  return "������";
	case ImmortalLevel::LIAN_XU:   return "������";
	case ImmortalLevel::HE_TI:     return "������";
	case ImmortalLevel::DA_CHENG:  return "�����";
	case ImmortalLevel::DU_JIE:    return "�ɽ���";
	default:                       return "δ֪";
	}
}

std::string Immortal::getName() const
{
	return name;
}

//���䣬 �д�
void Immortal::fight(const Immortal& other) const
{
	if (!this->ailve || !other.ailve) {
		std::cout << (this->ailve == false ? this->name : other.name) 
			<< "�������� �޷����б��䣡\n";
		return;
	}

	std::cout << this->name << "��" << other.name << "���б����д裬";
	if (this->power() > other.power()) {
		std::cout << this->name << "ʤ����\n";
	}
	else if (this->power() < other.power()) {
		std::cout << other.name << "ʤ����\n";
	}
	else {
		std::cout << "��������൱��\n";
	}
}

//����
void Immortal::deathFight(Immortal& other)
{
	if (!this->ailve || !other.ailve) {
		std::cout << (this->ailve == false ? this->name : other.name)
			<< "�������� �޷����б��䣡\n";
		return;
	}

	std::cout << "\n" << this->name << "��" 
		<< other.name << "����������";

	if (this->power() > other.power()) {
		std::cout << this->name << "ʤ����" 
			<< other.name << "������\n";

		//�������ߵ������ʲ���ӵ�ʤ���ߵ��ʲ���
		this->stones.push_back(other.stonesCount());
		this->addMonsters(other.monsters);

		other.death();
	}
	else if (this->power() < other.power()) {
		std::cout << other.name << "ʤ����" 
			<< this->name << "������\n";

		//�������ߵ������ʲ���ӵ�ʤ���ߵ��ʲ���
		other.stones.push_back(this->stonesCount());
		other.addMonsters(this->monsters);

		this->death();
	}
	else {
		std::cout << "��������൱��\n";
	}
}

//�չؽ���
bool Immortal::upgrade()
{
	//������������ ���Ѿ�����
	if (!this->ailve || this->level == ImmortalLevel::DU_JIE) 
		return false;

	if ((rand() % 2) == 0) {
		//���׳ɹ��� ��Ϊ����һ��
		this->level = (ImmortalLevel)((int)this->level + 1);
		return true;
	}
	else {
		//����ʧ�ܣ� ��Ϊ����һ��
		this->level = (ImmortalLevel)((int)this->level - 1);
		return false;
	}
}

//������������Ĵ���
void Immortal::death()
{
	ailve = false;
	//�������Ԫ��
	stones.erase(stones.begin(), stones.end());
	monsters.erase(monsters.begin(), monsters.end());
}


//�ж��������Ƿ����ָ��������
bool Immortal::exist(const Monster& monster) const
{
	for (int i = 0; i < monsters.size(); i++) {
		if (monsters[i] == monster) {
			return true;
		}
	}
	return false;
}

//ɾ��ָ������
void Immortal::deleteMonster(const Monster& monster)
{
	std::vector<Monster>::iterator iter;
	for (iter = monsters.begin(); iter != monsters.end();) {
		//��ǰ���޵���Ҫɾ��������
		if (*iter == monster) {
			iter = monsters.erase(iter);
			break;
		}
		else {
			iter++;
		}
	}
}

//������ʯ����������
SpriteStone& Immortal::stonesCount()
{
	//��ʯ�ʲ�Ϊ��
	if (stones.empty()) {
		//���һ���յ���ʯ�� ��ֹ����ʱԽ��
		stones.push_back(SpriteStone(0));
		return stones[0];
	}
	//ֻ��һ��Ԫ�ػ��Ѿ��������ʯ��������û���µ���ʯ���� 
	else if (stones.size() == 1) {
		return stones[0];
	}

	int count = 0;
	for (int i = 0; i < stones.size(); i++) {
		//����ʯת�ɳ�����ʯ�Է������
		stones[i] = SpriteStoneLevel::PRIMARY;
		count += stones[i][COUNT_KEY];
	}
	//���������ʯ
	stones.clear();

	//�Ѽ����������ʯ������ӵ���ʯ�ʲ���
	stones.push_back(SpriteStone(count));

	return stones[0];
}

std::ostream& operator<<(std::ostream& os, Immortal& immortal)
{
	os << "[������]" << immortal.name
		<< (immortal.ailve == true ? "[�����]" : "[������]") 
		<< "\t����:" << immortal.menPai 
		<< "\t�ȼ�:" << immortal.level_str() 
		<< "\t��ʯ:" << immortal.stonesCount() 
		<< "\t����:" << immortal.monsters.size() << "ֻ";
	return os;
}
