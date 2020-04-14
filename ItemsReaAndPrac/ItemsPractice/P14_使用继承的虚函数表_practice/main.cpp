#include <iostream>
#include <stdlib.h>

class Father {
public:
	virtual void test1() { std::cout << "Father::test1\n"; }
	virtual void test2() { std::cout << "Father::test2\n"; }
	virtual void test3() { std::cout << "Father::test3\n"; }
	virtual void test4() { std::cout << "Father::test4\n"; }
	void test5() { std::cout << "���麯����Father::test5\n"; }

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
	std::cout << "son: ��ַ: " << &son << std::endl;

	int* vir = (int*)*((int*)(&son));

	for (int i = 0; i < 5; i++) {
		std::cout << "��" << i + 1 << "���麯��: ";
		((test_t)*(vir + i))();
	}

	std::cout << "son.x: ��ַ: " << &son.x << std::endl;
	std::cout << "son.x: ��ַ: " << ((int*)(&son) + 1) << std::endl;
	std::cout << "son.x: ֵ: " << son.x << std::endl;
	std::cout << "son.x: ֵ: " << *((int*)(&son) + 1) << std::endl;

	std::cout << "son.y: ��ַ: " << &son.y << std::endl;
	std::cout << "son.y: ��ַ: " << ((int*)(&son) + 2) << std::endl;
	std::cout << "son.y: ֵ: " << son.y << std::endl;
	std::cout << "son.y: ֵ: " << *((int*)(&son) + 2) << std::endl;

	system("pause");
	return 0;
}