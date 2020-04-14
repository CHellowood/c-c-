/*
第5题 请编写一个函数void fun(int m,int k,int xx[]),该函数的功能是：将大于整数m且紧靠m的k各素数存入xx所指的数组中。 
*/

#include <iostream>
#include <Windows.h>

using namespace std;

void fun(int m, int k, int xx[]) {
	int num=0;

	for(int i=m+1; i<k; i++) {
		if(i == 2) {
			xx[num] = i;
			num++;
			continue;
		}
		for(int j=2; j<i; j++) {
			if(!(i%j)) break;
			if(j >= i-1) {
				xx[num] = i;
				num++;
			}
		}
	}
}


int main5(void) {
	int m=0, k=0, xx[64]={0};

	cout << "第5题 请编写一个函数void fun(int m,int k,int xx[]),该函数的功能是：将大于整数m且紧靠m的k各素数存入xx所指的数组中。" << endl;

	while(true) {
		go:
		cout << endl << "--------------------" << endl;

		cout << "m: ";
		while(!(cin >> m)) {
			cin.clear();
			cin.sync();

			cout << "输入出错!" << endl;
			goto go;
		}

		cout << "k: ";
		while(!(cin >> k)) {
			cin.clear();
			cin.sync();

			cout << "输入出错!" << endl;
			goto go;
		}

		if(m < 0) {
			cout << "m是负数!" << endl;
			continue;
		}else if(m == 0 && k == 0) {
			cout << endl << "m和k都为0" << endl;
			//system("pause");
			//break;
			continue;
		}else if(m > k) {
			cout << "m > k不符合题意!" << endl;
			continue;
		}

		fun(m, k, xx);

		cout << m << "到" << k << "之间的素数: ";

		for(int i=0; i<64; i++) {
			if(xx[i] > 0) 
			cout << xx[i] << "  ";
		}

	}

	system("pause");
	return 0;
}