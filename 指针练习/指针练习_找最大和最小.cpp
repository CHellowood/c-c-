#include <iostream>
#include <time.h>

using namespace std;

void dx(int *a, int len) {
	int d = 0;
	int x = 0;
	int *d1 = a;
	int *x1 = a;
	int ret = 0;

	// ������
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
		cout << "������Ϊ�ջ�Ϊ��!!!" << endl;
		return;
	}

	cout << "�±�Ϊ " << d << " �������: " << *d1 << endl;
	// ��С����
	for(int i=0; i<len; i++) {
		if(*x1>*(x1+i)) {
			int b = *x1;
			*x1 = *(x1+i);
			*(x1+i) = b;
			x = i;
		}
	}
	
	cout << "�±�Ϊ " << x << " ������С: " << *x1 << endl;
}

int main12(void) {
	int a[64] = {0};

	srand((unsigned)time(NULL));
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		a[i] = rand();
		cout << "�±�" << i << ": " << a[i] << endl;
	}

	dx(a, sizeof(a)/sizeof(a[0]));


	system("pause");
	return 0;
}