#pragma once
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Object {
public:
	Object();
	Object(string name, int age);// string gender, int age, int yanzhi, int wage);

	string getName() const;
	//string getGender() const;
	int getAge() const;
	//int getYanzhi() const;
	//int getWage() const;

	//bool satisfied(int objectYanzhi, int objectWage) const;
	//string description() const;//����
	//static void input(vector<Object> &objects);  //�����û���Ϣ

protected:
	string name;     //����
	//string gender;   //�Ա�
	int age;         //����
	//int yanzhi;      //��ֵ
	//int wage;        //����
};