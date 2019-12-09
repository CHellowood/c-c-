#include "Calculation.h"

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

//�ӿ���̨�����ַ����ֱ��ʽ,Ȼ���ַ�����ת���������浽number��,��������浽str��
//����̨�����ԵȺ�(=)��β
void input(vector<int>& number, vector<char>& str) {
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
			number.push_back(num);
			num = 0;
			if (ch == '=') break;
			if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
				str.push_back(ch);
		}
	}
}

//�ѿ���̨����ĳ���_str[]�������ַ����ֱ��ʽ,_str[]�����ԵȺ�(=)��β,����ͬ��
void input(vector<int>& number, vector<char>& str, char _str[]) {
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
			number.push_back(num);
			num = 0;
			//if (ch == '=') break;
			if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
				str.push_back(ch);
			if (ch == '\0') break;
		}
	}
}

//������,��ʽ: number[i] str[i] number[i+1],
//����number[i]=2,str[i]='+',number[i+1]=5,�������2+5
//���ȼ��� ��(*)��(/)
void result(vector<int>& number, vector<char>& str) {
	vector<int>::iterator iter_i = number.begin();
	for (vector<char>::iterator iter_c = str.begin(); iter_c != str.end();) {

		switch (*iter_c) {
		case '*':
			*(iter_i) = *(iter_i) * *(iter_i + 1);
			iter_c = str.erase(iter_c);
			number.erase(iter_i + 1);
			break;
		case '/':
			*(iter_i) = *(iter_i) / *(iter_i + 1);
			iter_c = str.erase(iter_c);
			number.erase(iter_i + 1);
			break;
		default:
			iter_c++;
			iter_i++;
		}
	}

	iter_i = number.begin();
	for (vector<char>::iterator iter_c = str.begin(); iter_c != str.end();) {
		switch (*iter_c) {
		case '+':
			*(iter_i) = *(iter_i)+*(iter_i + 1);
			iter_c = str.erase(iter_c);
			number.erase(iter_i + 1);
			break;
		case '-':
			*(iter_i) = *(iter_i)-*(iter_i + 1);
			iter_c = str.erase(iter_c);
			number.erase(iter_i + 1);
			break;
		default:
			iter_c++;
			iter_i++;
		}
	}
}