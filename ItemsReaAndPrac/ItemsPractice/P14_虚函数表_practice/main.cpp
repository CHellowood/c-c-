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

typedef void (*test_t)(void);

int main() {
	Father father;

/*
father对象内存分析：

father ：size = 12
+---
	虚函数表指针 ：size = 4
	数据成员：x  ：size = 4
	数据成员：y  ：size = 4
+---
*/

	std::cout << "father : size: " << sizeof(father) << std::endl;
	std::cout << "father : 地址: " << &father << std::endl;

	//取虚函数表指针
	/*
				  +---转成指针
				  |  +---取内容
				　|	 |	 +---转成指针	
				  |  |   |       +---取对象father的地址
	int* vir = (int*)*(int*)(&father);
	*/
	int* vir = (int*)*(int*)(&father);

	/*
		+---转成函数
		|	 +---取内容
		|	 |	+---虚函数表的第一个元素的地址
		|	 |	|	 +---元素偏移量
	((test_t)*(vir + 0))();
	*/
	((test_t) * (vir + 0))();
	((test_t) * (vir + 1))();
	((test_t) * (vir + 2))();
	((test_t) * (vir + 3))();

	/*
	 +---取内容		
	 |   +---转成指针
	 |   |       +---转成整数	
	 |	 |		 |      +---取对象father的地址
	 |	 |		 |		|		 +---字节偏移量	
	 *((int*)(((int)(&father)) + 4))
	*/
	std::cout << "father.x: 地址: " << &father.x << std::endl;
	std::cout << "father.x: 地址: " << ((int*)(((int)(&father)) + 4)) << std::endl;
	std::cout << "father.x: 值: " << father.x << std::endl;
	std::cout << "father.x: 值: " << *((int*)(((int)(&father)) + 4)) << std::endl;

	/*
	 +---取内容
	 |      +---转成指针
	 |      |      +---取对象father的地址
	 |      |      |        +---元素偏移量
	 *(((int*)(&father)) + 2)
	*/
	std::cout << "father.y: 地址: " << &father.y << std::endl;
	std::cout << "father.y: 地址: " << (((int*)(&father)) + 2) << std::endl;
	std::cout << "father.y: 值: " << father.y << std::endl;
	std::cout << "father.y: 值: " << *(((int*)(&father)) + 2) << std::endl;

	system("pause");
	return 0;
}