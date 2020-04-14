#include "Book.h"

Book::Book(string title, float price, string isbn) {
	this->title = title;
	this->price = price;
	this->ISBN = isbn;
}

Book::~Book() {

}

string Book::getTitle() {
	return title;
}

//获取价格
float Book::getPrice() {
	return price;
}

//获取书号
string Book::getISBN() {
	return ISBN;
}