#include "SellBook.h"

SellBook::SellBook(string title, float price, string isbn, float discount)
	: Book(title, price, isbn) {
	this->discount = discount;
}

SellBook::~SellBook() {

}

//获取当前折扣
float SellBook::getDiscount() {
	return discount;
}

//设置折扣
void SellBook::setDiscount(float discount) {
	this->discount = discount;
}

//获取折扣价格
float SellBook::getPrice() {
	return (price * discount / 10);
}