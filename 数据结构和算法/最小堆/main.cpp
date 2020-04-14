#include <iostream>
#include <Windows.h>

using namespace std;

#define SILENT_LIMIT 11

typedef struct {
	int* data;
	int size;
	int limit;
}Heap;

bool initHeap(Heap& heap, int* data, int len);
bool insert(Heap& heap, int n);
bool deleteHeapTop(Heap& heap, int& heapTop);

static void adjust(Heap& heap, int i);
static void insert_adjust(Heap& heap, int i);
static void delete_adjust(Heap& heap, int i);

bool initHeap(Heap& heap, int* data, int len) {
	if (!data) return false;
	
	int limit = SILENT_LIMIT > len ? SILENT_LIMIT : len;

	heap.data = new int[limit];
	if (!heap.data) return false;

	heap.size = 0;
	heap.limit = limit;

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

	for (father = i; father * 2 + 1 < heap.size; father = son) {
		son = father * 2 + 1;

		if (son + 1 < heap.size && heap.data[son + 1] < heap.data[son]) {
			son++;
		}

		if (node <= heap.data[son]) break;
		
		heap.data[father] = heap.data[son];
		heap.data[son] = node;
	}
}

bool insert(Heap& heap, int n) {
	if (!heap.data || heap.size >= heap.limit) {
		cout << "堆不存在或堆空间已满!" << endl;
		return false;
	}

	heap.data[heap.size++] = n;
	insert_adjust(heap, heap.size - 1);

	return true;
}

void insert_adjust(Heap& heap, int i) {
	if (i < 0 || i >= heap.size) return;

	while (i > 0) {
		int father = (i - 1) / 2;
		
		if (heap.data[father] < heap.data[i]) break;
		
		int num = heap.data[father];
		heap.data[father] = heap.data[i];
		heap.data[i] = num;

		i = father;
	}
}

/*
//方式一
bool deleteHeapTop(Heap& heap, int& heapTop) {
	if (!heap.data || heap.size < 1) {
		cout << "堆不存在或堆为空!" << endl;
		return false;
	}

	heapTop = heap.data[0];
	delete_adjust(heap, 0);

	return true;
}

void delete_adjust(Heap& heap, int i) {
	int father = 0, son = 0;
	for (father = i; father * 2 + 1 < heap.size; father = son) {
		son = father * 2 + 1;

		if (son + 1 < heap.size && heap.data[son + 1] < heap.data[son]) {
			son++;
		}

		heap.data[father] = heap.data[son];
	}
	heap.size--;
}
*/

//方式二
bool deleteHeapTop(Heap& heap, int& heapTop) {
	if (!heap.data || heap.size < 1) {
		cout << endl << "堆不存在或堆为空!" << endl;
		return false;
	}

	heapTop = heap.data[0];
	heap.data[0] = heap.data[--heap.size];
	
	//delete_adjust(heap, 0);
	adjust(heap, 0);

	return true;
}

int main(void) {
	Heap heap;
	int data[] = {-1, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	if (!initHeap(heap, data, sizeof(data) / sizeof(data[0]))) {
		cout << "初始化最小堆失败!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "初始化最小堆成功!" << endl;

	for (int i = 0; i < heap.size; i++) {
		cout << heap.data[i] << "  ";
	}
	cout << endl;

	if (!insert(heap, -6)) {
		cout << "插入失败!" << endl;
	}
	else {
		cout << "插入成功!" << endl;
	}

	for (int i = 0; i < heap.size; i++) {
		cout << heap.data[i] << "  ";
	}
	cout << endl;

	int n = 0;
	while (deleteHeapTop(heap, n)) {
		cout << " " << n;
	}
	cout << endl;

	system("pause");
	return 0;
}
