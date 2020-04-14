#include <stdio.h>
#include <stdlib.h>
#include "Father.h"
#include "Mother.h"
#include "Child.h"

void copy() {
	
}

int main(void) {
	Father father;
	Mother mother;
	Child  child;

	child.Father::cook();
	child.Mother::cook();
	child.cook();

	system("pause");
	return 0;
}