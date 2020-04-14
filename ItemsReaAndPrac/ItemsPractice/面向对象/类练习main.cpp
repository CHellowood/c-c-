#include <iostream>
#include <Windows.h>
#include <string>
#include "Class.h"

using namespace std;

int main(void) {
	Class cl, cll;
	cll = cl;

	const Class c;

	cl.description();
	cll.description();
	c.description();

	cl.modifyP("ÃÀ¹ú");

	cl.description();
	cll.description();

	cout << Class::callClassNum() <<endl;

	system("pause");
	return 0;
}