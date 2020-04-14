#include <graphics.h>
#include <Windows.h>
#include <stdio.h>
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib") //加载winmm.lib库文件

int main(void) {
	IMAGE bg;
	loadimage(&bg, _T("bg.jpg"), 480, 640);

	initgraph(480, 640);
	putimage(0, 0, &bg);	

	char song[] = "本墨置子-Cyberangel.mp3";
	int song_size = sizeof(song) / sizeof(song[0]);
	char* str = new char[song_size + 12 + 1];

	sprintf_s(str, song_size + 12, "play %s repeat", song);

	mciSendString(str, 0, 1, 0);

	system("pause");
	closegraph();
	return 0;
}
