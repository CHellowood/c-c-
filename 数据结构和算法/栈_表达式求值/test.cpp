#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "LinkStack.h"
#include "ExpEvaStack.h"

using namespace std;

int main(void) {
	Stack stack;
	char c[] = {"25*4 + 100/4- 15"};
	
	initStack(stack);

	input(stack);

	printStack(stack);

	result(stack);

	cout << " = " << stack.top->data << endl;
	

	system("pause");
	return true;
}