#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main6(void) {
	int *a=NULL, *p=NULL, b[10][10] = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},{6, 66, 666}};
	a = &b[0][0];

	cout << "a = " << a << "  *a = " << *a << endl; 

	*a++ = 10;
	cout << "a = " << a << "  *a = " << *a << endl; 
	//for(int i=0; i<sizeof(b)/sizeof(int); i++) {
		//cout << "b[" << i << "]=" << b[i/10][i%10] << "  ";
	//}

	printf("\nc: *a=%d  *a-1=%d  *(a-1)=%d\n", *a, *a-1, *(a-1));
	cout << "c++: *a=" << *a << endl;

	system("pause");
	return 0;
}