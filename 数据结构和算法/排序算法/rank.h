//#pragma once
#ifndef _RANK_H_
#define _RANK_H_

/*****************************<<��������>>*****************************/

/*��������*/
void change(int* data1, int* data2);

/*�ж������Ƿ�����(��С����)*/
//��鷶Χ(Ĭ����������): startSub(Ĭ��Ϊ 0): ��ʼ�±�, endSub(Ĭ��Ϊ size-1): �����±�
bool ordered(const int* data, int size, int startSub = 0, int endSub = 0);

/*������������*/
//������Χ(Ĭ����������): startSub(Ĭ��Ϊ 0): ��ʼ�±�, endSub(Ĭ��Ϊ size-1): �����±�
void copy(int* array1, int* array2, int size, int startSub = 0, int endSub = 0);

/*��ӡ����*/
//��ӡ��Χ(Ĭ����������) : startSub(Ĭ��Ϊ 0) : ��ʼ�±�, endSub(Ĭ��Ϊ size - 1) : �����±�
void print(int* data, int size, int startSub = 0, int endSub = 0);

/*********************************************************************/

/******************************<<����>>******************************/

typedef struct _Heap {//��
	int* data;
	int size;
	bool apply;//apply: �Ƿ�����һ���µ��ڴ汣��data
}Heap;

/*��ʼ������*/
void initHeap(Heap*& heap, int* data, int size, bool apply = false);

/*������*/
bool BuildHeap(Heap* heap);

/*����*/
void outHeap(Heap* heap);

/*���ٶ�*/
void destroy(Heap* heap);

/*********************************************************************/

/******************************<<������>>******************************/

/*������*/
void HeapSort(int* data, int size);

/*ѡ������*/
void SelectioSort(int* data, int size);

/*ð������*/
void BubbleSort(int* data, int size);

/*��������*/
void InsertSort(int* data, int size);

/*ϣ������*/
void ShellSort(int* data, int size);

/*λͼ����*/
/* min: data���������Сֵ, max: data����������ֵ */
/* ����Χ(Ĭ����������): startSub(Ĭ��Ϊ 0): ��ʼ�±�, endSub(Ĭ��Ϊ size-1): �����±� */
void BitmapSort(int* data, int size, int min, int max, int startSub = 0, int endSub = 0);

/*�鲢����*/
/* left: ��ʼ�±�
* right: ����Ԫ�ظ��� */
void MergeSort(int* data, int left, int right);

/*��������*/
/*startSub: ��ʼ�±�, endSub: �����±� */
void QuickSort(int* data, int startSub, int endSub);

/*********************************************************************/

#endif 