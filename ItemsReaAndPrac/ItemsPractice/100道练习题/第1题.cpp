/*
��1�� m���˵ĳɼ������score�����У����д����fun,���Ĺ����ǣ�������
ƽ���ֵ�����Ϊ����ֵ���أ�������ƽ���ֵķ�������below��ָ���ĺ����С� 
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
	printf("ƽ����: %d\n", divi);

	for(int j=0; j<len; j++) {
		if(*(p+j) < divi) {
			number++;
			printf("��%dλѧԱ�ķ���: %d, ����ƽ���� %d.\n", j+1, *(p+j), divi);
		}
	}
	return number;
}

int main1(void) {
	int number=0, divide[10] = {55, 99, 30, 40, 50, 90, 77, 88, 99, 111};
	number = fun(divide, sizeof(divide)/sizeof(int));
	printf("\n�ܹ���%d�˵ķ�������ƽ����.\n", number);

	system("pause");
	return 0;
}