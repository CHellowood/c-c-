#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>

using namespace std;

#define WINDOW_WIDTH 960  //���ڿ��
#define WINDOW_HEIGHT 768 //���ڸ߶�

#define TRUE(pos) pos.y >= 0 && pos.y < MAP_HEIGHT && pos.x >= 0 && pos.x < MAP_WIDTH

#define MAP_PY_WIDTH 100  //��ͼƫ�ƿ��
#define MAP_PY_HEIGHT 150 //��ͼƫ�Ƹ߶�

#define DAOJU_NAME_LEN 64 //�������ֳ���
#define DAOJU_SIZE 61	  //���ߴ�С

#define MAP_WIDTH 12      //��ͼ���
#define MAP_HEIGHT 9	  //��ͼ�߶�

#define BOX_GOAL_NUM 4    //����Ŀ�ĵص�����

#define KBHIT_UP 'w'   //��
#define KBHIT_DOWN 's' //��
#define KBHIT_LEFT 'a' //��
#define KBHIT_RIGHT 'd'//��
#define KBHIT_QUIT 'q' //�˳�

enum daoju_num{
	Wall,        //ǽ
	Floor,	     //�ذ�
	Box_Goal,    //����Ŀ�ĵ�
	Box,         //����
	Man,	     //��
	Box_Goal_Box,//���Ӻ�����Ŀ�ĵ��ص�
	ALL          //��������
};

IMAGE daoju[ALL];//����

struct _POS {    //���� 
	int x;
	int y;
};

enum advance{//����
	Up,   //��
	Down, //��
	Left, //��
	Right //��
};

struct _POS man;//��������
struct _POS box_goal[BOX_GOAL_NUM];

int age = Floor;
//��ʼ����Ϸ��ͼ
int map[MAP_HEIGHT][MAP_WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 1, 0, 1, 0, 2, 0, 0, 2, 1, 1, 0},
		{0, 1, 3, 1, 0, 1, 1, 1, 1, 1, 1, 0},
		{0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0},
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 0},
		{0, 1, 2, 1, 1, 3, 1, 1, 3, 0, 1, 0},
		{0, 1, 0, 2, 0, 1, 1, 1, 1, 0, 4, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

/*********************************************************************
*Ŀ��:   ��ָ��λ�ô�ӡָ��ͼƬ
*����:   ��������Ľṹ��ĵ�ַ, ͼƬ
*����ֵ: ��
**********************************************************************/
void image(struct _POS *pos, enum daoju_num num) {
	map[pos->y][pos->x] = num;
	putimage(MAP_PY_WIDTH + pos->x * DAOJU_SIZE, MAP_PY_HEIGHT + pos->y * DAOJU_SIZE, &daoju[num]);
}

/*****************************************
*Ŀ��:   ʵ�������ƶ�
*����:   �����ƶ�����
*����ֵ: ��
******************************************/

void move(enum advance movexy) {
	struct _POS hero_pos = man;
	struct _POS hero_pos_ = man;

	switch(movexy) {
		case Up:
			hero_pos.y--;
			hero_pos_.y-=2;
			break;
		case Down:
			hero_pos.y++;
			hero_pos_.y+=2;
			break;
		case Left:
			hero_pos.x--;
			hero_pos_.x-=2;
			break;
		case Right:
			hero_pos.x++;
			hero_pos_.x+=2;
			break;
	}

	if(TRUE(hero_pos) && map[hero_pos.y][hero_pos.x] == Floor) {     //����ǰһ���ǵذ�
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Floor;
	}else if(TRUE(hero_pos) && map[hero_pos.y][hero_pos.x] == Box_Goal) {
		image(&hero_pos, Man);
		image(&man, Floor);
		man = hero_pos;
		age = Box_Goal;
	}else if(TRUE(hero_pos) && map[hero_pos.y][hero_pos.x] == Box_Goal_Box) {
			image(&hero_pos_, Box);
			image(&hero_pos, Man);
			image(&man, Floor);
			man = hero_pos;
			age = Box_Goal;
	}else if(TRUE(hero_pos_) && map[hero_pos.y][hero_pos.x] == Box) {//����ǰһ��������
		if(map[hero_pos_.y][hero_pos_.x] == Floor) {                 //����ǰһ���ǵذ�
			image(&hero_pos_, Box);
			image(&hero_pos, Man);
			image(&man, (enum daoju_num)age);
			man = hero_pos;
			age = Floor;
		}else if(map[hero_pos_.y][hero_pos_.x] == Box_Goal) {        //����ǰһ��������Ŀ�ĵ�
			image(&hero_pos_, Box_Goal_Box);
			image(&hero_pos, Man);
			image(&man, Floor);
			man = hero_pos;
		}
	}
}

/**************************************
*Ŀ��:   ��Ϸ��������
*����:   ��Ϸ����������Դ
*����ֵ: true��Ϸ���� false��Ϸ����
***************************************/
bool end_scene(IMAGE *img) {
	for(int i=0; i<MAP_HEIGHT; i++) {
		for(int j=0; j<MAP_WIDTH; j++) {
			if(map[i][j] == Box_Goal) {
				return false;
			}
		}
	}
	settextcolor(RGB(255, 0, 0));
	settextstyle(100, 0, "����");

	putimage(0, 0, img);
	outtextxy(280, 334, "ͨ����!");
	return true;
}

int main(void) {
	
	IMAGE img;
	char daoju_name[ALL][DAOJU_NAME_LEN];								      //������Ϸ��Դ���ļ���
	
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	loadimage(&img, _T("blackground.bmp"), WINDOW_WIDTH, WINDOW_HEIGHT, true);//���ر�����Դ
	putimage(0, 0, &img);													  //��ʾ����

	for(int i=Wall; i<ALL; i++) {                                             //������Ϸ������Դ
		sprintf(daoju_name[i], "daoju%d.bmp", i);
		loadimage(&daoju[i], _T(daoju_name[i]), DAOJU_SIZE, DAOJU_SIZE, true);
	}
	
	for(int i=0, num=0; i<MAP_HEIGHT; i++) {										  //��ʾ��Ϸ����
		for(int j=0; j<MAP_WIDTH; j++) {
			if(map[i][j] == Man) {
				man.x = j;
				man.y = i;
			}else if(map[i][j] == Box_Goal) {
				box_goal[num].x = j;
				box_goal[num].y = i;
				num++;
			}
			putimage(MAP_PY_WIDTH +j*DAOJU_SIZE, MAP_PY_HEIGHT+i*DAOJU_SIZE, &daoju[map[i][j]]);
		}
	}

	bool quit = false;
	while(!quit) {
		if(_kbhit()) {	       //�Ƿ񰴼�
			char ch = _getch();//���µļ����ַ�

			if(ch == KBHIT_UP) {         //��
				move(Up);
			}else if(ch == KBHIT_DOWN) { //��
				move(Down);
			}else if(ch == KBHIT_LEFT) { //��
				move(Left);
			}else if(ch == KBHIT_RIGHT) {//��
				move(Right);
			}else if(ch == KBHIT_QUIT) { //�˳�
				quit = true;
			}
			
			end_scene(&img);
		}
		Sleep(100);
	}

	system("pause");
	closegraph();    //�ر�ͼ�ν���
	return 0;
}