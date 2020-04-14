#include <iostream>
#include "Father.h"
#include "Son.h"

void test(Father father) {
	cout << father.description() << endl;
}

int main(void) {
	Father father("Father", 55);
	Son son("Son", 20, "ÍõÕßÈÙÒ«");

	test(son);

	cout << father.description() << endl;
	cout << son.description() << endl;

	system("pause");
	return 0;
}