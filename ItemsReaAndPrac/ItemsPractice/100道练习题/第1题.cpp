/*
第1题 m个人的成绩存放在score数组中，请编写函数fun,它的功能是：将低于
平均分的人作为函数值返回，将低于平均分的分数放在below所指定的函数中。 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun(int *p, int len) {
	int number=0, divi=0;
	for(int i=0; i<len; i++) {
		divi += *(p+i);
	}
	divi /= len;
	printf("平均分: %d\n", divi);

	for(int j=0; j<len; j++) {
		if(*(p+j) < divi) {
			number++;
			printf("第%d位学员的分数: %d, 低于平均分 %d.\n", j+1, *(p+j), divi);
		}
	}
	return number;
}

int main1(void) {
	int number=0, divide[10] = {55, 99, 30, 40, 50, 90, 77, 88, 99, 111};
	number = fun(divide, sizeof(divide)/sizeof(int));
	printf("\n总共有%d人的分数低于平均分.\n", number);

	system("pause");
	return 0;
}