#include <iostream>
#include <Windows.h>
#include <time.h>
#include "rank.h"

using namespace std;

//随机打乱数组
void disrupt(int* data, int size) {
	if (data && size > 1) {
		for (int i = 0; i < size; i++) {
			int num = rand() % size;
			change(&data[i], &data[num == i ? rand() % size : num]);/*交换数据*/
		}
	}
}

int main(void) {
	srand((unsigned)time(NULL));

	int data[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(data) / sizeof(data[0]);
/*
	cout << "------选择排序------" << endl;

	disrupt(data, size);//打乱数组

	cout << "排序前: " << endl;
	print(data, size);

	SelectioSort(data, size);
	cout << "排序后: " << endl;
	print(data, size);

	cout << endl << "------冒泡排序------" << endl;
	
	disrupt(data, size);//打乱数组

	cout << "排序前: " << endl;
	print(data, size);

	BubbleSort(data, size);
	cout << "排序后: " << endl;
	print(data, size);

	cout << endl << "------插入排序------" << endl;

	disrupt(data, size);//打乱数组

	cout << "排序前: " << endl;
	print(data, size);

	InsertSort(data, size);
	cout << "排序后: " << endl;
	print(data, size);

	cout << endl << "------希尔排序------" << endl;
	
	disrupt(data, size);//打乱数组

	cout << "排序前: " << endl;
	print(data, size);

	ShellSort(data, size);
	cout << "排序后: " << endl;
	print(data, size);
*/
	for (int i = 0; i < 10; i++) {
		disrupt(data, size);
		cout << "排序前: " << endl;
		print(data, size);

		//BitmapSort(data, size, 0, 9, 0, 4);
		//BitmapSort(data, size, 0, 9, 9, 5);

		QuickSort(data, 0, size-1);
		cout << "排序后: " << endl;
		if (ordered(data, size)) {//判断数组是否有序(从小到大)
			printf_s("排序成功!!!\n");
		}
		else printf_s("排序失败!!!\n");
		print(data, size);
	}

	system("pause");
	return 0;
}
