#include <iostream>
#include <stdlib.h>

class Father {
public:
	virtual void test1() { std::cout << "Father::test1\n"; }
	virtual void test2() { std::cout << "Father::test2\n"; }
	virtual void test3() { std::cout << "Father::test3\n"; }
	virtual void test4() { std::cout << "Father::test4\n"; }
	void test5() { std::cout << "非虚函数：Father::test5\n"; }

public://为了方便测试， 特地写成public权限
	int x = 'x';
	int y = 'y';
	static int z;
};
int Father::z = 'z';

class Mother {
public:
	virtual void test1() { std::cout << "Mother::test1\n"; }
	virtual void test2() { std::cout << "Mother::test2\n"; }
	virtual void test3() { std::cout << "Mother::test3\n"; }
	virtual void test4() { std::cout << "Mother::test4\n"; }

public://为了方便测试， 特地写成public权限
	int m = 'm';
	int n = 'n';
};

class Son : public Father , public Mother {
public:
	void test1() { std::cout << "Son::test1\n"; }
	virtual void test6() { std::cout << "Son::test6\n"; }
};


typedef void (*test_t)(void);

int main() {
	Son son;

	/*
	son对象内存结构分析：

	son : size = 24
	+--- 
	虚函数表指针1 : size = 4
	数据成员 x    : size = 4
	数据成员 y    : size = 4
	虚函数表指针2 : size = 4
	数据成员 m    : size = 4
	数据成员 n    : size = 4
	*/

	std::cout << "son: size: " << sizeof(son) << std::endl;
	std::cout << "son: 地址: " << &son << std::endl;

	//取第一个虚函数表指针
	int* vir = (int*) * (int*)(&son);
	std::cout << vir << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "第一个虚函数表的第" << i+1 << "个虚函数: ";
		((test_t)*(vir + i))();
	}

	std::cout << "son.x: 值: " << son.x << std::endl;
	std::cout << "son.x: 值: " << *((int*)(&son) + 1) << std::endl;
	std::cout << "son.x: 地址: " << (int*)(&son) + 1 << std::endl;

	std::cout << "son.y: 值: " << son.y << std::endl;
	std::cout << "son.y: 值: " << *((int*)(&son) + 2) << std::endl;
	std::cout << "son.y: 地址: " << (int*)(&son) + 2 << std::endl;

	//取第二个虚函数表指针
	int* vir1 = (int*)*((int*)(&son) + 3);

	for (int i = 0; i < 4; i++) {
		std::cout << "第二个虚函数表的第" << i + 1 << "个虚函数: ";
		((test_t) * (vir1 + i))();
	}

	std::cout << "son.m: 值: " << son.m << std::endl;
	std::cout << "son.m: 值: " << *((int*)(&son) + 4) << std::endl;
	std::cout << "son.m: 地址: " << (int*)(&son) + 4 << std::endl;

	std::cout << "son.n: 值: " << son.n << std::endl;
	std::cout << "son.n: 值: " << *((int*)(&son) + 5) << std::endl;
	std::cout << "son.n: 地址: " << (int*)(&son) + 5 << std::endl;

	system("pause");
	return 0;
}