#include <iostream>
#include <Windows.h>

//拥有纯虚函数的类被称之为抽象类
class Shape {//形状
public:
	Shape(const char* color = "blue"){
		int len = strlen(color) + 1;
		this->color = new char[len];
		strcpy_s(this->color, len, color);
	}

	//如果该类的子类拥有指针成员， 尽量把该类的析构函数定义为虚函数
	virtual ~Shape() { delete[] color; }

	//纯虚函数
	virtual int area() = 0;

private:
	char* color;
};


class Square : public Shape{//正方形
public:
	Square(int row = 0, const char* color = "blue") 
		: Shape(color), row(row){}

	//继承抽象类后，需要对抽象类的纯虚函数进行重写并实现
	//如果不进行重写，那么该类也是抽象类
	int area() { return row * row; }

private:
	int row;
};

int main() {
	//抽象类无法生成对象
	//例如：
	Shape s;


}