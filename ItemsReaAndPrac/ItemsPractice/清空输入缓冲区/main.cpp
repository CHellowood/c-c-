#include <stdio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

int main(void) {
	while(true) {
		int i=0;
		cout << "----------" << endl;
		while(!(cin >> i)) {
			cin.clear();//�����ȡ����ı�־
			cin.sync(); //������뻺����
			//cin.ignore('\n');//��ȡָ���������ַ�(Ĭ��1��) �� ��ȡ�ַ�ֱ������ָ���ַ�(Ĭ��EOF)

			cout << "�������!" << endl << "----------" << endl;
		}

		cout << i << endl;
	}
	system("pause");
	return 0;
	
}