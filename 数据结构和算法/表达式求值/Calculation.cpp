#include "Calculation.h"

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

//从控制台输入字符数字表达式,然后字符数字转成整数保存到number里,运算符保存到str里
//控制台输入以等号(=)结尾
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
				cout << "运算出错!" << endl;
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

//把控制台输入改成用_str[]来接收字符数字表达式,_str[]不用以等号(=)结尾,其余同上
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
				cout << "运算出错!" << endl;
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

//计算结果,公式: number[i] str[i] number[i+1],
//假设number[i]=2,str[i]='+',number[i+1]=5,结果就是2+5
//优先计算 乘(*)除(/)
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