#include <iostream>
#include <Windows.h>

using namespace std;

typedef int DataType;

typedef struct _Heap {
	DataType* data;
	int size;
}Heap;

void initHeap(Heap& heap, DataType* data, int len);
void sort(Heap& heap);
static void adjust(Heap& heap, int i);

void initHeap(Heap& heap, DataType* data, int len) {
	heap.data = data;
	heap.size = len;

	for (int i = (heap.size - 1) / 2; i >= 0; i--) {
		adjust(heap, i);
	}
}

void sort(Heap& heap) {
	if (!heap.data) return;

	while (heap.size > 0) {
		int num = heap.data[0];
		heap.data[0] = heap.data[heap.size-1];
		heap.data[heap.size-1] = num;
		heap.size--;
		
		for (int i = (heap.size - 1) / 2; i >= 0; i--) {
			adjust(heap, i);
		}
	}
}

void adjust(Heap& heap, int i) {
	int node = heap.data[i];
	while ((i * 2 + 1) < heap.size) {
		int son = i * 2 + 1;

		if (son + 1 < heap.size && heap.data[son + 1] > heap.data[son]) {
			son++;
		}

		if (heap.data[son] <= node) break;

		heap.data[i] = heap.data[son];
		heap.data[son] = node;

		i = son;
	}
}

int main(void) {
	Heap heap;
	DataType data[] = {2, 4, 5, 6, 1, 9, 7, 8, 0, 3};

	cout << "³õÊ¼»¯¶Ñ" << endl;
	initHeap(heap, data, sizeof(data)/sizeof(data[0]));
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		cout << " " << data[i];
	}
	cout << endl;

	cout << "¶ÑÅÅĞò" << endl;
	sort(heap);
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		cout << " " << data[i];
	}
	cout << endl;

	system("pause");
	return 0;
}
