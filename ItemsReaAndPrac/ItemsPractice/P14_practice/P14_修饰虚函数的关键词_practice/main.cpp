#include <iostream>
#include <Windows.h>

//定义类时添加final， 该类就不能被其他类继承了
class test final{
};

//例如：
class test1 : public test {
};


class test2 {
public:
	//定义虚函数时添加final，会导致其他类继承该类时, 
	//只能继承该虚函数，而无法重写该虚函数
	//只需在定义时添加， 无需在实现时添加
	virtual void testFinal() final{}
};

//例如：
class test3 : public test2{
public:
	void testFinal() {}
};


class test4 {
public:
	virtual void testOverride(){}
};

class test5 : public test4 {
public:
	//在重写父类的虚函数时添加override, 
	//方便阅读代码者知道这是在重写父类的虚函数
	//添加override之后，如果该虚函数的函数名与
	//父类的虚函数的函数名不一致，或该类没有父类，编译器则会报错
	//例如：
	void testoverride() override{}
};
