#include <iostream>
#include <Windows.h>
//#include "Money.h"
//#include "Pork.h"
//#include "Beef.h"
#include "Boy.h"
#include "Man.h"

using namespace std;

int main(void) {
	/*//----------˫Ŀ��������ز���----------
	Pork p1(10);
	Pork p2(20);
	Beef b1(10);
	Beef b2(20);

	Money m = p1 + p2;

	cout << m.description() << endl;

	m = p1 + b1;

	cout << m.description() << endl;

	m = b1 + b2;

	cout << m.description() << endl;

	m = b1 + p2;

	cout << m.description() << endl;
	*/
	
	/*//----------��ֵ��������ز���----------
	Boy boy1("��Ϯ", 18, 4000, 10);
	Boy boy2;

	cout << boy1.description() << endl;
	cout << boy2.description() << endl;

	boy2 = boy1;

	cout << "\n������:\n";

	cout << boy1.description() << endl;
	cout << boy2.description() << endl;
	*/

	/*//----------��ϵ��������ز���----------
	Boy boy3("Tom", 22, 12000, 10);
	Boy boy4("Jerry", 22, 10000, 10);

	if (boy3 > boy4) {
		cout << "ѡ��boy3\n";
	}
	else if (boy3 == boy4) {
		cout << "boy3��boy4һ�����㣬 ��ѡ��һ���أ�\n";
	}
	else if (boy3 < boy4) {
		cout << "ѡ��boy4\n";
	}
	*/

	////----------�±���������ز���----------
	//Boy boy5("while-��Ϯ", 18, 4000, 10);

	////����name���ַ��������±���������ص��������� ������Ҫ����ǿ������ת��
	////cout << "name: " << (char*)boy5[NAME_KEY] << endl;
	//cout << "age: " << boy5[AGE_KEY] << endl;
	//cout << "salary: " << boy5[SALARY_KEY] << endl;
	//cout << "darkHorse: " << boy5[DARK_HORSE_KEY] << endl;

	//cout << endl;

	////cout << "name: " << (char*)boy5[NAME] << endl;
	//cout << "age: " << boy5[AGE] << endl;
	//cout << "salary: " << boy5[SALARY] << endl;
	//cout << "darkHorse: " << boy5[DARK_HORSE] << endl;

	////----------���������������ز���----------
	//Boy boy6("while-��Ϯ", 18, 4000, 10);
	//Boy boy7;

	//////�ó�Ա����ʵ�������������� 
	//////���Ƽ�ʹ�ó�Ա������ʵ��������������
	////boy6 << cout << endl;
	////boy7 << (boy6 << cout << endl) << endl;

	//////�ó�Ա����ʵ��������������� 
	//////���Ƽ�ʹ�ó�Ա������ʵ���������������
	////boy7 >> cin;
	//////boy6 >> (boy7 >> cin);

	////boy7 << cout << endl;

	////ʹ��ȫ����Ԫ������ʵ��������������
	//cout << boy6 << endl << boy7 << endl;

	////ʹ��ȫ����Ԫ������ʵ���������������
	//cin >> boy7;
	//cout << boy7 << endl;

	////----------��ͨ����ת������----------
	//Boy boy8 = 10000;//���캯��Boy(int);
	//
	//cout << boy8 << endl;

	////----------������ת��ͨ����(�������������)----------
	//Boy boy9("����ѩ", 18, 4000, 10);

	//int power = boy9;
	//char* name = boy9;

	//cout << power << endl;
	//cout << name << endl;

	////----------������ת������----------
	//Boy boy10("while", 18, 4000, 10);
	//Man man = boy10;//���캯�� Man(Boy&);

	//cout << boy10 << endl;
	//cout << man << endl;

	system("pause");
	return 0;
}