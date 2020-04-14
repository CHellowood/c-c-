#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

using namespace std;

/*

//获取最大值
int getMax(vector<int>& datas) {
	if (datas.size() < 1) {
		cout << "getMax: 数据为空, 无法计算!";
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

//获取最小值
int getMin(vector<int>& datas) {
	if (datas.size() < 1) {
		cout << "getMin: 数据为空, 无法计算!";
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

//获取平均值
int getMean(vector<int>& datas) {
	if (datas.size() < 1) {
		cout << "getMean: 数据为空, 无法计算!";
		return 0;
	}

	//计算总和
	int sum = datas[0];
	for (int i = 1; i < datas.size(); i++) {
		sum += datas[i];
	}

	//返回平均值
	return (sum / datas.size());
}

*/

int main(void) {
	ifstream infile;
	vector<int> datas;

	infile.open("data.txt");


	if (!infile.is_open()) {
		cout << "文件打开失败!\n";
		system("pause");
		exit(1);
	}

	//循环读取
	while (true) {
		int num = 0;

		//读取一个数据
		infile >> num;
		if (infile.eof()) break;

		//把读取到的数据保存到datas里
		datas.push_back(num);
	}

	//cout << "最大值: " << getMax(datas) << endl;
	//cout << "最小值: " << getMin(datas) << endl;
	//cout << "平均值: " << getMean(datas) << endl;

	int max = datas[0];//最大值
	int min = datas[0];//最小值
	int mean = 0;      //平均值
	int sun = datas[0];//数值总和

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

	cout << "数值总和: " << sun << endl;
	cout << "最大值: " << max << endl;
	cout << "最小值: " << min << endl;
	cout << "平均值: " << mean << endl;

	infile.close();
	system("pause");
	return 0;
}
