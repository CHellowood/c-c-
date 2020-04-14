#include <iostream>
#include <Windows.h>

using namespace std;

typedef int DataType;

typedef struct PriorityQueue {
	DataType* data; //数据
	int size;       //当前已储存的元素个数
}PQueue;

bool initQueue(PQueue& queue, int* data, int len);
bool search(PQueue& queue, int n, int* data, int len);

static bool adjust(PQueue& queue, int i);
//static bool insert_adjust(PQueue& queue, int i);

//初始化堆
bool initQueue(PQueue& queue, int* data, int len) {
	queue.data = data;
	queue.size = len;

	if (len > 0) {
		for (int i = (queue.size - 1) / 2; i >= 0; i--) {
			if (!adjust(queue, i)) return false;
		}
	}
	return true;
}

//查找最大的n个元素,保存到data数组
bool search(PQueue& queue, int n, int* data, int len) {
	if (!queue.data || n < 0 || n > queue.size || !data || len < n) return false;

	int i = 0;
	while (i < n) {
		data[i] = queue.data[0];
		queue.data[0] = queue.data[--queue.size];

		for (int j = (queue.size - 1) / 2; j >= 0; j--) {
			if (!adjust(queue, j)) return false;
		}
		i++;
	}
	return true;
}

bool adjust(PQueue& queue, int i) {
	if (!queue.data || i < 0 || i >= queue.size) return false;

	int node = queue.data[i];
	while ((i * 2 + 1) < queue.size) {
		int son = i * 2 + 1;

		if (son + 1 < queue.size && queue.data[son + 1] > queue.data[son]) {
			son++;
		}

		if (queue.data[son] <= queue.data[i]) {
			break;
		}

		queue.data[i] = queue.data[son];
		queue.data[son] = node;

		i = son;
	}
	return true;
}

/*
bool insert_adjust(PQueue& queue, int i) {
	if (i < 0 || i >= queue.size) return false;

	while (i > 0) {
		int father = (i - 1) / 2;

		if (queue.data[father] >= queue.data[i]) {
			break;
		}

		int num = queue.data[father];
		queue.data[father] = queue.data[i];
		queue.data[i] = num;

		i = father;
	}
	return true;
}
*/

int main(void) {
	PQueue queue;
	int data[] = { 2, 4, 5, 8, 0, 1, 3, 66, 7, 9 };

	if (!initQueue(queue, data, sizeof(data) / sizeof(data[0]))) {
		cout << "初始化优先队列失败!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "初始化优先队列成功!" << endl;

	for (int i = 0; i < queue.size; i++) {
		cout << " " << queue.data[i];
	}
	cout << endl;

	int num[10];
	int n = 5;
	cout << "最大的" << n << "个元素出队:";
	search(queue, n, num, 10);
	
	for (int i = 0; i < n; i++) {
		cout << " " << num[i];
	}
	cout << endl;

	system("pause");
	return 0;
}