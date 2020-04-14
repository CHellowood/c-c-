#include "Boy.h"
#include "Girl.h"
#include <sstream>
#include <iomanip>
#include <iostream>

Boy::Boy() : Object() {
	this->gender = "男";
	this->yanzhi = 0;
	this->wage = 0;
}

Boy::Boy(string name, int age, int yanzhi, int wage) 
	: Object(name, age) {
	this->gender = "男";
	this->yanzhi = yanzhi;
	this->wage   = wage;
}

//获取性别
string Boy::getGender() const {
	return gender;
}

//获取颜值
int Boy::getYanzhi() const {
	return yanzhi;
}

//获取薪资
int Boy::getWage() const {
	return wage;
}

//判断girl是否符合该boy的要求
bool Boy::satisfied(const Girl &girl) const {
	int Yanzhi = yanzhi + yanzhi * YANZHI_SCALE;
	
	if (//girl.getWage() >= wage - wage * WAGE_SCALE && 
		girl.getYanzhi() >= (Yanzhi > 100 ? 100 : Yanzhi)) {
		return true;
	}
	return false;
}

//用户描述
string Boy::description() const {
	stringstream ret;
	ret << "名字:" 
		<< setw(9) << setiosflags(ios::left) 
		<< name
		<< "\t\t性别:男"
		<< "\t\t年龄:" << age
		<< "\t\t颜值:"
		<< setw(3) << setiosflags(ios::left) //把下一个数据的宽度设为3并进行左对齐
		<< yanzhi
		<< "\t\t薪资:" << wage;

	return ret.str();
}

//输入多个用户信息
void Boy::inputBoys(vector<Boy>& boys) {
	int i = 1;
	while (true) {
		string name;
		int age;
		int yanzhi;
		int wage;

		cout << "\t<<第" << i++ << "位boy>>\n";
		cout << "名字[输入 end 结束]:";
		cin >> name;

		if (name == "end") break;

		cout << "年龄:";
		cin >> age;

		cout << "颜值:";
		cin >> yanzhi;

		cout << "工资:";
		cin >> wage;

		boys.push_back(Boy(name, age, yanzhi, wage));
	}
}

//输入单个用户信息
void Boy::inputBoy(Boy &boy) {
	string name;
	int age;
	int yanzhi;
	int wage;

	cout << "\n<<输入boy的信息>>\n";
	cout << "名字:";
	cin >> name;

	cout << "年龄:";
	cin >> age;

	cout << "颜值:";
	cin >> yanzhi;

	cout << "工资:";
	cin >> wage;

	boy = Boy(name, age, yanzhi, wage);
}

bool Boy::operator>(const Boy& boy) const
{
	return wage > boy.wage;
}

ostream& operator<<(ostream& os, const Boy& boy)
{
	os << "名字:" << setw(9) << setiosflags(ios::left) << boy.name
		<< "\t\t性别:男"
		<< "\t\t年龄:" << boy.age
		/*把下一个数据的宽度设为3并进行左对齐*/
		<< "\t\t颜值:" << setw(3) << setiosflags(ios::left) << boy.yanzhi
		<< "\t\t薪资:" << boy.wage;

	return os;
}
