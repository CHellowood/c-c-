#include <iostream>
#include <time.h>

using namespace std;

void dx(int *a, int len) {
	int d = 0;
	int x = 0;
	int *d1 = a;
	int *x1 = a;
	int ret = 0;

	// 最大的数
	for(int i=0; i<len; i++) {
		if(*(d1+i) == 0) ret++;
		if(*d1<*(d1+i)) {
			int b = *d1;
			*d1= *(d1+i);
			*(d1+i) = b;
			d = i;
		}
	}
	if(ret >= len) {
		cout << "该数组为空或为零!!!" << endl;
		return;
	}

	cout << "下标为 " << d << " 的数最大: " << *d1 << endl;
	// 最小的数
	for(int i=0; i<len; i++) {
		if(*x1>*(x1+i)) {
			int b = *x1;
			*x1 = *(x1+i);
			*(x1+i) = b;
			x = i;
		}
	}
	
	cout << "下标为 " << x << " 的数最小: " << *x1 << endl;
}

int main12(void) {
	int a[64] = {0};

	srand((unsigned)time(NULL));
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		a[i] = rand();
		cout << "下标" << i << ": " << a[i] << endl;
	}

	dx(a, sizeof(a)/sizeof(a[0]));


	system("pause");
	return 0;
}