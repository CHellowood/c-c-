#include <sstream>
#include "Son.h"

Son::Son(const char* name, int age, const char* game) :Father(name, age) {
	this->game = game;
}

Son::~Son() {

}

string Son::getGame() const {
	return game;
}

string Son::description() const {
	stringstream ret;
	ret << "name:" << name << " age:" << age << "game" << game << endl;
	return ret.str();
}