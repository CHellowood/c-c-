/*
��3�� ���д����void fun(int x,int pp[],int *n),���Ĺ����ǣ����������x�Ҳ���
ż���ĸ�������������С�����˳�����pp��ָ�������У���Щ�����ĸ���ͨ���β�n���ء� 
*/

#include <iostream>

using namespace std;

void fun(int x, int pp[], int *n) {
	int num=0;
	for(int i=1; i<=x; i++) {
		if(x%i == 0 && i%2 != 0) {
			pp[num] = i;
			num++;
		}
	}
	*n = num;
}

int main3(void) {
	int x, n, pp[64];

	cout << "��3�� ���д����void fun(int x,int pp[],int *n),���Ĺ����ǣ����������x�Ҳ���" << endl
         << "ż���ĸ�������������С�����˳�����pp��ָ�������У���Щ�����ĸ���ͨ���β�n���ء� " << endl;
	
	while(1) {
		cout << endl << "x: ";
		cin >> x;

		fun(x, pp, &n);

		cout << "pp: ";
		for(int i=0; i<n; i++) {
			cout << pp[i] << ", ";
		}
		cout << endl << "��" << n << "��" << endl;
	}
	system("pause");
	return 0;
}