#include <iostream>
#include <Windows.h>

//������ʱ���final�� ����Ͳ��ܱ�������̳���
class test final{
};

//���磺
class test1 : public test {
};


class test2 {
public:
	//�����麯��ʱ���final���ᵼ��������̳и���ʱ, 
	//ֻ�ܼ̳и��麯�������޷���д���麯��
	//ֻ���ڶ���ʱ��ӣ� ������ʵ��ʱ���
	virtual void testFinal() final{}
};

//���磺
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
	//����д������麯��ʱ���override, 
	//�����Ķ�������֪����������д������麯��
	//���override֮��������麯���ĺ�������
	//������麯���ĺ�������һ�£������û�и��࣬��������ᱨ��
	//���磺
	void testoverride() override{}
};
