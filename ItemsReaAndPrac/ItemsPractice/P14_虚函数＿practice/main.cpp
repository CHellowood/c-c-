#include <iostream>
#include <Windows.h>
#include "Father.h"
#include "Son.h"

void party(Father** fathers, int n) {
	for (int i = 0; i < n; i++) {
		fathers[i]->play();
	}
}

int main() {
	Father father;
	Son son1, son2;

	Father* fathers[] = {&father, &son1, &son2};

	party(fathers, 3);

	system("pause");
	return 0;
}
