#include <iostream>
#include <stdlib.h>

class Father {
public:
	virtual void test1() { std::cout << "Father::test1\n"; }
	virtual void test2() { std::cout << "Father::test2\n"; }
	virtual void test3() { std::cout << "Father::test3\n"; }
	virtual void test4() { std::cout << "Father::test4\n"; }
	void test5() { std::cout << "非虚函数：Father::test5\n"; }

public:
	int x = 'x';
	int y = 'y';
	static int z;
};
int Father::z = 'z';


class Son : public Father{
public:
	void test1() { std::cout << "Son::test1\n"; }
	virtual void test6() { std::cout << "Son::test6\n"; }
};


typedef void (*test_t)(void);

int main() {
	Son son;

	std::cout << "son: size: " << sizeof(son) << std::endl;
	std::cout << "son: 地址: " << &son << std::endl;

	int* vir = (int*)*((int*)(&son));

	for (int i = 0; i < 5; i++) {
		std::cout << "第" << i + 1 << "个虚函数: ";
		((test_t)*(vir + i))();
	}

	std::cout << "son.x: 地址: " << &son.x << std::endl;
	std::cout << "son.x: 地址: " << ((int*)(&son) + 1) << std::endl;
	std::cout << "son.x: 值: " << son.x << std::endl;
	std::cout << "son.x: 值: " << *((int*)(&son) + 1) << std::endl;

	std::cout << "son.y: 地址: " << &son.y << std::endl;
	std::cout << "son.y: 地址: " << ((int*)(&son) + 2) << std::endl;
	std::cout << "son.y: 值: " << son.y << std::endl;
	std::cout << "son.y: 值: " << *((int*)(&son) + 2) << std::endl;

	system("pause");
	return 0;
}