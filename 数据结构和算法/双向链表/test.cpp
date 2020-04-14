#include <iostream>
#include <Windows.h>
#include "DoubleLink.h"

using namespace std;

int main(void) {
	LinkHead* link = NULL;
	int i = 0, n = 0;

	cout << endl << "<<----------��ʼ��˫������----------<<" << endl;

	if (!initDoubleLink(link)) {
		cout << "˫�������ʼ��ʧ��!" << endl;
		exit(-1);
	}

	cout << endl << "<<----------������ͷ����ӽ��----------<<" << endl;

	cout << "Ҫ��ӵĽ�����:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << "��" << j + 1 << "����������:";
		cin >> n;

		if (!addNode_Head(link, n)) {
			cout << "���ʧ��!" << endl;
			continue;
		}
		cout << "��ӳɹ�!" << endl;
	}

	printDoubleLink(link);

	cout << endl << "<<----------������β����ӽ��----------<<" << endl;

	cout << "Ҫ��ӵĽ�����:";
	cin >> i;

	for (int j = 0; j < i; j++) {
		cout << "��" << j + 1 << "����������:";
		cin >> n;

		if (!addNode_Tail(link, n)) {
			cout << "���ʧ��!" << endl;
			continue;
		}
		cout << "��ӳɹ�!" << endl;
	}

	printDoubleLink(link);

	cout << endl << "<<----------�������в�����----------<<" << endl;

	int num = 0;
	cout << "Ҫ����Ľ�����:";
	cin >> num;

	for (int j = 0; j < num; j++) {
		cout << "��" << j + 1 << "����������:";
		cin >> i >> n;

		if (!inesrtNode(link, i, n)) {
			cout << "����ʧ��!" << endl;
			continue;
		}
		cout << "����ɹ�!" << endl;

		printDoubleLink(link);
	}

	cout << endl << "<<----------��������ɾ�����----------<<" << endl;

	cout << "Ҫɾ���Ľ�����:";
	cin >> num;

	for (int j = 0; j < num; j++) {
		cout << "��" << j + 1 << "������λ��:";
		cin >> i;

		if (!deleteNode(link, i)) {
			cout << "ɾ��ʧ��!" << endl;
			continue;
		}
		cout << "ɾ���ɹ�!" << endl;

		printDoubleLink(link);
	}
	
	cout << endl << "<<----------��������----------<<" << endl;

	destroyDoubleLink(link);

	system("pause");
	return 0;
}
