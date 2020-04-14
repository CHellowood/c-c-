#include <iostream>
#include <Windows.h>
#include "SqStack.h"

using namespace std;



int main(void) {
	SqStack stack;

	cout << endl << "<------��ʼ��˳��ջ------>" << endl;
	if (!initStack(stack)) {
		cout << "˳��ջ��ʼ��ʧ��!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "˳��ջ��ʼ���ɹ�!" << endl;

	cout << endl << "<------��ջ------>" << endl;
	int i = 0, n = 0;

	cout << "��ջ��Ԫ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cin >> n;
		if (!enterStack(stack, n)) {
			cout << "��ջʧ��!" << endl;
		}
		else {
			cout << "��ջ�ɹ�!" << endl;
		}
		printStack(stack);
	}

	cout << endl << "<------��ջ------>" << endl;

	cout << "��ջ��Ԫ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		if (!outStack(stack, n)) {
			cout << "��ջʧ��!" << endl;
		}
		else {
			cout << "��ջ�ɹ�!" << endl;
			cout << "��ջ��Ԫ����: " << n << endl;
		}
	}

	cout << endl << "<------��ȡջ��Ԫ��------>" << endl;

	if (!getStackTop(stack, n)) {
		cout << "��ȡʧ��!" << endl;
	}
	else {
		cout << "��ȡ�ɹ�!" << endl;
		cout << "ջ��Ԫ����:" << n << endl;	
	}

	cout << endl << "<------����˳��ջ------>" << endl;

	destroyStack(stack);

	system("pause");
	return 0;
}
