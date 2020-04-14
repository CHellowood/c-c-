#include "rank.h"
#include <stdio.h>

/*交换数据*/
void change(int* data1, int* data2) {
	int num = *data1;
	*data1 = *data2;
	*data2 = num;
}

/*判断数组是否有序(从小到大)*/
bool ordered(const int* data, int size, int startSub, int endSub) {
	endSub = endSub == 0 ? size - 1 : endSub;

	if (data && startSub >= 0 && endSub > startSub && endSub < size) {
		for (int i = startSub; i < endSub; i++) {
			if (i + 1 <= endSub && data[i] > data[i + 1]) {
				return false;
			}
		}
		return true;
	}
	return false;
}


/*拷贝整数数组*/
void copy(int* array1, int* array2, int size, int startSub, int endSub) {
	endSub = endSub == 0 ? size - 1 : endSub;

	if (array1 && array2 && startSub >= 0 && endSub > startSub && endSub < size) {
		for (int i = startSub; i <= endSub; i++) {
			array1[i] = array2[i];
		}
	}
}

/*打印数组*/
void print(int* data, int size, int startSub, int endSub) {
	if (data && startSub >= 0 && endSub >= startSub && size > endSub) {
		endSub = endSub == 0 ? size - 1 : endSub;
		for (int i = startSub; i <= endSub; i++) {
			printf_s("%d ", data[i]);
		}
		printf_s("\n");
	}
}


/*初始化最大堆*/
void initHeap(Heap*& heap, int* data, int size, bool apply) {
	if (!data || size < 1) return;

	heap = new Heap;
	if (!heap) return;

	if (apply) {
		heap->data = new int[size];
		if (!heap->data) return;
		
		copy(heap->data, data, size, 0, size - 1);/*拷贝整数数组*/
		heap->apply = true;
	}
	else {
		heap->data = data;
		heap->apply = false;
	}

	heap->size = size;
}

/*建最大堆*/
bool BuildHeap(Heap* heap) {
	if (!heap || heap->size < 2) return false;

	int father = 0, son = 0;

	for (int i = (heap->size - 1) / 2; i >= 0; i--) {
		for (father = i; father * 2 + 1 < heap->size; father = son) {
			son = father * 2 + 1;

			if (son + 1 < heap->size && heap->data[son + 1] > heap->data[son]) {
				son++;
			}

			if (heap->data[son] > heap->data[father]) {
				change(&heap->data[son], &heap->data[father]); //交换数据
			}
		}
	}
	return true;
}

/*出堆*/
void outHeap(Heap* heap) {
	if (!heap) return;

	int temp = heap->data[0];
	heap->data[0] = heap->data[--heap->size];
	heap->data[heap->size] = temp;
	
	BuildHeap(heap);
}

/*销毁堆*/
void destroy(Heap* heap) {
	if (heap) {
		if (heap->apply) delete[] heap->data;
		else heap->data = 0;
		delete heap;
	}
}

/*堆排序*/
void HeapSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//判断数组是否有序

	Heap* temp = NULL;
	initHeap(temp, data, size);

	BuildHeap(temp);/*建最大堆*/

	while (temp->size > 1) outHeap(temp);

	destroy(temp);
}


/*选择排序*/
void SelectioSort(int* data, int size) {
	if (!data || size < 2) return;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] > data[j]) {
				//print(data, size);
				change(&data[i], &data[j]); //交换数据
			}
		}
		if (ordered(data, size)) {
			printf_s("SelectioSort: 大循环运行了%d次!\n", i + 1);
			break; //如果有序, 结束循环	
		}
	}
}

/*冒泡排序*/
void BubbleSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//判断数组是否有序

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				//print(data, size);
				change(&data[j], &data[j + 1]); //交换数据
			}
		}

		if (ordered(data, size)) {
			printf_s("BubbleSort: 大循环运行了%d次!\n", i + 1);
			break; //如果有序, 结束循环	
		}
	}
}

/*插入排序*/
void InsertSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//判断数组是否有序

	for (int i = 1; i < size; i++) {
		int num = i;
		while (num - 1 >= 0 && data[num - 1] > data[num]) {
			//print(data, size);
			change(&data[num - 1], &data[num]); //交换数据
			num--;
		}
		/*
		if (ordered(data, size)) {
			printf_s("InsertSort: 大循环运行了%d次!\n", i + 1);
			break; //如果有序, 结束循环	
		}
		*/
	}
}

