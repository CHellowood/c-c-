//#pragma once
#ifndef _RANK_H_
#define _RANK_H_

/*****************************<<辅助函数>>*****************************/

/*交换数据*/
void change(int* data1, int* data2);

/*判断数组是否有序(从小到大)*/
//检查范围(默认整个数组): startSub(默认为 0): 起始下标, endSub(默认为 size-1): 结束下标
bool ordered(const int* data, int size, int startSub = 0, int endSub = 0);

/*拷贝整数数组*/
//拷贝范围(默认整个数组): startSub(默认为 0): 起始下标, endSub(默认为 size-1): 结束下标
void copy(int* array1, int* array2, int size, int startSub = 0, int endSub = 0);

/*打印数组*/
//打印范围(默认整个数组) : startSub(默认为 0) : 起始下标, endSub(默认为 size - 1) : 结束下标
void print(int* data, int size, int startSub = 0, int endSub = 0);

/*********************************************************************/

/******************************<<最大堆>>******************************/

typedef struct _Heap {//堆
	int* data;
	int size;
	bool apply;//apply: 是否申请一块新的内存保存data
}Heap;

/*初始化最大堆*/
void initHeap(Heap*& heap, int* data, int size, bool apply = false);

/*建最大堆*/
bool BuildHeap(Heap* heap);

/*出堆*/
void outHeap(Heap* heap);

/*销毁堆*/
void destroy(Heap* heap);

/*********************************************************************/

/******************************<<排序函数>>******************************/

/*堆排序*/
void HeapSort(int* data, int size);

/*选择排序*/
void SelectioSort(int* data, int size);

/*冒泡排序*/
void BubbleSort(int* data, int size);

/*插入排序*/
void InsertSort(int* data, int size);

/*希尔排序*/
void ShellSort(int* data, int size);

/*位图排序*/
/* min: data数组里的最小值, max: data数组里的最大值 */
/* 排序范围(默认整个数组): startSub(默认为 0): 起始下标, endSub(默认为 size-1): 结束下标 */
void BitmapSort(int* data, int size, int min, int max, int startSub = 0, int endSub = 0);

/*归并排序*/
/* left: 起始下标
* right: 数组元素个数 */
void MergeSort(int* data, int left, int right);

/*快速排序*/
/*startSub: 起始下标, endSub: 结束下标 */
void QuickSort(int* data, int startSub, int endSub);

/*********************************************************************/

#endif 