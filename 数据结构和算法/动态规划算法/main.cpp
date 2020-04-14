/*有n阶台阶, 一步可以走一阶或两阶, 一共有多少种走法? */

#include <stdio.h>
#include <stdlib.h>

//分治算法求解, 缺点:台阶数较大时会大量的重复计算已经计算过的走法, 导致计算的非常慢
int WalkMethod(int num) {
	if (num <= 0) return 0;
	if (num == 1) return 1;//有1阶台阶时, 有1种走法
	if (num == 2) return 2;//有2阶台阶时, 有2种走法

	return WalkMethod(num - 1) + WalkMethod(num - 2);
}

//动态规划算法求解
int WalkMethod2(int num) {
	if (num <= 0) return 0;
	if (num == 1) return 1;//有1阶台阶时, 有1种走法
	if (num == 2) return 2;//有2阶台阶时, 有2种走法

	int* temp = new int[num + 1];
	if (!temp) return -1;

	temp[0] = 0;
	temp[1] = 1;
	temp[2] = 2;

	for (int i = 3; i <= num; i++) {
		temp[i] = temp[i - 1] + temp[i - 2];
	}
	int ret = temp[num];
	delete[] temp;

	return ret;
}

int main(void) {
	int num = 0, result = 0;

	printf_s("台阶数:");
	scanf_s("%d", &num);
/*
	//分治算法求解
	printf_s("------分治算法求解------\n");

	for (int i = 0; i <= num; i++) {
		result = WalkMethod(i);
		printf_s("%d 阶台阶一共有 %d 种走法\n", i, result);
	}
*/
	//动态规划算法求解
	printf_s("\n------动态规划算法求解------\n");

	for (int i = 0; i <= num; i++) {
		result = WalkMethod2(i);
		printf_s("%d 阶台阶一共有 %d 种走法\n", i, result);
	}


	system("pause");
	return 0;
}


