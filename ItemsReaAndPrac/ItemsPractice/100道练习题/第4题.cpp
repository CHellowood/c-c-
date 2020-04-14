/*
第4题 请编写一个函数void fun(char *tt,int pp[]),统计在tt字符中"a"到"z"26各字母各自出现的次数，并依次放在pp所指的数组中。
*/

#include <iostream>

using namespace std;

void fun(char *tt, int pp[], int &number) {
	int n=0, num=0;
	for(char i='a'; i<='z'; i++) {
		for(int j=0; j<strlen(tt); j++) {
			if(*(tt+j) == i) {
				num++;	
				number++;
			}
		}
		pp[n++] = num;
		num = 0;
	}
}

int main4(void) {
	char tt[64];
	int number=0, pp[26]={0};

	cout << "第4题 请编写一个函数void fun(char *tt,int pp[]),统计在tt字符中'a'到'z'26各字母各自出现的次数，并依次放在pp所指的数组中。" << endl;

	while(true) {

		cout << endl << "--------------------------------" << endl;

		cout<< "输入字符串: ";
		cin >> tt;

		fun(tt, pp, number);

		cout << endl << "----------字符出现次数----------" << endl;

		for(int i=0; i<sizeof(pp)/sizeof(int); i++) {
			cout << (char)('a'+i) << " 出现的次数: " << pp[i] << "次" << endl; 
		}

		cout << endl << "'a'-'z'26个字母共出现" << number << "次";
	}

	system("pause");
	return 0;
}