/*希尔排序*/
void ShellSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//判断数组是否有序
	
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int current = data[i];
			int j = 0;
			for (j = i - gap; j >= 0 && data[j] > current; j -= gap) { // <- 关键点
				change(&data[j], &data[j + gap]); //交换数据
				//printf_s("测试: gap: %d i: %d j: %d\n", gap, i, j);
				//data[j + gap] = data[j]; //第一轮循环: gap = 2, i = 4, j = 2, j + gap = i
			}							 //第二轮循环: gap = 2, i = 4, j = 0, j + gap = 上一轮的 j
			//data[j + gap] = current;     //此时 j < 0
		}
	}
}

/*位图排序*/
void BitmapSort(int* data, int size, int min, int max, int startSub, int endSub) {
	endSub = endSub == 0 ? size - 1 : endSub;
	
	if (!data || size < 2 || min >= max || 
		size <= startSub || size <= endSub || startSub == endSub) return;
	//if (ordered(data, size)) return;//判断数组是否有序

	if (startSub > endSub) change(&startSub, &endSub);

	int len = max - min + 1;
	int* temp = new int[len] { 0 }; //申请内存后 一定 一定 一定 要全部清0, 不然会排序失败 
	if (!temp) return;

	for (int i = startSub; i <= endSub; i++) {
		temp[data[i] - min]++;
	}

	for (int j = 0, sub = startSub; j < len && sub <= endSub;) {
		if (temp[j] > 0) {
			data[sub++] = j + min;
			temp[j]--;
		}
		else j++;
	}
	delete[] temp;
}


/*归并排序*/
void MergeSort(int* data, int left, int right) {
	if (!data) return;
	//if (ordered(data, right)) return;//判断数组是否有序
	
	int mid = (right + left) /2;

	//把data数组分成两部分
	//判断data数组下标为 left 到 mid-1 的 mid-left-1 个元素是否有序
	if (!ordered(data, right, left, mid - 1) && mid - left - 1 >= 1) 
		MergeSort(data, left, mid);
	
	//判断data数组下标为 mid 到 right-1 的 right-mid-1 个元素是否有序
	if (!ordered(data, right, mid, right - 1) && right - mid -1 >= 1)
		MergeSort(data, mid, right);

	int* temp = new int[right];
	if (!temp) return;

	int l = left;//左边起始坐标
	int m = mid; //右边起始坐标
	int t = left;   //已排好的元素个数

	while (l < mid && m < right) { // 如果左边已经排完或右边已经排完, 结束循环
		if (data[l] < data[m]) {
			temp[t++] = data[l++];
		}
		else temp[t++] = data[m++];
	}

	//如果右边已经排完但左边还未排完,则继续排左边未排完的
	while (l < mid) temp[t++] = data[l++];

	//如果左边已经排完但右边还未排完,则继续排右边未排完的
	while (m < right) temp[t++] = data[m++];

	copy(data, temp, right, left, right - 1);

	delete[] temp;
}

/*快速排序*/
void QuickSort(int* data, int startSub, int endSub) {
	if (!data || startSub < 0 || startSub >= endSub) return;

	int temp = data[startSub];//把基值移出来, 该位置就变成了空位(指的不是该位置的数据为空)
	int start = startSub;
	int end = endSub;

	while (start < end) {
		while (start < end && data[end] >= temp) {//从右边开始寻找小于基值的值
			end--;
		}

		if (start < end) data[start++] = data[end];//找到了, 把该值移到空位, 该位置就变成了空位

		while (start < end && data[start] < temp) {//从边开始寻找大于或等于基值的值
			start++;
		}

		if (start < end) data[end--] = data[start];//找到了, 把该值移到空位, 该位置就变成了空位
	}
	//循环结束后start是等于end的
	data[start] = temp;

	QuickSort(data, startSub, end-1);  //递归 startSub 到 end-1 之间的元素
	QuickSort(data, start+1, endSub);//递归 start+1 到 endSub 之间的元素
}
