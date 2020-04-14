#include <iostream>

using namespace std;

void str(char *a, char *b, char *c) {
	int a_len = strlen(a);
	int b_len = strlen(b);

	if(a_len <= 1 && *a == NULL) a_len = 0;
	if(b_len <= 1 && *b == NULL) b_len = 0;
	if(a_len == 0 && b_len == 0) {
		cout << "两个字符串都为空!!!!!!" << endl;
		return;
	}else if (a_len == 0 || b_len == 0){
		cout << "有一个字符串为空!!!" << endl;
		return;
	}
	cout << "字符串1的长度为: " << a_len << endl;
	cout << "字符串2的长度为: " << b_len << endl;

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

	cout << "字符串1 :";
	gets(a);

	cout << "字符串2: ";
	gets(b);

	str(a, b, c);

	cout << "连接后的字符串: " << c << endl;

	system("pause");
	return 0;
}