#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include "Graphics.h" //�Զ���ľ�̬��


int main() {
	initgraph(640, 480);

	square(220, 140, 420, 340);

	//circle(320, 240, 100);

	_circle(220, 140, 100);

	_getch();
	closegraph();
	return 0;
}