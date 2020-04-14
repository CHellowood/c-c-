#include "Search.h"
#include <Windows.h>

/*整数比较*/
int int_compare(const void* elem1, const void* elem2) {
	const int* i1 = (const int*)elem1;
	const int* i2 = (const int*)elem2;

	return (*i1 - *i2);
}

/*字符比较*/
int char_compare(const void* elem1, const void* elem2) {
	const char* ch1 = (const char*)elem1;
	const char* ch2 = (const char*)elem2;

	return (*ch1 - *ch2);
}

/*浮点数比较*/
int float_compare(const void* elem1, const void* elem2) {
	const float* f1 = (const float*)elem1;
	const float* f2 = (const float*)elem2;

	if ((*f1 - *f2) > 0) return 1;
	if ((*f1 - *f2) < 0) return -1;
	return 0;
}

/*二分查找*/
int BinarySearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2)) {
	if (!array || len < 2 || elemSize < 1 || !search) return -1;

	int start = 0;
	int end = len - 1;
	int middle = 0;

	while (start <= end) {
		middle = (start + end) / 2;

		int ret = compare((char*)array + (middle * elemSize), search);
		
		if (ret == 0) return middle;       //找到了, 返回下标
		else if (ret > 0) end = middle - 1;//array[middle]大于要找的, 把范围缩小到 start 至 middle-1
		else start = middle + 1;           //array[middle]小于要找的, 把范围缩小到 middle+1 至 end
	}
	return -1;//没有找到
}

typedef struct _Search {
	void* array;
	int start;
	int end;
	void* find;  //要搜索的数据
	int elemSize;//元素大小
	int findout; //保存结果的下标, -1表示没有找到
	int (*compare)(const void* elem1, const void* elem2);
}Search;

/*线程执行的程序*/
DWORD WINAPI ThreadProc(void* lpParam) {
	Search* s = (Search*)lpParam;

	for (int i = s->start; i <= s->end; i++) {
		if (s->compare((char*)s->array + (i * s->elemSize), s->find) == 0) {
			s->findout = i;
			return 0;
		}
	}
	s->findout = -1;
	return 0;
}

/*并行搜索*/
int ParallelSearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2)) {
	if (!array || len < 2 || elemSize < 1 || !search) return -1;

	int mid = (len - 1) / 2;
	Search s1 = { array, 0, mid, search, elemSize, 0, compare };
	Search s2 = { array, mid+1, len-1, search, elemSize, 0, compare };

	DWORD threadID1;//线程1的ID
	HANDLE hThread1;//线程1的句柄

	DWORD threadID2;//线程2的ID
	HANDLE hThread2;//线程2的句柄

	//创建线程
	hThread1 = CreateThread(NULL, 0, ThreadProc, &s1, 0, &threadID1);
	hThread2 = CreateThread(NULL, 0, ThreadProc, &s2, 0, &threadID2);

	WaitForSingleObject(hThread1, INFINITE);//等待线程1结束
	WaitForSingleObject(hThread2, INFINITE);//等待线程2结束

	return s1.findout >= 0 ? s1.findout : s2.findout;
}