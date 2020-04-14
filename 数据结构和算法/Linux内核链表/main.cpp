#include <iostream>
#include <Windows.h>
#include "DoubleLink.h"
#include <typeinfo>


using namespace std;

int main(void) {
	DLink* link = NULL;
	int i=0;

	cout << endl << "<<----------��ʼ������---------->>" << endl;
	
	link = new DLink;
	
	if (!link) {
		cout << "��ʼ������ʧ��!" << endl;
		exit(-1);
	}

	link->data = -1;
	initDLink(link->pointer);//��ʼ��ָ����

	cout << "��ʼ������ɹ�!" << endl;

	cout << endl << "<<----------������ͷ����ӽ��---------->>" << endl;

	cout << "Ҫ��ӵĽ�����:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		DLink* newNode = new DLink;
		if (!newNode) {
			cout << "��" << j + 1 << "����������ڴ�ʧ��!" << endl;
			continue;
		}

		cout << "��" << j + 1 << "����������:";
		cin >> newNode->data;

		addNode_Head(link->pointer, newNode->pointer);
	}

	printDLink(link->pointer);

	cout << endl << "<<----------������β����ӽ��---------->>" << endl;

	cout << "Ҫ��ӵĽ�����:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		DLink* newNode = new DLink;
		if (!newNode) {
			cout << "��" << j + 1 << "����������ڴ�ʧ��!" << endl;
			continue;
		}

		cout << "��" << j + 1 << "����������:";
		cin >> newNode->data;

		addNode_Tail(link->pointer, newNode->pointer);
	}

	printDLink(link->pointer);

	cout << endl << "<<----------�������в�����---------->>" << endl;

	cout << "Ҫ����Ľ�����:";
	cin >> i;

	for (int j = 0, n = 0; j < i; j++) {
		DLink* newNode = new DLink;
		if (!newNode) {
			cout << "��" << j + 1 << "����������ڴ�ʧ��!" << endl;
			continue;
		}

		cout << "��" << j + 1 << "������λ�ú�����:";
		cin >> n >> newNode->data;

		if (!insertNode(link->pointer, n, newNode->pointer)) {
			cout << "����ʧ��!" << endl;
			delete newNode;
			continue;
		}
		cout << "����ɹ�!" << endl;
		printDLink(link->pointer);
	}

	cout << endl << "<<----------��������ɾ�����---------->>" << endl;

	cout << "Ҫɾ���Ľ�����:";
	cin >> i;

	for (int j = 0, n = 0; j < i; j++) {
		cout << "��" << j + 1 << "������λ��:";
		cin >> n;

		if (!deleteNode(link->pointer, n)) {
			cout << "ɾ��ʧ��!" << endl;
			continue;
		}

		cout << "ɾ���ɹ�!" << endl;
		printDLink(link->pointer);
	}

	cout << endl << "<<----------��������---------->>" << endl;

	destroyDLink(link->pointer);

	system("pause");
	return 0;
}
