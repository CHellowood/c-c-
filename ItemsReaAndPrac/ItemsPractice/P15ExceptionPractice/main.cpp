#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int copyFile(const char* infile, const char* outfile) 
	throw(int)/*声明异常类型时只能抛出已声明的异常类型
		   （括号里为空表示禁止抛出异常）
		    不声明异常类型可以抛出任何类型的异常*/
{
	FILE* in, * out;

	/*
			  +---文件流
			  |      +---文件名
			  |      |      +---打开方式
	 fopen_s(&in, infile, "rb");
	*/
	fopen_s(&in, infile, "rb");
	if (!in) throw -1; //抛出异常

	fopen_s(&out, outfile, "wb");
	if (!out) {
		fclose(in);
		throw - 2; //抛出异常
	}

	char temp[1024];
	int insize = 0;
	while ((insize = fread(temp, 1, 1024, in)) > 0) {
		if (fwrite(temp, 1, insize, out) != insize) {
			fclose(in);
			fclose(out);
			throw -3; //抛出异常
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
		copyFile1("e:/Github/c-c-/ItemsReaAndPrac/ItemsPractice/文件操作/test.txt",
			"e:/Github/c-c-/ItemsReaAndPrac/ItemsPractice/P15ExceptionPractice/test.txt");
	}
	catch(int error){//捕捉异常（int类型）
		switch (error) {
		case -1:
			printf_s("读取文件打开失败！\n");
			break;
		case -2:
			printf_s("写入文件打开失败！\n");
			break;
		case -3:
			printf_s("拷贝时出现异常！\n");
			break;
		default:
			printf_s("警告，出现未知异常！%d\n", error);
		}
	}
	catch (...) {//捕捉异常（所有类型）
		printf_s("警告，出现未知类型的异常！\n");
	}

	system("pause");
	return 0;
}