#include <iostream>

using namespace std;

void nc1(int num) {
	int *p = NULL; 
	p = new int[num];
	
	if(p) {cout << "nc1 内存申请成功,申请了" << num*sizeof(int) << "Byte!" << endl;}
	else {cout << "nc1 内存申请失败!!!" << endl; return;}

	system("pause");
	delete[] p;
}

int main(void) {
	int num = 0;

	cout << "需要申请多少内存?(单位: 1/4 Byte)" << endl;
	cin >> num;

	nc1(num);

	system("pause");
	return 0;
}