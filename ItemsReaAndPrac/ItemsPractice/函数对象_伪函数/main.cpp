#include <iostream>
#include <Windows.h>

template <typename T>
struct less {

	//ʵ�ֺ����ֱ�ӰѸ����ݽṹ�Ķ��󵱺���ʹ��
	bool operator()(const T& left, const T& right) {
		return (left < right);
	}
};

template <typename T,
	typename CompMethod = less<T>> //�ȽϷ�����Ĭ�ϱȽ�С��
struct test {

	//ʵ�ֺ����ֱ�ӰѸ����ݽṹ�Ķ��󵱺���ʹ��
	bool operator()(const T& left, const T& right) {
		CompMethod method;         //����һ��CompMethod����
		return method(left, right);//α������ֱ�ӰѶ��󵱺���ʹ��
	}
};

int main() {
	int l = 6, r = 8;

	test<int> comp;
	bool result = comp(l, r); //α������ֱ�ӰѶ��󵱺���ʹ��

	std::cout << "result: " << result << std::endl;

	system("pause");
	return 0;
}