//#pragma once
#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>

using namespace std;

class Book {
public:
	Book(string title, float price, string isbn);
	~Book();

	string getTitle();//��ȡ����
	float  getPrice();//��ȡ�۸�
	string getISBN(); //��ȡ���

protected:
	string title; //����
	float  price; //�۸�
	string ISBN;  //���
};

#endif 