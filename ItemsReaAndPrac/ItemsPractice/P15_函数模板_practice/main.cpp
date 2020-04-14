#include <iostream>
#include <Windows.h>
#include <string>

template <typename T>
class A {
public:
	A(T t = 0) { this->t = t; }

	//ģ�������Ԫ��������д��
	template <typename T>
	friend A<T> addA(const A<T>& a, const A<T>& b);

	//ģ����ľ�̬��������
	static T s;

private:
	T t;
};

//ģ����ľ�̬������ʼ��
template <typename T> T A<T>::s = 10;

//ģ�������Ԫ��������д��
template <typename T>
A<T> addA(const A<T>& a, const A<T>& b) {
	A<T> ret;
	ret.t = a.t + b.t;
	return ret;
}

int Max(int a, int b) {
	std::cout << "���� int Max(int a, int b)\n";
	return a > b ? a : b;
}

//float Max(float a, float b) {
//	return a > b ? a : b;
//}
//
//char Max(char a, char b) {
//	return a > b ? a : b;
//}

//����ģ�壬 ������������������ͬ�� ����������������������
template <typename T, typename T1>
T Max(T a, T1 b) {
	std::cout << "���� T Max(T a, T b)\n";
	return a > b ? a : b;
}

int main(void) {
	int a = 3;
	int b = 5;

	A<int> t(a);
	A<int> h(b);

	A<int> g = addA(t, h);
	 

	/*
								+---��������
	 ����д�� Max(a, b) �� Max<int, int>(a, b) 
	*/
	/*std::cout << "[int]Max(a, b) = " << Max(a, b) << std::endl;
	
	float c = 4.3f;
	float d = 5.6f;
	std::cout << "[float]Max(c, d) = " << Max(c, d) << std::endl;

	char e = 'e';
	char f = 'f';
	std::cout << "[char]Max(e, f) = " << Max(e, f) << std::endl;*/

	//����ģ�庯��ʱ���������Զ���ʽ����ת��
	//����������ͨ���غ�����ģ�庯��������ʱ������ѡ����ͨ���غ���
	//Max(a, b);
	//����Ҫָ��ʹ��ģ�庯��ʱ�������������д����
	//����������Լ��ϲ���������Ҳ���Բ���
	//Max<>(a, b);


	system("pause");
	return 0;
}