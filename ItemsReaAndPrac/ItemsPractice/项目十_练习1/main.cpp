#include <iostream>
#include <Windows.h>
#include "Toys.h"

int main(void) {
	Toys toys("±äÐÎ½ð¸Õ", 1000, "china");
	
	cout << toys.description() << endl;

	system("pause");
	return 0;
}
