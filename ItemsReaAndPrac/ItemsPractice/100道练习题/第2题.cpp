/*
第2题 请编写函数fun，它的功能是：求出1到100之内能北7或者11整除，但不能
同时北7和11整除的所有证书，并将他们放在a所指的数组中，通过n返回这些数的个数。 
*/

#include <stdio.h>
#include <stdlib.h>

void fun(int *p, int *n) {
	int num=0;
	for(int i=1; i<=100; i++) {
		if(i%7 == 0 && i%11 != 0 || i%11 == 0 && i%7 != 0) {
			*p = i;
			num++;
			printf("%d 可以被7或11整除\n", *p++);
		}
	}
	*n = num;
}

int main2(void) {
	int a, b[64] = {0};

	fun(b, &a);
	printf("\n能被7整除或能被11整除但不能被7和11同时整除的有 %d 个\n", a);
	//printf("%d 可以被7或11整除 Ox%p\n", b[1][0], &b[1][0]);

	system("pause");
	return 0;
}