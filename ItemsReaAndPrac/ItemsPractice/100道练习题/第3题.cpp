/*
第3题 请编写函数void fun(int x,int pp[],int *n),它的功能是：求出能整除x且不是
偶数的各整数，并按从小到大的顺序放在pp所指的数组中，这些除数的个数通过形参n返回。 
*/

#include <iostream>

using namespace std;

void fun(int x, int pp[], int *n) {
	int num=0;
	for(int i=1; i<=x; i++) {
		if(x%i == 0 && i%2 != 0) {
			pp[num] = i;
			num++;
		}
	}
	*n = num;
}

int main3(void) {
	int x, n, pp[64];

	cout << "第3题 请编写函数void fun(int x,int pp[],int *n),它的功能是：求出能整除x且不是" << endl
         << "偶数的各整数，并按从小到大的顺序放在pp所指的数组中，这些除数的个数通过形参n返回。 " << endl;
	
	while(1) {
		cout << endl << "x: ";
		cin >> x;

		fun(x, pp, &n);

		cout << "pp: ";
		for(int i=0; i<n; i++) {
			cout << pp[i] << ", ";
		}
		cout << endl << "共" << n << "个" << endl;
	}
	system("pause");
	return 0;
}