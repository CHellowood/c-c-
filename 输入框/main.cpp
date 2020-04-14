#include <graphics.h>
#include <conio.h>
#include "InputField.cpp"

int main() {
	initgraph(640, 480);

	InputField<> infi;
	
	infi.display();
	while (true) {
		infi.MouseCilckInputField();
	}

	_getch();
	return 0;
}
