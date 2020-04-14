#include "rank.h"
#include <stdio.h>

/*��������*/
void change(int* data1, int* data2) {
	int num = *data1;
	*data1 = *data2;
	*data2 = num;
}

/*�ж������Ƿ�����(��С����)*/
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


/*������������*/
void copy(int* array1, int* array2, int size, int startSub, int endSub) {
	endSub = endSub == 0 ? size - 1 : endSub;

	if (array1 && array2 && startSub >= 0 && endSub > startSub && endSub < size) {
		for (int i = startSub; i <= endSub; i++) {
			array1[i] = array2[i];
		}
	}
}

/*��ӡ����*/
void print(int* data, int size, int startSub, int endSub) {
	if (data && startSub >= 0 && endSub >= startSub && size > endSub) {
		endSub = endSub == 0 ? size - 1 : endSub;
		for (int i = startSub; i <= endSub; i++) {
			printf_s("%d ", data[i]);
		}
		printf_s("\n");
	}
}


/*��ʼ������*/
void initHeap(Heap*& heap, int* data, int size, bool apply) {
	if (!data || size < 1) return;

	heap = new Heap;
	if (!heap) return;

	if (apply) {
		heap->data = new int[size];
		if (!heap->data) return;
		
		copy(heap->data, data, size, 0, size - 1);/*������������*/
		heap->apply = true;
	}
	else {
		heap->data = data;
		heap->apply = false;
	}

	heap->size = size;
}

/*������*/
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
				change(&heap->data[son], &heap->data[father]); //��������
			}
		}
	}
	return true;
}

/*����*/
void outHeap(Heap* heap) {
	if (!heap) return;

	int temp = heap->data[0];
	heap->data[0] = heap->data[--heap->size];
	heap->data[heap->size] = temp;
	
	BuildHeap(heap);
}

/*���ٶ�*/
void destroy(Heap* heap) {
	if (heap) {
		if (heap->apply) delete[] heap->data;
		else heap->data = 0;
		delete heap;
	}
}

/*������*/
void HeapSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//�ж������Ƿ�����

	Heap* temp = NULL;
	initHeap(temp, data, size);

	BuildHeap(temp);/*������*/

	while (temp->size > 1) outHeap(temp);

	destroy(temp);
}


/*ѡ������*/
void SelectioSort(int* data, int size) {
	if (!data || size < 2) return;

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i] > data[j]) {
				//print(data, size);
				change(&data[i], &data[j]); //��������
			}
		}
		if (ordered(data, size)) {
			printf_s("SelectioSort: ��ѭ��������%d��!\n", i + 1);
			break; //�������, ����ѭ��	
		}
	}
}

/*ð������*/
void BubbleSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//�ж������Ƿ�����

	for (int i = 0; i < size - 1; i++) {

		for (int j = 0; j < size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				//print(data, size);
				change(&data[j], &data[j + 1]); //��������
			}
		}

		if (ordered(data, size)) {
			printf_s("BubbleSort: ��ѭ��������%d��!\n", i + 1);
			break; //�������, ����ѭ��	
		}
	}
}

/*��������*/
void InsertSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//�ж������Ƿ�����

	for (int i = 1; i < size; i++) {
		int num = i;
		while (num - 1 >= 0 && data[num - 1] > data[num]) {
			//print(data, size);
			change(&data[num - 1], &data[num]); //��������
			num--;
		}
		/*
		if (ordered(data, size)) {
			printf_s("InsertSort: ��ѭ��������%d��!\n", i + 1);
			break; //�������, ����ѭ��	
		}
		*/
	}
}

