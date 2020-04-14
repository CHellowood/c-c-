#include <iostream>
#include <Windows.h>
#include "SqStack.h"

using namespace std;



int main(void) {
	SqStack stack;

	cout << endl << "<------初始化顺序栈------>" << endl;
	if (!initStack(stack)) {
		cout << "顺序栈初始化失败!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "顺序栈初始化成功!" << endl;

	cout << endl << "<------入栈------>" << endl;
	int i = 0, n = 0;

	cout << "入栈的元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cin >> n;
		if (!enterStack(stack, n)) {
			cout << "入栈失败!" << endl;
		}
		else {
			cout << "入栈成功!" << endl;
		}
		printStack(stack);
	}

	cout << endl << "<------出栈------>" << endl;

	cout << "出栈的元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		if (!outStack(stack, n)) {
			cout << "出栈失败!" << endl;
		}
		else {
			cout << "出栈成功!" << endl;
			cout << "出栈的元素是: " << n << endl;
		}
	}

	cout << endl << "<------获取栈顶元素------>" << endl;

	if (!getStackTop(stack, n)) {
		cout << "获取失败!" << endl;
	}
	else {
		cout << "获取成功!" << endl;
		cout << "栈顶元素是:" << n << endl;	
	}

	cout << endl << "<------销毁顺序栈------>" << endl;

	destroyStack(stack);

	system("pause");
	return 0;
}
