#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

/*��ȡ�ļ���С:
 *����:   fileName: �ļ���
 *����ֵ: �ļ���С, -1��ʾ�ļ�������*/
long long getFileSize(const char* fileName) {
	ifstream infile;

	infile.open(fileName);
	if (!infile.is_open()) {
		return -1;
	}

	/*�����ļ���ָ��λ��(�ֽ�)
	 *�Զ�ȡ��ʽ���ļ�ʱʹ��seekg
	 *�����뷽ʽ���ļ�ʱʹ��seekp
	 *��һ������: ƫ����
	 *�ڶ�������: �ļ���λ��
	 *beg �ļ���ʼλ��
	 *cur �ļ���ǰλ��
	 *end �ļ�����λ��*/
	infile.seekg(0, infile.end);

	/*��ȡ��ʼλ�õ���ǰλ�þ���(�ֽ�)
	 *�Զ�ȡ��ʽ���ļ�ʱʹ��tellg
	 *�����뷽ʽ���ļ�ʱʹ��tellp*/
	long long ret = infile.tellg();
	infile.close();

	return ret;
}

int main(void) {
	cout << getFileSize("�ļ��������д.cpp") << "\n";

	ofstream outfile;
	outfile.open("test.txt");
	if (!outfile.is_open()) {
		system("pause");
		exit(-1);
	}

	outfile << "1234567890";

	outfile.seekp(-5, outfile.end);

	outfile << "???";

	outfile.close();
	system("pause");
	return 0;
}
