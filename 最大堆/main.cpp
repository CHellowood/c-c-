#include <iostream>
#include <Windows.h>

using namespace std;

#define DATA_LIMIT 11

typedef struct {
	int *data;   //堆数组指针
	int size;    //当前存储的元素个数
	int limit;   //堆数组的容量
}Heap;

bool initHeap(Heap& heap, int* data, int len);
bool insert(Heap& heap, int n);
bool outHeapTop(Heap& heap, int& heapTop);

static void adjust(Heap& heap, int i);
static void insert_adjust(Heap& heap, int i);

bool initHeap(Heap& heap, int* data, int len) {
	int limit = DATA_LIMIT > len ? DATA_LIMIT : len;
	
	heap.data = new int[limit];
	if (!heap.data) return false;

	heap.limit = limit;
	heap.size = 0;

	if (len > 0) {
		memcpy(heap.data, data, len*sizeof(int));
		heap.size = len;

		for (int i = (heap.size - 1) / 2; i >= 0; i--) {
			adjust(heap, i);
		}
	}

	return true;
}

void adjust(Heap& heap, int i) {
	int node = heap.data[i];
	int father = 0, son = 0;

	for (father = i; (father * 2 + 1) < heap.size; father = son) {
		son = father * 2 + 1;

		if ((son + 1) < heap.size && heap.data[son + 1] > heap.data[son]) {
			son++;
		}

		if (node >= heap.data[son]) {
			break;
		}
		else {
			heap.data[father] = heap.data[son];
			heap.data[son] = node;
		}

	}
}

bool insert(Heap& heap, int n) {
	if (!heap.data || heap.size >= heap.limit) return false;

	heap.data[heap.size++] = n;
	insert_adjust(heap, heap.size - 1);

	return true;
}

void insert_adjust(Heap& heap, int i) {
	if (i < 0 || i >= heap.size) return;

	int father = (i - 1) / 2, son = i;

	while (son > 0) {
		if (heap.data[father] >= heap.data[son]) break;

		int num = heap.data[father];
		heap.data[father] = heap.data[son];
		heap.data[son] = num;

		son = father;
		father = (father - 1) / 2;
	}
}

bool outHeapTop(Heap& heap, int& heapTop) {
	if (!heap.data || heap.size < 1) return false;

	heapTop = heap.data[0];
	heap.data[0] = heap.data[--heap.size];
	adjust(heap, 0);

	return true;
}

int main(void) {
	Heap heap;
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};

	if (!initHeap(heap, data, sizeof(data) / sizeof(data[0]))) {
		cout << "初始化堆失败!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "初始化堆成功!" << endl;
	
	for (int i = 0; i < 10; i++) {
		cout << heap.data[i] << endl;
	}

	if (!insert(heap, 99)) {
		cout << "插入失败!" << endl;
	}
	else {
		cout << "插入成功!" << endl;
	}

	for (int i = 0; i < 10; i++) {
		cout << heap.data[i] << endl;
	}

	int n = 0;
	while (outHeapTop(heap, n)) {
		cout  << " " << n;
	}

	system("pause");
	return 0;
}