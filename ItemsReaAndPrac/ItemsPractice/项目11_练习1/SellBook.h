#pragma once
#include "Book.h"

class SellBook : public Book {
public:
	SellBook(string title, float price, string isbn, float discount = 10.0);
	~SellBook();

	float getDiscount();     //��ȡ�ۿ�
	void  setDiscount(float discount);//�����ۿ�
	float getPrice();//��ȡ�ۿۼ۸�
private:
	float discount;//�ۿ�
};

