#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const double MAX = 1.5;

double data_compare(double data[], int data_len, int len) {
	double num = 0;
	for(int i=0; i<len; i++) {
		num += data[data_len - i]*data[data_len - i];
	}
	return num/len;
}

int main(void) {
	string filename;
	ifstream fin;
	int num = 0, short_window = 0, long_window = 0;
	double time_ = 0, *data = NULL, short_ = 0, long_ = 0; 

	cout << "������Ҫ�Ŀ����ļ���!" << endl;
	cin >> filename;

	fin.open(filename.c_str());
	if(fin.fail()) {
		cout << "�ļ���ʧ��!" << endl;
		system("pause");
		exit(-1);
	}
	else {
		fin >> num >> time_;
		//cout << "num: "<< num << "time_: "<< time_;
		
		if(num>=0) {
			data = new double[num];
			
			for(int i=0; i<num; i++) {
				fin >> data[i]; 
			}

			cout << "��ʱ�䴰�ڳ���: ";
			cin >> short_window;

			cout << "��ʱ�䴰�ڳ���: ";
			cin >> long_window; 

			for(int i=long_window-1; i<num; i++) {
				short_ = data_compare(data, i, short_window);
				long_ = data_compare(data, i, long_window);

				if(short_/long_ > MAX) {
					cout << "���ܳ��ֵ����ʱ�� " << time_*(i+1) << endl;

				}
			}
			delete[] data;

		}
		fin.close();
	}

	system("pause");
	return 0;
}