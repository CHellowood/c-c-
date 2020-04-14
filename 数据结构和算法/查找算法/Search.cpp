#include "Search.h"
#include <Windows.h>

/*�����Ƚ�*/
int int_compare(const void* elem1, const void* elem2) {
	const int* i1 = (const int*)elem1;
	const int* i2 = (const int*)elem2;

	return (*i1 - *i2);
}

/*�ַ��Ƚ�*/
int char_compare(const void* elem1, const void* elem2) {
	const char* ch1 = (const char*)elem1;
	const char* ch2 = (const char*)elem2;

	return (*ch1 - *ch2);
}

/*�������Ƚ�*/
int float_compare(const void* elem1, const void* elem2) {
	const float* f1 = (const float*)elem1;
	const float* f2 = (const float*)elem2;

	if ((*f1 - *f2) > 0) return 1;
	if ((*f1 - *f2) < 0) return -1;
	return 0;
}

/*���ֲ���*/
int BinarySearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2)) {
	if (!array || len < 2 || elemSize < 1 || !search) return -1;

	int start = 0;
	int end = len - 1;
	int middle = 0;

	while (start <= end) {
		middle = (start + end) / 2;

		int ret = compare((char*)array + (middle * elemSize), search);
		
		if (ret == 0) return middle;       //�ҵ���, �����±�
		else if (ret > 0) end = middle - 1;//array[middle]����Ҫ�ҵ�, �ѷ�Χ��С�� start �� middle-1
		else start = middle + 1;           //array[middle]С��Ҫ�ҵ�, �ѷ�Χ��С�� middle+1 �� end
	}
	return -1;//û���ҵ�
}

typedef struct _Search {
	void* array;
	int start;
	int end;
	void* find;  //Ҫ����������
	int elemSize;//Ԫ�ش�С
	int findout; //���������±�, -1��ʾû���ҵ�
	int (*compare)(const void* elem1, const void* elem2);
}Search;

/*�߳�ִ�еĳ���*/
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

/*��������*/
int ParallelSearch(void* array, int len, int elemSize, void* search, int (*compare)(const void* elem1, const void* elem2)) {
	if (!array || len < 2 || elemSize < 1 || !search) return -1;

	int mid = (len - 1) / 2;
	Search s1 = { array, 0, mid, search, elemSize, 0, compare };
	Search s2 = { array, mid+1, len-1, search, elemSize, 0, compare };

	DWORD threadID1;//�߳�1��ID
	HANDLE hThread1;//�߳�1�ľ��

	DWORD threadID2;//�߳�2��ID
	HANDLE hThread2;//�߳�2�ľ��

	//�����߳�
	hThread1 = CreateThread(NULL, 0, ThreadProc, &s1, 0, &threadID1);
	hThread2 = CreateThread(NULL, 0, ThreadProc, &s2, 0, &threadID2);

	WaitForSingleObject(hThread1, INFINITE);//�ȴ��߳�1����
	WaitForSingleObject(hThread2, INFINITE);//�ȴ��߳�2����

	return s1.findout >= 0 ? s1.findout : s2.findout;
}