/*��һ������Ϊn�����Ӽ���m��(n��m��������, n>1����m>1), 
ÿ�����ӵĳ��ȼ�Ϊk[0], k[1]...k[m], k[0]*k[1]...*k[m]�����˻��Ƕ���? )*/

#include <stdio.h>
#include <stdlib.h>

//
double MaxProduct(int rope) {
	if (rope <= 1) return 0;
	
	double* temp = new double[rope+1];
	if (!temp) return -1;

	int sub = 0;
	//�����ж���������һ��
	for (int m = 2; m <= rope; m++) {
		double* k = new double[m];
		if (!k) return -1;

		for (int i = 0; i < m; i++) {
			k[i] = (double)rope / m;         //��k����ÿ�����ӵĳ���
		}

		temp[sub] = 1;
		for (int j = 0; j < m; j++) { //����˻�
			//printf_s("%lf ", k[j]);
			temp[sub] *= k[j];
		}
		//printf_s("\n");
		sub++;

		delete[] k;
	}

	double max = temp[0];
	for (int i = 1; i <= rope; i++) {    //Ѱ�����ĳ˻�
		if (max < temp[i]) max = temp[i];
	}
	delete[] temp;

	return max;
}

int main(void) {
	int rope = 0, para = 0;

	printf_s("���ӳ���(����1): ");
	scanf_s("%d", &rope);

	for (int i = 2; i <= rope; i++) {
		double result = MaxProduct(i);
		printf_s("%d �����˻���: %lf\n", i, result);
	}

	system("pause");
	return 0;
}