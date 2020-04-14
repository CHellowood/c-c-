#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//数组大小
#define DATA_NUM 10  
//数组的所有元素要小于100
#define MAX_NUM 100

/*位图排序*/
bool bitmap_rank(int* data, int size, int maxnum) {
	if (!data) return false;

	int* bitmap = new int[maxnum];
	if (!bitmap) return false;

	//将整个数组全部置0
	memset(bitmap, 0, sizeof(bitmap[0])*maxnum);

	//位图排序
	for (int i = 0; i < size; i++) {
		if (data[i] < maxnum) {
			bitmap[data[i]]++;
		}
	}

	//将排序后的结果复制到传递进来的数组
	for (int j = 0, n = 0; j < maxnum;) {
		if (bitmap[j]-- > 0) {
			data[n++] = j;
		}
		else j++;
	}

	delete[] bitmap;
	return true;
}

//二叉查找
int BinarySearch(int* data, int start, int tail, int num) {
	if (!data) return -2;
	if (start > tail) return -1;

	int mid = (start + tail) / 2;
	
	//当前数据等于要查找的数据就直接返回
	if (data[mid] == num) return mid; 
	//当前数据小于要查找的数据就往右边找
	else if (data[mid] < num) return BinarySearch(data, mid + 1, tail, num);
	//当前数据大于要查找的数据就往左边找
	else return BinarySearch(data, start, mid - 1, num);
}

int main(void) {
	int data[DATA_NUM];

	/*随机生成一个数组*/
	srand((unsigned)time(NULL));
	for (int i = 0; i < DATA_NUM; i++) {
		data[i] = rand() % MAX_NUM;
		cout << data[i] << " ";
	}
	cout << endl;

	/*位图排序*/
	if (bitmap_rank(data, DATA_NUM, MAX_NUM)) {
		cout << endl << "排序后: ";
		for (int i = 0; i < DATA_NUM; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		
		//二叉查找
		while (true) {
			int num = 0;

			cout << "查找: ";
			cin >> num;

			int const sub = BinarySearch(data, 0, DATA_NUM - 1, num);
			cout << sub << endl;
		}
	}

	system("pause");
	return 0;
}
