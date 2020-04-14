#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "Search.h"

int main(void) {

	printf_s("整数测试:\n");
	int array[] = {1, 3, 4, 6, 7, 9, 11};
	int search[] = {-1, 0, 1, 2, 6, 8, 11, 12};

	for (int i = 0; i < sizeof(search) / sizeof(search[0]); i++) {
		int result = BinarySearch(array, sizeof(array)/sizeof(array[0]), sizeof(int), &search[i], int_compare);
		printf_s("searching %d, result %d\n", search[i], result);
	}

	printf_s("字符测试:\n");
	char array1[] = { 'a', 'c', 'd', 'f', 'g', 'j', 's' };
	char search1[] = { '0', 'a', 'e', 'f', 'h', 's', 'z' };

	for (int i = 0; i < sizeof(search1) / sizeof(search1[0]); i++) {
		int result = BinarySearch(array1, sizeof(array1) / sizeof(array1[0]), sizeof(char), &search1[i], char_compare);
		printf_s("searching %c, result %d\n", search1[i], result);
	}

	printf_s("浮点数测试:\n");
	float array2[] = { 1.0f, 3.3f, 4.5f, 6.2f, 7.1f, 9.6f, 11.1f };
	float search2[] = { -0.5f, 0.3f, 1.0f, 1.1f, 2.2f, 6.2f, 8.9f, 11.1f, 11.2f };

	for (int i = 0; i < sizeof(search2) / sizeof(search2[0]); i++) {
		int result = BinarySearch(array2, sizeof(array2) / sizeof(array2[0]), sizeof(float), &search2[i], float_compare);
		printf_s("searching %f, result %d\n", search2[i], result);
	}



	printf_s("并行搜索: 整数测试2:\n");
	int array3[] = { 1, 3, 4, 6, 7, 9, 11 };
	int search3[] = { -1, 0, 1, 2, 6, 8, 11, 12 };

	for (int i = 0; i < sizeof(search3) / sizeof(search3[0]); i++) {
		int result = ParallelSearch(array3, sizeof(array3) / sizeof(array3[0]), sizeof(int), &search3[i], int_compare);
		printf_s("searching %d, result %d\n", search3[i], result);
	}
	

	system("pause");
	return 0;
}