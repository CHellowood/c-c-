#include <iostream>

using namespace std;

void nc1(int num) {
	int *p = NULL; 
	p = new int[num];
	
	if(p) {cout << "nc1 �ڴ�����ɹ�,������" << num*sizeof(int) << "Byte!" << endl;}
	else {cout << "nc1 �ڴ�����ʧ��!!!" << endl; return;}

	system("pause");
	delete[] p;
}

int main(void) {
	int num = 0;

	cout << "��Ҫ��������ڴ�?(��λ: 1/4 Byte)" << endl;
	cin >> num;

	nc1(num);

	system("pause");
	return 0;
}