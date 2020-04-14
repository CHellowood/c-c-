#include <iostream>
#include <Windows.h>
#include "Queue.h"

using namespace std;

int main(void) {
	QUEUE* queue = NULL;

	queue = new QUEUE;
	if (!queue) {
		cout << "queue�ڴ�����ʧ��!" << endl;
		system("pause");
		exit(-1);
	}

	cout << endl << "<<----------��ʼ������---------->>" << endl;
	
	if (!initQueue(queue)) {
		cout << "���г�ʼ��ʧ��!" << endl;
		delete queue;
		system("pause");
		exit(-1);
	}
	cout << "���г�ʼ���ɹ�!" << endl;

	cout << endl << "<<----------Ԫ�����---------->>" << endl;
	int i = 0, n = 0;

	cout << "Ҫ��ӵ�Ԫ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << endl << "��" << j + 1 << "��:";
		cin >> n;

		addData(queue, n);
		printQueue(queue);
	}

	cout << endl << "<<----------Ԫ�س���---------->>" << endl;
	cout << queue->head << "    " << queue->tail << endl;

	for (int j = 0; j < 4;j++) {
		DataType num = 0;
		deleteData(queue, num);
		cout << endl << "���ӵ�Ԫ����: " << num << endl;
		printQueue(queue);
	}

	cout << endl << "<<----------Ԫ�����---------->>" << endl;

	cout << "Ҫ��ӵ�Ԫ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << endl << "��" << j + 1 << "��:";
		cin >> n;

		addData(queue, n);
		printQueue(queue);
	}

	cout << endl << "<<----------���ٶ���---------->>" << endl;
	destroyQueue(queue);


	system("pause");
	return 0;
}
