#include <iostream>
#include <sstream>
#include "Toys.h"

Toys::Toys() {
	name = "";
	price = 0;
	origin = "";
}

Toys::Toys(string name, int price, string origin) {
	this->name = name;
	this->price = price;
	this->origin = origin;
}

Toys::~Toys() {

}

string Toys::getName() const {
	return name;
}

int Toys::getPrice() const {
	return (int)(price*discount);
}

string Toys::getOrigin() const {
	return origin;
}

string Toys::description() const {
	stringstream ret;
	ret << name << "-�۸�:" << getPrice() << "-����:" << origin;
	return ret.str();
}
