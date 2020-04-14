#include "ExpEvaStack.h"

//字符数字转整数(正数(0-9))
int char_turn_int(char& ch) {
	for (int i = 0; i <= 9; i++) {
		if (ch == i + 48) {
			return i;
		}
	}
	cout << ch << " 不是数字!" << endl;
	return -1;
}

//从控制台输入字符数字表达式,然后字符数字转成整数保存到stack.data里,运算符保存到stack.symbol里
//控制台输入以等号(=)结尾
void input(Stack& stack) {
	int num = 0;
	while (true) {
		char ch = ' ';
		while (ch == ' ') {
			cin >> ch;
		}

		if (ch >= '0' && ch <= '9') {
			int n = char_turn_int(ch);
			if (n < 0) {
				cout << "运算出错!" << endl;
				break;
			}

			num = num * 10 + n;
		}
		else {
			Link* p = new Link;
			p->data = num;
			p->symbol = ' ';
			num = 0;

			if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
				p->symbol = ch;

			enterStack(stack, *p);

			if (ch == '=') break;
		}
	}
}

//把控制台输入改成用_str[]来接收字符数字表达式,_str[]不用以等号(=)结尾,其余同上
void input(Stack& stack, char _str[]) {
	int num = 0, i = 0;
	while (true) {
		char ch = ' ';
		while (ch == ' ') {
			ch = _str[i++];
		}

		if (ch >= '0' && ch <= '9') {
			int n = char_turn_int(ch);
			if (n < 0) {
				cout << "运算出错!" << endl;
				break;
			}

			num = num * 10 + n;
		}
		else {
			Link* p = new Link;
			p->data = num;
			p->symbol = ' ';
			num = 0;

			if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
				p->symbol = ch;

			enterStack(stack, *p);

			if (ch == '\0') break;
		}
	}
}

//计算结果,公式: number[i] str[i] number[i+1],
//假设number[i]=2,str[i]='+',number[i+1]=5,结果就是2+5
//优先计算 乘(*)除(/)
void result(Stack& stack) {
	for (Link* p = stack.tail->naxt;  p->naxt;) {
		switch (p->symbol) {
		case '*':
			p->data = p->data * p->naxt->data;
			p->symbol = p->naxt->symbol;
			outStack(stack, p->naxt);
			break;
		case '/':
			p->data = p->data / p->naxt->data;
			p->symbol = p->naxt->symbol;
			outStack(stack, p->naxt);
			break;
		default:
			p = p->naxt;
		}
	}

	for (Link* p = stack.tail->naxt; p->naxt;) {
		switch (p->symbol) {
		case '+':
			p->data = p->data + p->naxt->data;
			p->symbol = p->naxt->symbol;
			outStack(stack, p->naxt);
			break;
		case '-':
			p->data = p->data - p->naxt->data;
			p->symbol = p->naxt->symbol;
			outStack(stack, p->naxt);
			break;
		default:
			p = p->naxt;
		}
	}
}