#pragma once
#include "Book.h"

class SellBook : public Book {
public:
	SellBook(string title, float price, string isbn, float discount = 10.0);
	~SellBook();

	float getDiscount();     //获取折扣
	void  setDiscount(float discount);//设置折扣
	float getPrice();//获取折扣价格
private:
	float discount;//折扣
};

