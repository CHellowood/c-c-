//#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>

using namespace std;

class Book {
public:
	Book(string title, float price, string isbn);
	~Book();

	string getTitle();//获取书名
	float  getPrice();//获取价格
	string getISBN(); //获取书号

protected:
	string title; //书名
	float  price; //价格
	string ISBN;  //书号
};

#endif 