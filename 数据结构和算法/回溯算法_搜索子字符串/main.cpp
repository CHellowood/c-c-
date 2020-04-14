#include <stdio.h>
#include <stdlib.h>

//搜索下一个字符
bool naxtChar(const char* str, int rows, int cols, int row, int col,
	 const char* substr, int& subscript, bool* tf) {

	//表示找完了
	if (substr[subscript] == '\0') return true;

	bool temp = false;
	
	//当前字符是否是当前要找的字符 
    //是:继续找下一个
	//否:直接返回
	if (row >= 0 && row < rows && col >= 0 && col < cols &&
		!tf[row * cols + col] && str[row * cols + col] == substr[subscript]) {
		
		subscript++;
		tf[row * cols + col] = true;

		temp = naxtChar(str, rows, cols, row + 1, col, substr, subscript, tf) ||
			naxtChar(str, rows, cols, row, col + 1, substr, subscript, tf) ||
			naxtChar(str, rows, cols, row - 1, col, substr, subscript, tf) ||
			naxtChar(str, rows, cols, row, col - 1, substr, subscript, tf);

		if (!temp) {
			subscript--;
			tf[row * cols + col] = false;
		}
	}
	return temp;
}

void setValue(bool* tf, bool value, int size) {
	if (tf) {
		for (int i = 0; i < size; i++) {
			tf[i] = value;
		}
	}
}

//搜索子字符串
bool searchSubstr(const char* str, int rows, int cols, const char* substr) {
	if (!str || !substr || rows <= 0 || cols <= 0) return false;

	bool* tf = new bool[rows * cols];
	setValue(tf, false, rows * cols);

	int subscript = 0;

	//每个字符都当作起点找一遍
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (naxtChar(str, rows, cols, i, j, substr, subscript, tf)) {
				return true;
			}
		}
	}
	return false;
}

/*
ABCDEF
GHIJKL
MNOPQR
STUVWX
*/
int main(void) {
	const char* str = "ABCDEFGHIJKLMNOPQRSTUVWX";
	const char* substr = "ABCDEFLKJIHG";

	if (searchSubstr(str, 4, 6, substr)) {
		printf_s("测试一: PASS");
	}
	else {
		printf_s("测试一: FAIL");
	}

	system("pause");
	return 0;
}
