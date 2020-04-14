#include "Father.h"
#include <sstream>

Father::Father(const char* name, int age) {
	this->name = name;
	this->age = age;
}

Father::~Father() {
}

string Father::getName() const {
	return name;
}

int Father::getAge() const {
	return age;
}

string Father::description() const {
	stringstream ret;
	ret << "name:" << name << " age:" << age << endl;
	return ret.str();
}