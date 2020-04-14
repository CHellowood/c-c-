#include <iostream>
#include <Windows.h>
#include <string>

template <typename T>
class A {
public:
	A(T t = 0) { this->t = t; }

	//模板类的友元函数声明写法
	template <typename T>
	friend A<T> addA(const A<T>& a, const A<T>& b);

	//模板类的静态变量声明
	static T s;

private:
	T t;
};

//模板类的静态变量初始化
template <typename T> T A<T>::s = 10;

//模板类的友元函数定义写法
template <typename T>
A<T> addA(const A<T>& a, const A<T>& b) {
	A<T> ret;
	ret.t = a.t + b.t;
	return ret;
}

int Max(int a, int b) {
	std::cout << "调用 int Max(int a, int b)\n";
	return a > b ? a : b;
}

//float Max(float a, float b) {
//	return a > b ? a : b;
//}
//
//char Max(char a, char b) {
//	return a > b ? a : b;
//}

//函数模板， 作用与上三个函数相同， 不过参数可以是任意类型
template <typename T, typename T1>
T Max(T a, T1 b) {
	std::cout << "调用 T Max(T a, T b)\n";
	return a > b ? a : b;
}

int main(void) {
	int a = 3;
	int b = 5;

	A<int> t(a);
	A<int> h(b);

	A<int> g = addA(t, h);
	 

	/*
								+---参数类型
	 可以写成 Max(a, b) 或 Max<int, int>(a, b) 
	*/
	/*std::cout << "[int]Max(a, b) = " << Max(a, b) << std::endl;
	
	float c = 4.3f;
	float d = 5.6f;
	std::cout << "[float]Max(c, d) = " << Max(c, d) << std::endl;

	char e = 'e';
	char f = 'f';
	std::cout << "[char]Max(e, f) = " << Max(e, f) << std::endl;*/

	//调用模板函数时参数不会自动隐式类型转换
	//当参数与普通重载函数和模板函数都符合时，优先选择普通重载函数
	//Max(a, b);
	//当需要指定使用模板函数时，可以用下面的写法，
	//尖括号里可以加上参数的类型也可以不加
	//Max<>(a, b);


	system("pause");
	return 0;
}