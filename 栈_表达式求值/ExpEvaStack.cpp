#include "ExpEvaStack.h"

//�ַ�����ת����(����(0-9))
int char_turn_int(char& ch) {
	for (int i = 0; i <= 9; i++) {
		if (ch == i + 48) {
			return i;
		}
	}
	cout << ch << " ��������!" << endl;
	return -1;
}

//�ӿ���̨�����ַ����ֱ��ʽ,Ȼ���ַ�����ת���������浽stack.data��,��������浽stack.symbol��
//����̨�����ԵȺ�(=)��β
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
				cout << "�������!" << endl;
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

//�ѿ���̨����ĳ���_str[]�������ַ����ֱ��ʽ,_str[]�����ԵȺ�(=)��β,����ͬ��
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
				cout << "�������!" << endl;
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

//������,��ʽ: number[i] str[i] number[i+1],
//����number[i]=2,str[i]='+',number[i+1]=5,�������2+5
//���ȼ��� ��(*)��(/)
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