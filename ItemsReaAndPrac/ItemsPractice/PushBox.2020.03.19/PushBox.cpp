#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <conio.h>
#include "resource.h"
#include "Map.cpp"
//#include "Role.cpp"
//#include "Box.cpp"

int main() {
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	loadResource();

	//putimage(0, 0, &bgs[(int)BG::BG1]);

	//putimage(0, 0, &roles[(int)ROLE::Tom]);

	Map<> map(mapData, mapLength, mapWidth, true, true, true);
	map.display();
	map.move();

	
	system("pause");
	closegraph();
	return 0;
}