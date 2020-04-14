/*把一根长度为n的绳子剪成m段(n和m都是整数, n>1而且m>1), 
每段绳子的长度记为k[0], k[1]...k[m], k[0]*k[1]...*k[m]的最大乘积是多少? )*/

#include <stdio.h>
#include <stdlib.h>

//
double MaxProduct(int rope) {
	if (rope <= 1) return 0;
	
	double* temp = new double[rope+1];
	if (!temp) return -1;

	int sub = 0;
	//将所有段数都计算一遍
	for (int m = 2; m <= rope; m++) {
		double* k = new double[m];
		if (!k) return -1;

		for (int i = 0; i < m; i++) {
			k[i] = (double)rope / m;         //用k保存每段绳子的长度
		}

		temp[sub] = 1;
		for (int j = 0; j < m; j++) { //计算乘积
			//printf_s("%lf ", k[j]);
			temp[sub] *= k[j];
		}
		//printf_s("\n");
		sub++;

		delete[] k;
	}

	double max = temp[0];
	for (int i = 1; i <= rope; i++) {    //寻找最大的乘积
		if (max < temp[i]) max = temp[i];
	}
	delete[] temp;

	return max;
}

int main(void) {
	int rope = 0, para = 0;

	printf_s("绳子长度(大于1): ");
	scanf_s("%d", &rope);

	for (int i = 2; i <= rope; i++) {
		double result = MaxProduct(i);
		printf_s("%d 的最大乘积是: %lf\n", i, result);
	}

	system("pause");
	return 0;
}