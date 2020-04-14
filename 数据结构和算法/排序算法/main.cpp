#include <iostream>
#include <Windows.h>
#include <time.h>
#include "rank.h"

using namespace std;

//�����������
void disrupt(int* data, int size) {
	if (data && size > 1) {
		for (int i = 0; i < size; i++) {
			int num = rand() % size;
			change(&data[i], &data[num == i ? rand() % size : num]);/*��������*/
		}
	}
}

int main(void) {
	srand((unsigned)time(NULL));

	int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(data) / sizeof(data[0]);
/*
	cout << "------ѡ������------" << endl;

	disrupt(data, size);//��������

	cout << "����ǰ: " << endl;
	print(data, size);

	SelectioSort(data, size);
	cout << "�����: " << endl;
	print(data, size);

	cout << endl << "------ð������------" << endl;
	
	disrupt(data, size);//��������

	cout << "����ǰ: " << endl;
	print(data, size);

	BubbleSort(data, size);
	cout << "�����: " << endl;
	print(data, size);

	cout << endl << "------��������------" << endl;

	disrupt(data, size);//��������

	cout << "����ǰ: " << endl;
	print(data, size);

	InsertSort(data, size);
	cout << "�����: " << endl;
	print(data, size);

	cout << endl << "------ϣ������------" << endl;
	
	disrupt(data, size);//��������

	cout << "����ǰ: " << endl;
	print(data, size);

	ShellSort(data, size);
	cout << "�����: " << endl;
	print(data, size);
*/
	for (int i = 0; i < 10; i++) {
		disrupt(data, size);
		cout << "����ǰ: " << endl;
		print(data, size);

		//BitmapSort(data, size, 0, 9, 0, 4);
		//BitmapSort(data, size, 0, 9, 9, 5);

		QuickSort(data, 0, size-1);
		cout << "�����: " << endl;
		if (ordered(data, size)) {//�ж������Ƿ�����(��С����)
			printf_s("����ɹ�!!!\n");
		}
		else printf_s("����ʧ��!!!\n");
		print(data, size);
	}

	system("pause");
	return 0;
}
