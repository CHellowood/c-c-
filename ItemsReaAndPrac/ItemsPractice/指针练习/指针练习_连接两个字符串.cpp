#include <iostream>

using namespace std;

void str(char *a, char *b, char *c) {
	int a_len = strlen(a);
	int b_len = strlen(b);

	if(a_len <= 1 && *a == NULL) a_len = 0;
	if(b_len <= 1 && *b == NULL) b_len = 0;
	if(a_len == 0 && b_len == 0) {
		cout << "�����ַ�����Ϊ��!!!!!!" << endl;
		return;
	}else if (a_len == 0 || b_len == 0){
		cout << "��һ���ַ���Ϊ��!!!" << endl;
		return;
	}
	cout << "�ַ���1�ĳ���Ϊ: " << a_len << endl;
	cout << "�ַ���2�ĳ���Ϊ: " << b_len << endl;

	for(int i=0; i<a_len; i++) {
		*(c+i) = *(a+i);
		if(i == a_len-1) {
			for(int j=0; j<b_len; j++) {
				*(c+i+j+1) = *(b+j);
			}
		}
	}
}

int main21() {
	char a[64] = {0};
	char b[64] = {0};
	char c[128] = {0};

	cout << "�ַ���1 :";
	gets(a);

	cout << "�ַ���2: ";
	gets(b);

	str(a, b, c);

	cout << "���Ӻ���ַ���: " << c << endl;

	system("pause");
	return 0;
}