#include <iostream>
#include <Windows.h>
#include "LinkList.h"

using namespace std;

int main(void) {
	LinkHead* link = NULL;
	int i = 0, n = 0;

	cout << endl << "<<----------��ʼ������----------<<" << endl;

	if (initNode(link)) {
		cout << "�����ʼ���ɹ�!" << endl;
	}
	else {
		cout << "�����ʼ��ʧ��!" << endl;
		system("pause");
		return 0;
	}

	cout << endl << "<<----------������ͷ�����Ԫ��----------<<" << endl;

	cout << "������Ҫ������ͷ����ӵ�Ԫ�ظ���:";
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "��ͷ����ӵĵ�" << j+1 << "��Ԫ�ص�����:";
		cin >> n;

		if (addNodeHead(link, n)) {
			cout << "��ͷ�����Ԫ�سɹ�!" << endl;
		}
		else {
			cout << "��ͷ�����Ԫ��ʧ��!" << endl;
		}

		printNode(link);
	}

	cout << endl << "<<----------������β�����Ԫ��----------<<" << endl;

	cout << "������Ҫ������β����ӵ�Ԫ�ظ���:";
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "��β����ӵĵ�" << j + 1 << "��Ԫ�ص�����:";
		cin >> n;

		if (addNodeTail(link, n)) {
			cout << "��β�����Ԫ�سɹ�!" << endl;
		}
		else {
			cout << "��β�����Ԫ��ʧ��!" << endl;
		}

		printNode(link);
	}
/*
	cout << endl << "<<----------�������в���Ԫ��----------<<" << endl;
	
	int num = 0;
	cout << "������Ҫ�������в����Ԫ�ظ���:";
	cin >> num;
	for (int j = 0; j < num; j++) {
		cout << "Ҫ����ĵ�" << j+1 << "��Ԫ�ص�λ�ú�����:";
		cin >> i >> n;

		if (insertNode(link, i, n)) {
			cout << "��" << j + 1 << "��Ԫ�ز���ɹ�!" << endl;
		}
		else {
			cout << "��" << j + 1 << "��Ԫ�ز���ʧ��!" << endl;
		}

		printNode(link);
	}

	cout << endl << "<<----------���ݽ��λ���������в��ҽ��----------<<" << endl;

	cout << "�ý���������е�λ��:";
	cin >> i;

	if (!searchNode(link, i)) {
		cout << "�ý�㲻����!" << endl;
	}
*/
	cout << endl << "<<----------���ݽ�������������в��ҽ��----------<<" << endl;
	
	cout << "����Ҫ���ҵ�����:";
	cin >> n;

	searchData(link, n);

	cout << endl << "<<----------��������ɾ�����----------<<" << endl;
	
	cout << "������Ҫ��������ɾ����Ԫ�ظ���:";
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "Ҫɾ���ĵ�" << j + 1 << "������λ��:";
		cin >> n;

		if (deleteNode(link, n)) {
			cout << "ɾ�����ɹ�!" << endl;
		}
		else {
			cout << "ɾ�����ʧ��!" << endl;
		}

		printNode(link);
	}

	cout << endl << "<<----------��������----------<<" << endl;
	destroyLinkNode(link);

	system("pause");
	return 0;
}