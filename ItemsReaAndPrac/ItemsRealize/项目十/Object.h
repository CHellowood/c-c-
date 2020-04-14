#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Object {
public:
	Object();
	Object(string name, string gender, int age, int yanzhi, int wage, int demandYanzhi, int demandWage);
	~Object();

	string getName() const;
	string getGender() const;
	int getAge() const;
	int getYanzhi() const;
	int getWage() const;

	bool satisfied(int objectYanzhi, int objectWage) const;
	string description() const;//����
	static void input(vector<Object> &objects);//����

private:
	string name;     //����
	string gender;   //�Ա�
	int age;         //����
	int yanzhi;      //��ֵ
	int wage;        //����
	int demandYanzhi;//Ҫ����ֵ
	int demandWage;  //Ҫ����

};