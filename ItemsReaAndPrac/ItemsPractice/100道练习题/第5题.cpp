/*
��5�� ���дһ������void fun(int m,int k,int xx[]),�ú����Ĺ����ǣ�����������m�ҽ���m��k����������xx��ָ�������С� 
*/

#include <iostream>
#include <Windows.h>

using namespace std;

void fun(int m, int k, int xx[]) {
	int num=0;

	for(int i=m+1; i<k; i++) {
		if(i == 2) {
			xx[num] = i;
			num++;
			continue;
		}
		for(int j=2; j<i; j++) {
			if(!(i%j)) break;
			if(j >= i-1) {
				xx[num] = i;
				num++;
			}
		}
	}
}


int main5(void) {
	int m=0, k=0, xx[64]={0};

	cout << "��5�� ���дһ������void fun(int m,int k,int xx[]),�ú����Ĺ����ǣ�����������m�ҽ���m��k����������xx��ָ�������С�" << endl;

	while(true) {
		go:
		cout << endl << "--------------------" << endl;

		cout << "m: ";
		while(!(cin >> m)) {
			cin.clear();
			cin.sync();

			cout << "�������!" << endl;
			goto go;
		}

		cout << "k: ";
		while(!(cin >> k)) {
			cin.clear();
			cin.sync();

			cout << "�������!" << endl;
			goto go;
		}

		if(m < 0) {
			cout << "m�Ǹ���!" << endl;
			continue;
		}else if(m == 0 && k == 0) {
			cout << endl << "m��k��Ϊ0" << endl;
			//system("pause");
			//break;
			continue;
		}else if(m > k) {
			cout << "m > k����������!" << endl;
			continue;
		}

		fun(m, k, xx);

		cout << m << "��" << k << "֮�������: ";

		for(int i=0; i<64; i++) {
			if(xx[i] > 0) 
			cout << xx[i] << "  ";
		}

	}

	system("pause");
	return 0;
}