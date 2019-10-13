#include <iostream>

using namespace std;

void _b(double b[], double a[], int len) {
	for(int i=0; i<len; i++) {
		b[i] = a[i];
	}
}

void _c(double *c, double *a, int len) {
	for(int i=0; i<len; i++) {
		*(c+i) = *(a+i);
	}
}

void _d(double *d, double *a, double *l) {
	int i = 0;
	while(1){
		*(d+i) = *(a+i); 
		if(a+i == l) break; 

		i++;
	}
}

void print(double *p, int len) {
	for(int i=0; i<len; i++) {
		if(i%5 == 0) cout << endl;
		cout << "下标 " << i << " : " << *(p+i) << "\t";
	}
}

int main13(void) {
	double a[5] = {1.1,2.3,3.7,4.9,5.2};
	double b[64] = {0};
	double c[64] = {0};
	double d[64] = {0};
	
	_b(b, a, sizeof(a)/sizeof(a[0]));
	_c(c, a, sizeof(a)/sizeof(a[0]));
	_d(d, a, a+sizeof(a)/sizeof(a[0])-1);

	cout << endl << endl << "--------数组b--------" << endl << endl;
	print(b, sizeof(b)/sizeof(b[0]));

	cout << endl << endl << "--------数组c--------" << endl << endl;
	print(c, sizeof(c)/sizeof(c[0]));
	
	cout << endl << endl << "--------数组d--------" << endl << endl;
	print(d, sizeof(d)/sizeof(d[0]));

	system("pause");
	return 0;
}