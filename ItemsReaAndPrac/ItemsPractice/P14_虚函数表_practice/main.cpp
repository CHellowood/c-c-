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

typedef void (*test_t)(void);

int main() {
	Father father;

/*
father�����ڴ������

father ��size = 12
+---
	�麯����ָ�� ��size = 4
	���ݳ�Ա��x  ��size = 4
	���ݳ�Ա��y  ��size = 4
+---
*/

	std::cout << "father : size: " << sizeof(father) << std::endl;
	std::cout << "father : ��ַ: " << &father << std::endl;

	//ȡ�麯����ָ��
	/*
				  +---ת��ָ��
				  |  +---ȡ����
				��|	 |	 +---ת��ָ��	
				  |  |   |       +---ȡ����father�ĵ�ַ
	int* vir = (int*)*(int*)(&father);
	*/
	int* vir = (int*)*(int*)(&father);

	/*
		+---ת�ɺ���
		|	 +---ȡ����
		|	 |	+---�麯����ĵ�һ��Ԫ�صĵ�ַ
		|	 |	|	 +---Ԫ��ƫ����
	((test_t)*(vir + 0))();
	*/
	((test_t) * (vir + 0))();
	((test_t) * (vir + 1))();
	((test_t) * (vir + 2))();
	((test_t) * (vir + 3))();

	/*
	 +---ȡ����		
	 |   +---ת��ָ��
	 |   |       +---ת������	
	 |	 |		 |      +---ȡ����father�ĵ�ַ
	 |	 |		 |		|		 +---�ֽ�ƫ����	
	 *((int*)(((int)(&father)) + 4))
	*/
	std::cout << "father.x: ��ַ: " << &father.x << std::endl;
	std::cout << "father.x: ��ַ: " << ((int*)(((int)(&father)) + 4)) << std::endl;
	std::cout << "father.x: ֵ: " << father.x << std::endl;
	std::cout << "father.x: ֵ: " << *((int*)(((int)(&father)) + 4)) << std::endl;

	/*
	 +---ȡ����
	 |      +---ת��ָ��
	 |      |      +---ȡ����father�ĵ�ַ
	 |      |      |        +---Ԫ��ƫ����
	 *(((int*)(&father)) + 2)
	*/
	std::cout << "father.y: ��ַ: " << &father.y << std::endl;
	std::cout << "father.y: ��ַ: " << (((int*)(&father)) + 2) << std::endl;
	std::cout << "father.y: ֵ: " << father.y << std::endl;
	std::cout << "father.y: ֵ: " << *(((int*)(&father)) + 2) << std::endl;

	system("pause");
	return 0;
}