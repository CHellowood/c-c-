#include <Windows.h>
#include <graphics.h>
#include <time.h>

#define WINDOW_WIDTH  640
#define WINDOW_HEIGHT 480    
#define COLOR_MAX     255    //��������
#define STAR_NUM      666    //��������

//�����ƶ�����
enum MoveDir {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	DIR_NUM
};

//����
struct STAR {
	int x;
	int y;
	int step;
	int color;
	int dir;
};

STAR star[STAR_NUM];

//������ײ
void collision(int x, int y) {
	int circleSize = 1;          //Բ�İ뾶
	int circleX = x - circleSize;//Բ����ʼx����
	int circleY = y - circleSize;//Բ����ʼy����
		
	setlinecolor(RGB(0, 0, COLOR_MAX));
	circle(circleX, circleY, circleSize);		

	Sleep(50);

	setlinecolor(RGB(0, 0, 0));
	circle(circleX, circleY, circleSize);
}

//��ʼ������
void initStar(int i) {
	star[i].x = rand() % WINDOW_WIDTH;
	star[i].y = rand() % WINDOW_HEIGHT;
	star[i].step = (long)((rand() % 4) + 1);
	star[i].color = rand() % 255;
	star[i].dir = rand() % DIR_NUM;
}

//�ƶ�����
void moveStar(int i) {
	putpixel(star[i].x, star[i].y, 0);

	if (star[i].dir == UP) {
		star[i].y -= star[i].step;
	}
	else if (star[i].dir == DOWN) {
		star[i].y += star[i].step;
	}
	else if (star[i].dir == LEFT) {
		star[i].x -= star[i].step;
	}
	else if (star[i].dir == RIGHT) {
		star[i].x += star[i].step;
	}
	/*
	for (int j = 0; j < STAR_NUM; j++) {
		if (j != i && star[j].x == star[i].x && star[j].y == star[i].y) {
			collision(star[i].x, star[i].y);
			initStar(i);
			initStar(j);
			return;
		}
	}
*/
	if (star[i].x <= 0 || star[i].x >= WINDOW_WIDTH || 
		star[i].y <= 0 || star[i].y >= WINDOW_HEIGHT) 
		initStar(i);

	putpixel(star[i].x, star[i].y, RGB(star[i].color, star[i].color, star[i].color));
}

int main(void) {
	initgraph(640, 480);

	srand((unsigned)time(NULL));
	
	for (int i = 0; i < STAR_NUM; i++) {
		initStar(i);
		putpixel(star[i].x, star[i].y, star[i].color);
	}

	while (true) {
		for (int i = 0; i < STAR_NUM; i++) {
			moveStar(i);
		}
		Sleep(100);
	}

	system("pause");
	closegraph();
	return 0;
}