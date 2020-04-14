#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int copyFile(const char* infile, const char* outfile) 
	throw(int)/*�����쳣����ʱֻ���׳����������쳣����
		   ��������Ϊ�ձ�ʾ��ֹ�׳��쳣��
		    �������쳣���Ϳ����׳��κ����͵��쳣*/
{
	FILE* in, * out;

	/*
			  +---�ļ���
			  |      +---�ļ���
			  |      |      +---�򿪷�ʽ
	 fopen_s(&in, infile, "rb");
	*/
	fopen_s(&in, infile, "rb");
	if (!in) throw -1; //�׳��쳣

	fopen_s(&out, outfile, "wb");
	if (!out) {
		fclose(in);
		throw - 2; //�׳��쳣
	}

	char temp[1024];
	int insize = 0;
	while ((insize = fread(temp, 1, 1024, in)) > 0) {
		if (fwrite(temp, 1, insize, out) != insize) {
			fclose(in);
			fclose(out);
			throw -3; //�׳��쳣
		}
	}
	fclose(in);
	fclose(out);

	return 0;
}

int copyFile1(const char* infile, const char* outfile) {
	return copyFile(infile, outfile);
}

int main() {

	try {
		copyFile1("e:/Github/c-c-/ItemsReaAndPrac/ItemsPractice/�ļ�����/test.txt",
			"e:/Github/c-c-/ItemsReaAndPrac/ItemsPractice/P15ExceptionPractice/test.txt");
	}
	catch(int error){//��׽�쳣��int���ͣ�
		switch (error) {
		case -1:
			printf_s("��ȡ�ļ���ʧ�ܣ�\n");
			break;
		case -2:
			printf_s("д���ļ���ʧ�ܣ�\n");
			break;
		case -3:
			printf_s("����ʱ�����쳣��\n");
			break;
		default:
			printf_s("���棬����δ֪�쳣��%d\n", error);
		}
	}
	catch (...) {//��׽�쳣���������ͣ�
		printf_s("���棬����δ֪���͵��쳣��\n");
	}

	system("pause");
	return 0;
}