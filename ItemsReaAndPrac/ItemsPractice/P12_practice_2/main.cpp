/*��������������, ����Щ���ݱ��浽data.txt�ļ���,
 *���������Ĺ������������, ����ʾ�û���������,
 *ָ���û���������(��ctrl+z), ÿ����ౣ��10������
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
	ofstream outfile;
	int data = 0;
	int n = 0;

	outfile.open("data.txt");
	if (!outfile.is_open()) {
		cout << "�ļ���ʧ��!\n";
		system("pause");
		exit(1);
	}

	cout << "����������[ctrl+z��������]\n";
	while (true) {
		cout << "������һ������:";
		cin >> data;
	
		while (cin.fail() && !cin.eof()) {
			cin.clear(); //��������־
			//cin.sync();//��VS����Ч
			//�����뻺������ȫ�����ݶ���յ�, ֱ���������з�����(���з�Ҳ���)
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "�������, ����������:";
			cin >> data;
		}

		if (cin.eof()) break;

		outfile << data << "\t";
		if (++n % 10 == 0) {
			outfile << "\n";
		}
	}

	outfile.close();
	system("pause");
	return 0;
}