#include "SellBook.h"

SellBook::SellBook(string title, float price, string isbn, float discount)
	: Book(title, price, isbn) {
	this->discount = discount;
}

SellBook::~SellBook() {

}

//��ȡ��ǰ�ۿ�
float SellBook::getDiscount() {
	return discount;
}

//�����ۿ�
void SellBook::setDiscount(float discount) {
	this->discount = discount;
}

//��ȡ�ۿۼ۸�
float SellBook::getPrice() {
	return (price * discount / 10);
}