/*
��4�� ���дһ������void fun(char *tt,int pp[]),ͳ����tt�ַ���"a"��"z"26����ĸ���Գ��ֵĴ����������η���pp��ָ�������С�
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

	cout << "��4�� ���дһ������void fun(char *tt,int pp[]),ͳ����tt�ַ���'a'��'z'26����ĸ���Գ��ֵĴ����������η���pp��ָ�������С�" << endl;

	while(true) {

		cout << endl << "--------------------------------" << endl;

		cout<< "�����ַ���: ";
		cin >> tt;

		fun(tt, pp, number);

		cout << endl << "----------�ַ����ִ���----------" << endl;

		for(int i=0; i<sizeof(pp)/sizeof(int); i++) {
			cout << (char)('a'+i) << " ���ֵĴ���: " << pp[i] << "��" << endl; 
		}

		cout << endl << "'a'-'z'26����ĸ������" << number << "��";
	}

	system("pause");
	return 0;
}