/*ϣ������*/
void ShellSort(int* data, int size) {
	if (!data || size < 2) return;
	//if (ordered(data, size)) return;//�ж������Ƿ�����
	
	for (int gap = size / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < size; i++) {
			int current = data[i];
			int j = 0;
			for (j = i - gap; j >= 0 && data[j] > current; j -= gap) { // <- �ؼ���
				change(&data[j], &data[j + gap]); //��������
				//printf_s("����: gap: %d i: %d j: %d\n", gap, i, j);
				//data[j + gap] = data[j]; //��һ��ѭ��: gap = 2, i = 4, j = 2, j + gap = i
			}							 //�ڶ���ѭ��: gap = 2, i = 4, j = 0, j + gap = ��һ�ֵ� j
			//data[j + gap] = current;     //��ʱ j < 0
		}
	}
}

/*λͼ����*/
void BitmapSort(int* data, int size, int min, int max, int startSub, int endSub) {
	endSub = endSub == 0 ? size - 1 : endSub;
	
	if (!data || size < 2 || min >= max || 
		size <= startSub || size <= endSub || startSub == endSub) return;
	//if (ordered(data, size)) return;//�ж������Ƿ�����

	if (startSub > endSub) change(&startSub, &endSub);

	int len = max - min + 1;
	int* temp = new int[len] { 0 }; //�����ڴ�� һ�� һ�� һ�� Ҫȫ����0, ��Ȼ������ʧ�� 
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


/*�鲢����*/
void MergeSort(int* data, int left, int right) {
	if (!data) return;
	//if (ordered(data, right)) return;//�ж������Ƿ�����
	
	int mid = (right + left) /2;

	//��data����ֳ�������
	//�ж�data�����±�Ϊ left �� mid-1 �� mid-left-1 ��Ԫ���Ƿ�����
	if (!ordered(data, right, left, mid - 1) && mid - left - 1 >= 1) 
		MergeSort(data, left, mid);
	
	//�ж�data�����±�Ϊ mid �� right-1 �� right-mid-1 ��Ԫ���Ƿ�����
	if (!ordered(data, right, mid, right - 1) && right - mid -1 >= 1)
		MergeSort(data, mid, right);

	int* temp = new int[right];
	if (!temp) return;

	int l = left;//�����ʼ����
	int m = mid; //�ұ���ʼ����
	int t = left;   //���źõ�Ԫ�ظ���

	while (l < mid && m < right) { // �������Ѿ�������ұ��Ѿ�����, ����ѭ��
		if (data[l] < data[m]) {
			temp[t++] = data[l++];
		}
		else temp[t++] = data[m++];
	}

	//����ұ��Ѿ����굫��߻�δ����,����������δ�����
	while (l < mid) temp[t++] = data[l++];

	//�������Ѿ����굫�ұ߻�δ����,��������ұ�δ�����
	while (m < right) temp[t++] = data[m++];

	copy(data, temp, right, left, right - 1);

	delete[] temp;
}

/*��������*/
void QuickSort(int* data, int startSub, int endSub) {
	if (!data || startSub < 0 || startSub >= endSub) return;

	int temp = data[startSub];//�ѻ�ֵ�Ƴ���, ��λ�þͱ���˿�λ(ָ�Ĳ��Ǹ�λ�õ�����Ϊ��)
	int start = startSub;
	int end = endSub;

	while (start < end) {
		while (start < end && data[end] >= temp) {//���ұ߿�ʼѰ��С�ڻ�ֵ��ֵ
			end--;
		}

		if (start < end) data[start++] = data[end];//�ҵ���, �Ѹ�ֵ�Ƶ���λ, ��λ�þͱ���˿�λ

		while (start < end && data[start] < temp) {//�ӱ߿�ʼѰ�Ҵ��ڻ���ڻ�ֵ��ֵ
			start++;
		}

		if (start < end) data[end--] = data[start];//�ҵ���, �Ѹ�ֵ�Ƶ���λ, ��λ�þͱ���˿�λ
	}
	//ѭ��������start�ǵ���end��
	data[start] = temp;

	QuickSort(data, startSub, end-1);  //�ݹ� startSub �� end-1 ֮���Ԫ��
	QuickSort(data, start+1, endSub);//�ݹ� start+1 �� endSub ֮���Ԫ��
}
