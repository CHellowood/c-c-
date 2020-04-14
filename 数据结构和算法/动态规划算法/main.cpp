/*��n��̨��, һ��������һ�׻�����, һ���ж������߷�? */

#include <stdio.h>
#include <stdlib.h>

//�����㷨���, ȱ��:̨�����ϴ�ʱ��������ظ������Ѿ���������߷�, ���¼���ķǳ���
int WalkMethod(int num) {
	if (num <= 0) return 0;
	if (num == 1) return 1;//��1��̨��ʱ, ��1���߷�
	if (num == 2) return 2;//��2��̨��ʱ, ��2���߷�

	return WalkMethod(num - 1) + WalkMethod(num - 2);
}

//��̬�滮�㷨���
int WalkMethod2(int num) {
	if (num <= 0) return 0;
	if (num == 1) return 1;//��1��̨��ʱ, ��1���߷�
	if (num == 2) return 2;//��2��̨��ʱ, ��2���߷�

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

	printf_s("̨����:");
	scanf_s("%d", &num);
/*
	//�����㷨���
	printf_s("------�����㷨���------\n");

	for (int i = 0; i <= num; i++) {
		result = WalkMethod(i);
		printf_s("%d ��̨��һ���� %d ���߷�\n", i, result);
	}
*/
	//��̬�滮�㷨���
	printf_s("\n------��̬�滮�㷨���------\n");

	for (int i = 0; i <= num; i++) {
		result = WalkMethod2(i);
		printf_s("%d ��̨��һ���� %d ���߷�\n", i, result);
	}


	system("pause");
	return 0;
}


