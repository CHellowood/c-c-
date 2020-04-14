#include <stdio.h>
#include <stdlib.h>

//������һ���ַ�
bool naxtChar(const char* str, int rows, int cols, int row, int col,
	 const char* substr, int& subscript, bool* tf) {

	//��ʾ������
	if (substr[subscript] == '\0') return true;

	bool temp = false;
	
	//��ǰ�ַ��Ƿ��ǵ�ǰҪ�ҵ��ַ� 
    //��:��������һ��
	//��:ֱ�ӷ���
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

//�������ַ���
bool searchSubstr(const char* str, int rows, int cols, const char* substr) {
	if (!str || !substr || rows <= 0 || cols <= 0) return false;

	bool* tf = new bool[rows * cols];
	setValue(tf, false, rows * cols);

	int subscript = 0;

	//ÿ���ַ������������һ��
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
		printf_s("����һ: PASS");
	}
	else {
		printf_s("����һ: FAIL");
	}

	system("pause");
	return 0;
}
