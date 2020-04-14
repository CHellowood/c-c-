#pragma once
#include <string>

using namespace std;

class Toys {
public:	
	Toys();
	Toys(string name, int price, string origin);
	~Toys();

	string getName() const;
	int getPrice() const;
	string getOrigin() const;
	string description() const;
private:
	string name;   //玩具名称
	int price;     //价格
	string origin; //产地
	float discount=1.0;//折扣
};