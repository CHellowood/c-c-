#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void px(int a[], int len) {
	for(int i=0; i<len-1; i++) {
		for(int j=0; j<len-1-i; j++) {
			if(a[j]>a[j+1]) {
				int b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	}
}

void px1(int *a,int len) {
	for(int i=0; i<len-1; i++) {
		for(int j=0; j<len-1-i; j++) {
			if(*(a+j)>*(a+j+1)) {
				int b = *(a+j);
				*(a+j) = *(a+j+1);
				*(a+j+1) = b;
			}
		}
	}
}

int main11(void) {
	int a[64] = {0};
	srand((unsigned)time(NULL));
	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		
		a[i] = rand();
	}

	px1(a, sizeof(a)/sizeof(a[0]));

	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		cout << a[i] << "  ";
	}

	system("pause");
	return 0;
}