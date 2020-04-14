#include <stdio.h>
#include <stdlib.h>

#define F 7

int value[F] = {1, 2, 5, 10, 20, 50, 100};
int number[F] = {0, 2, 1, 0, 3, 1, 0};


//总钱数
int totalMoney() {
	int ret = 0;
	for (int i = 0; i < F; i++) {
		ret += value[i] * number[i];
	}
	return ret;
}


//整型数组拷贝
void copy(int* array1, int* array2, int size) {
	if (!array1 || !array2 || size <= 0) return;

	for (int i = 0; i < size; i++) {
		array1[i] = array2[i];
	}
}


int solve(int money) {
	if (money <= 0) return 0;
	if (totalMoney() < money) return -2;

	int num = 0;
	int gurMoney = 0;
	int tempnum[F];

	for (int i = F - 1; i >= 0; i--) {
		if (number[i] <= 0 || money < value[i]) continue;
		
		gurMoney = money;
		copy(tempnum, number, F);

		printf_s("- - - - - - - - - - - - - - - - - - - -\n");

		for (int j = i; j >= 0; j--) {
			int temp = gurMoney / value[j];
			
			if (temp > 0 && number[j] > 0) {
				temp = temp > number[j] ? number[j] : temp;
				gurMoney -= temp * value[j];
				tempnum[j] -= temp;
				num += temp;

				printf_s("面额%d的纸币%d张.\n", value[j], temp);
				if (gurMoney == 0) {
					copy(number, tempnum, F);
					return num;
				}
			}
		}
		printf_s("\n还差%d元, 重新进行计算!\n\n", gurMoney);

		num = 0;
	}
	return -1;
}

int main(void) {
	int money = 0;
	int num = 0;

	while (true) {
		printf_s("\n要支付的钱数: ");
		scanf_s("%d", &money);

		num = solve(money);

		if (num == -1) {
			printf_s("\n无法找开!!!\n\n");
		}
		else if (num == -2) {
			printf_s("\n钱不够!!!\n\n");
		}
		else {
			printf_s("\n至少需要%d张纸币支付!\n\n", num);
		}

		printf_s("- - - - - - - - - - - - - - - - - - - -\n");

		for (int i = F - 1; i >= 0; i--) {
			printf_s("面额%d的还剩%d张.\n", value[i], number[i]);
		}
	}

	system("pause");
	return 0;
}