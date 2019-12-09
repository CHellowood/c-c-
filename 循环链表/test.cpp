#include <iostream>
#include <Windows.h>
#include "CycleLink.h"

using namespace std;

int main(void) {
	LinkHead* link = NULL;
	int i = 0, n = 0;

	cout << endl << "<<----------��ʼ��ѭ������---------->>" << endl;

	if (!initCycleLink(link)) {
		cout << "ѭ�������ʼ��ʧ��!" << endl;
		exit(1);
	}
	cout << "ѭ�������ʼ���ɹ�!" << endl;

	cout << endl << "<<----------������ͷ����ӽ��---------->>" << endl;

	cout << "Ҫ��ӵĽ�����:";
	cin >> i;

	while (i > 0) {
		i--;

		cout << "�������:";
		cin >> n;

		if (!addNode_Head(link, n)) {
			cout << "���ʧ��!" << endl;
			continue;
		}
		cout << "��ӳɹ�!" << endl;
	}

	printCycleLink(link);

	cout << endl << "<<----------������β����ӽ��---------->>" << endl;

	cout << "Ҫ��ӵĽ�����:";
	cin >> i;

	while (i > 0) {
		i--;

		cout << "�������:";
		cin >> n;

		if (!addNode_Tail(link, n)) {
			cout << "���ʧ��!" << endl;
			continue;
		}
		cout << "��ӳɹ�!" << endl;
	}

	printCycleLink(link);

	cout << endl << "<<----------�������в�����---------->>" << endl;
	int num = 0;

	cout << "Ҫ����Ľ�����:";
	cin >> num;

	while (num > 0) {
		num--;

		cout << "����λ�ú�����:";
		cin >> i >> n;

		if (!insertNode(link, i, n)) {
			cout << "����ʧ��!" << endl;
			continue;
		}
		cout << "����ɹ�!" << endl;
		printCycleLink(link);
	}

	cout << endl << "<<----------��������ɾ�����---------->>" << endl;

	cout << "Ҫɾ���Ľ�����:";
	cin >> n;

	while (num > 0) {
		n--;

		cout << "���λ��:";
		cin >> i;

		if (!deleteNode(link, i)) {
			cout << "ɾ��ʧ��!" << endl;
			continue;
		}
		cout << "ɾ���ɹ�!" << endl;
		printCycleLink(link);
	}

	cout << endl << "<<----------��������---------->>" << endl;

	destroyCycleLink(link);

	system("pause");
	return 0;
}