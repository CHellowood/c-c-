#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//�����С
#define DATA_NUM 10  
//���������Ԫ��ҪС��100
#define MAX_NUM 100

/*λͼ����*/
bool bitmap_rank(int* data, int size, int maxnum) {
	if (!data) return false;

	int* bitmap = new int[maxnum];
	if (!bitmap) return false;

	//����������ȫ����0
	memset(bitmap, 0, sizeof(bitmap[0])*maxnum);

	//λͼ����
	for (int i = 0; i < size; i++) {
		if (data[i] < maxnum) {
			bitmap[data[i]]++;
		}
	}

	//�������Ľ�����Ƶ����ݽ���������
	for (int j = 0, n = 0; j < maxnum;) {
		if (bitmap[j]-- > 0) {
			data[n++] = j;
		}
		else j++;
	}

	delete[] bitmap;
	return true;
}

//�������
int BinarySearch(int* data, int start, int tail, int num) {
	if (!data) return -2;
	if (start > tail) return -1;

	int mid = (start + tail) / 2;
	
	//��ǰ���ݵ���Ҫ���ҵ����ݾ�ֱ�ӷ���
	if (data[mid] == num) return mid; 
	//��ǰ����С��Ҫ���ҵ����ݾ����ұ���
	else if (data[mid] < num) return BinarySearch(data, mid + 1, tail, num);
	//��ǰ���ݴ���Ҫ���ҵ����ݾ��������
	else return BinarySearch(data, start, mid - 1, num);
}

int main(void) {
	int data[DATA_NUM];

	/*�������һ������*/
	srand((unsigned)time(NULL));
	for (int i = 0; i < DATA_NUM; i++) {
		data[i] = rand() % MAX_NUM;
		cout << data[i] << " ";
	}
	cout << endl;

	/*λͼ����*/
	if (bitmap_rank(data, DATA_NUM, MAX_NUM)) {
		cout << endl << "�����: ";
		for (int i = 0; i < DATA_NUM; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
		
		//�������
		while (true) {
			int num = 0;

			cout << "����: ";
			cin >> num;

			int const sub = BinarySearch(data, 0, DATA_NUM - 1, num);
			cout << sub << endl;
		}
	}

	system("pause");
	return 0;
}
