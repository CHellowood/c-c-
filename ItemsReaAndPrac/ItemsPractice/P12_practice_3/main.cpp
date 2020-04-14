#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

/*

//��ȡ���ֵ
int getMax(vector<int>& datas) {
	if (datas.size() < 1) {
		cout << "getMax: ����Ϊ��, �޷�����!";
		return 0;
	}

	int max = datas[0];
	for (int i = 1; i < datas.size(); i++) {
		if (max < datas[i]) {
			max = datas[i];
		}
	}
	return max;
}

//��ȡ��Сֵ
int getMin(vector<int>& datas) {
	if (datas.size() < 1) {
		cout << "getMin: ����Ϊ��, �޷�����!";
		return 0;
	}

	int min = datas[0];
	for (int i = 1; i < datas.size(); i++) {
		if (min > datas[i]) {
			min = datas[i];
		}
	}
	return min;
}

//��ȡƽ��ֵ
int getMean(vector<int>& datas) {
	if (datas.size() < 1) {
		cout << "getMean: ����Ϊ��, �޷�����!";
		return 0;
	}

	//�����ܺ�
	int sum = datas[0];
	for (int i = 1; i < datas.size(); i++) {
		sum += datas[i];
	}

	//����ƽ��ֵ
	return (sum / datas.size());
}

*/

int main(void) {
	ifstream infile;
	vector<int> datas;

	infile.open("data.txt");


	if (!infile.is_open()) {
		cout << "�ļ���ʧ��!\n";
		system("pause");
		exit(1);
	}

	//ѭ����ȡ
	while (true) {
		int num = 0;

		//��ȡһ������
		infile >> num;
		if (infile.eof()) break;

		//�Ѷ�ȡ�������ݱ��浽datas��
		datas.push_back(num);
	}

	//cout << "���ֵ: " << getMax(datas) << endl;
	//cout << "��Сֵ: " << getMin(datas) << endl;
	//cout << "ƽ��ֵ: " << getMean(datas) << endl;

	int max = datas[0];//���ֵ
	int min = datas[0];//��Сֵ
	int mean = 0;      //ƽ��ֵ
	int sun = datas[0];//��ֵ�ܺ�

	for (int i = 1; i < datas.size(); i++) {
		if (max < datas[i]) {
			max = datas[i];
		}
		else if (min > datas[i]) {
			min = datas[i];
		}
		sun += datas[i];
	}
	mean = sun / datas.size();

	cout << "��ֵ�ܺ�: " << sun << endl;
	cout << "���ֵ: " << max << endl;
	cout << "��Сֵ: " << min << endl;
	cout << "ƽ��ֵ: " << mean << endl;

	infile.close();
	system("pause");
	return 0;
}
