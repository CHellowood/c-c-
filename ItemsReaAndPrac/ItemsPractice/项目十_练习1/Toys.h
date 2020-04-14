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
	string name;   //�������
	int price;     //�۸�
	string origin; //����
	float discount=1.0;//�ۿ�
};