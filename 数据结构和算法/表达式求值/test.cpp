#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "Calculation.h"

using namespace std;

int main(void) {
	vector<char> str;
	vector<int> number;
	char c[] = {"25*4 + 100/4- 15"};
	input(number, str, c);

	for (int i = 0; i < number.size(); i++) {
		cout << " " << number[i];
		if (i < str.size()) {
			cout << " " << str[i];
		}
	}
	result(number, str);
	cout << " = " << number[0] << endl;
	

	system("pause");
	return true;
}