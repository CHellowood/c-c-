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
	ret << name << "-" << age << "��-" << (gender == Man ? "��" : "Ů");
	return ret.str();
}

void Person::getMarried(Person& object) {
	if (this->object != NULL) {
		cout << this->name << "���Ѿ��ж�����, �����ٴν��!" << endl;
		return;
	}

	this->object = &object;
	object.object = this;
	cout << this->name << "��" << object.name << "�����!" << endl;
}

void Person::divorce() {
	if (object == NULL) {
		cout << this->name << ",��û�ж����޷����!" << endl;
		return;
	}
	cout << this->name << "��" << object->name << "�����!" << endl;
	object->object = NULL;
	object = NULL;
	
}

void Person::addFriend(Person& aFriend) {
	friends.push_back(&aFriend);
	cout << "�ɹ����" << aFriend.name << "Ϊ����!" << endl;
}

void Person::breakFriend(Person& bFriend) {
	//begin() ���ص�һ��Ԫ�صĵ�����, end() �������һ��Ԫ�ص���һ��λ�õĵ�����
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &bFriend) {
			it = friends.erase(it);//erase() ɾ��ָ��Ԫ�ز�������һ��Ԫ�صĵ�����
			cout << "�ɹ�ɾ��" << bFriend.name << "!" << endl;
		}
		else {
			it++;
		}
	}
}
