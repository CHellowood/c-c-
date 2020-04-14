#include <iostream>
#include <Windows.h>
#include "LinkQueue.h"

using namespace std;

int main(void) {
	QUEUE* queue = new QUEUE;
	if (!queue) {
		cout << "queue�ڴ�����ʧ��!" << endl;
		system("pause");
		exit(-1);
	}

	cout << endl << "<<----------��ʼ�����������---------->>" << endl;
	if (!initQueue(queue)) {
		cout << "��������г�ʼ��ʧ��!" << endl;
		delete queue;
		system("pause");
		exit(-1);
	}
	cout << "��������г�ʼ���ɹ�!" << endl;

	cout << endl << "<<----------������������---------->>" << endl;
	int i = 0, n = 0;

	cout << "Ҫ��ӵ�Ԫ�ظ���:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << endl << "��" << j + 1 << "��:";
		cin >> n;

		if (!addNode(queue, &n)) {
			cout << "���ʧ��!" << endl;
			continue;
		}
		cout << "��ӳɹ�!" << endl;
		printQueue(queue);
	}
	cout << endl << "<<----------��������г���---------->>" << endl;

	cout << "Ҫ���ӵ�Ԫ�ظ���:";
	cin >> i;

	if (i > queue->length) {
		cout << endl << i << "�ѳ�����ǰ�����Ԫ�ظ��� " << queue->length << endl;
		i = queue->length;
		cout << "�ѽ� " << i << "��ǰ�����Ԫ�ظ��� " << queue->length << endl;
	}

	for (int j = 0; j < i; j++) {
		DataType num = 0;
		if (!deleteNode(queue, &num)) {
			cout << "����ʧ��!" << endl;
			continue;
		}
		cout << endl << "���ӳɹ�,���ӵ���:" << num << endl;
		printQueue(queue);
	}

	cout << endl << "<<----------��ն���---------->>" << endl;

	clearQueue(queue);

	system("pause");
	return 0;
}
