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

//��ȡ�۸�
float Book::getPrice() {
	return price;
}

//��ȡ���
string Book::getISBN() {
	return ISBN;
}