#include <iostream>
#include <Windows.h>
#include "LinkStack.h"

using namespace std;

int main(void) {
	Stack stack;

	cout << endl << "<------��ʼ����ʽջ------>" << endl;
	if (!initStack(stack)) {
		cout << "��ʼ��ջʧ��!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "��ʼ��ջ�ɹ�!" << endl;

	cout << endl << "<------��ջ------>" << endl;
	int i = 0;

	cout << "��ջԪ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		Link* node = new Link;
		if (!node) {
			cout << "main:��ջ:node�ڴ�����ʧ��!" << endl;
			continue;
		}

		cout << "\n��ջԪ��:";
		cin >> node->data;
		enterStack(stack, node);

		printStack(stack);
	}

	cout << endl << "<------��ջ------>" << endl;
	
	cout << "��ջԪ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		Link ret;
		if (!outStack(stack, ret)) {
			cout << "��ջʧ��!" << endl;
			continue;
		}
		cout << "\n��ջ�ɹ�!" << endl;
		cout << "��ջ����: " << ret.data << endl;
		printStack(stack);
	}

	cout << endl << "<------����ջ------>" << endl;

	destroyStack(stack);

	system("pause");
	return 0;
}
