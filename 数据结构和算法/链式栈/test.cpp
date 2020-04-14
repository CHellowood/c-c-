#include <iostream>
#include <Windows.h>
#include "LinkStack.h"

using namespace std;

int main(void) {
	Stack stack;

	cout << endl << "<------初始化链式栈------>" << endl;
	if (!initStack(stack)) {
		cout << "初始化栈失败!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "初始化栈成功!" << endl;

	cout << endl << "<------入栈------>" << endl;
	int i = 0;

	cout << "入栈元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		Link* node = new Link;
		if (!node) {
			cout << "main:入栈:node内存申请失败!" << endl;
			continue;
		}

		cout << "\n入栈元素:";
		cin >> node->data;
		enterStack(stack, node);

		printStack(stack);
	}

	cout << endl << "<------出栈------>" << endl;
	
	cout << "出栈元素个数:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		Link ret;
		if (!outStack(stack, ret)) {
			cout << "出栈失败!" << endl;
			continue;
		}
		cout << "\n出栈成功!" << endl;
		cout << "出栈的是: " << ret.data << endl;
		printStack(stack);
	}

	cout << endl << "<------销毁栈------>" << endl;

	destroyStack(stack);

	system("pause");
	return 0;
}
