#include <sstream>
#include <iostream>
#include "Person.h"

Person::Person() {
}

Person::Person(string name, int age, gender_t gender) {
	this->name = name;
	this->age = age;
	this->gender = gender;
}

Person::~Person() {
}

string Person::getName() const {
	return name;
}

int Person::getAge() const {
	return age;
}

gender_t Person::getGender() const {
	return gender;
}

Person* Person::getObject() const {
	return object;
}

vector<Person*> Person::getFriends() const {
	return friends;
}

string Person::description() const {
	stringstream ret;
	ret << name << "-" << age << "岁-" << (gender == Man ? "男" : "女");
	return ret.str();
}

void Person::getMarried(Person& object) {
	if (this->object != NULL) {
		cout << this->name << "你已经有对象了, 不能再次结婚!" << endl;
		return;
	}

	this->object = &object;
	object.object = this;
	cout << this->name << "和" << object.name << "结婚了!" << endl;
}

void Person::divorce() {
	if (object == NULL) {
		cout << this->name << ",你没有对象无法离婚!" << endl;
		return;
	}
	cout << this->name << "和" << object->name << "离婚了!" << endl;
	object->object = NULL;
	object = NULL;
	
}

void Person::addFriend(Person& aFriend) {
	friends.push_back(&aFriend);
	cout << "成功添加" << aFriend.name << "为好友!" << endl;
}

void Person::breakFriend(Person& bFriend) {
	//begin() 返回第一个元素的迭代器, end() 返回最后一个元素的下一个位置的迭代器
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &bFriend) {
			it = friends.erase(it);//erase() 删除指定元素并返回下一个元素的迭代器
			cout << "成功删除" << bFriend.name << "!" << endl;
		}
		else {
			it++;
		}
	}
}
