#include <iostream>
#include <stdlib.h>

class Father {
public:
	virtual void test1() { std::cout << "Father::test1\n"; }
	virtual void test2() { std::cout << "Father::test2\n"; }
	virtual void test3() { std::cout << "Father::test3\n"; }
	virtual void test4() { std::cout << "Father::test4\n"; }
	void test5() { std::cout << "���麯����Father::test5\n"; }

public://Ϊ�˷�����ԣ� �ص�д��publicȨ��
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

public://Ϊ�˷�����ԣ� �ص�д��publicȨ��
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
	son�����ڴ�ṹ������

	son : size = 24
	+--- 
	�麯����ָ��1 : size = 4
	���ݳ�Ա x    : size = 4
	���ݳ�Ա y    : size = 4
	�麯����ָ��2 : size = 4
	���ݳ�Ա m    : size = 4
	���ݳ�Ա n    : size = 4
	*/

	std::cout << "son: size: " << sizeof(son) << std::endl;
	std::cout << "son: ��ַ: " << &son << std::endl;

	//ȡ��һ���麯����ָ��
	int* vir = (int*) * (int*)(&son);
	std::cout << vir << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "��һ���麯����ĵ�" << i+1 << "���麯��: ";
		((test_t)*(vir + i))();
	}

	std::cout << "son.x: ֵ: " << son.x << std::endl;
	std::cout << "son.x: ֵ: " << *((int*)(&son) + 1) << std::endl;
	std::cout << "son.x: ��ַ: " << (int*)(&son) + 1 << std::endl;

	std::cout << "son.y: ֵ: " << son.y << std::endl;
	std::cout << "son.y: ֵ: " << *((int*)(&son) + 2) << std::endl;
	std::cout << "son.y: ��ַ: " << (int*)(&son) + 2 << std::endl;

	//ȡ�ڶ����麯����ָ��
	int* vir1 = (int*)*((int*)(&son) + 3);

	for (int i = 0; i < 4; i++) {
		std::cout << "�ڶ����麯����ĵ�" << i + 1 << "���麯��: ";
		((test_t) * (vir1 + i))();
	}

	std::cout << "son.m: ֵ: " << son.m << std::endl;
	std::cout << "son.m: ֵ: " << *((int*)(&son) + 4) << std::endl;
	std::cout << "son.m: ��ַ: " << (int*)(&son) + 4 << std::endl;

	std::cout << "son.n: ֵ: " << son.n << std::endl;
	std::cout << "son.n: ֵ: " << *((int*)(&son) + 5) << std::endl;
	std::cout << "son.n: ��ַ: " << (int*)(&son) + 5 << std::endl;

	system("pause");
	return 0;
}