#include <iostream>
#include <Windows.h>

template <typename T>
struct less {

	//实现后可以直接把该数据结构的对象当函数使用
	bool operator()(const T& left, const T& right) {
		return (left < right);
	}
};

template <typename T,
	typename CompMethod = less<T>> //比较方法，默认比较小于
struct test {

	//实现后可以直接把该数据结构的对象当函数使用
	bool operator()(const T& left, const T& right) {
		CompMethod method;         //声明一个CompMethod对象
		return method(left, right);//伪函数，直接把对象当函数使用
	}
};

int main() {
	int l = 6, r = 8;

	test<int> comp;
	bool result = comp(l, r); //伪函数，直接把对象当函数使用

	std::cout << "result: " << result << std::endl;

	system("pause");
	return 0;
}