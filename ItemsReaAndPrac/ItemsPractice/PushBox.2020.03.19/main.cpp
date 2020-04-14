#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define WINDOW_WIDTH 960  //���ڿ��
#define WINDOW_HEIGHT 760 //���ڸ߶�

#define TRUE(pos) pos.y >= 0 && pos.y < MAP_HEIGHT && pos.x >= 0 && pos.x < MAP_WIDTH
#define POS(pos) map[pos.y][pos.x]

#define MAP_PY_WIDTH 0  //��ͼƫ�ƿ��
#define MAP_PY_HEIGHT 0 //��ͼƫ�Ƹ߶�

#define DAOJU_NAME_LEN 64 //�������ֳ���
#define DAOJU_SIZE 40	  //���ߴ�С

#define MAP_WIDTH 12      //��ͼ���
#define MAP_HEIGHT 9	  //��ͼ�߶�

#define BOX_GOAL_NUM 4    //����Ŀ�ĵص�����

#define KBHIT_UP 'w'   //��
#define KBHIT_DOWN 's' //��
#define KBHIT_LEFT 'a' //��
#define KBHIT_RIGHT 'd'//��
#define KBHIT_QUIT 'q' //�˳�

enum daoju_num {
	Wall,        //ǽ
	Floor,	     //�ذ�
	Box_Goal,    //����Ŀ�ĵ�
	Box,         //����
	Man,	     //��
	Box_Goal_Box,//���Ӻ�����Ŀ�ĵ��ص�
	ALL          //��������
};

struct _POS {    //���� 
	int x;
	int y;
};

enum advance {//����
	Up,   //��
	Down, //��
	Left, //��
	Right //��
};

struct _POS man = { 0, 0 };//��������

int age = Floor; //���  
int step = 0;
IMAGE daoju[ALL];//����

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
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

//�����µ�ͼ
int create_map[MAP_HEIGHT][MAP_WIDTH] = { 0 };

/*********************************************************************
*Ŀ��:   ��ָ��λ�ô�ӡָ��ͼƬ
*����:   ��������Ľṹ��ĵ�ַ, ͼƬ
*����ֵ: ��
**********************************************************************/
void image(struct _POS* pos, enum daoju_num num) {
	map[pos->y][pos->x] = num;
	putimage(MAP_PY_WIDTH + pos->x * DAOJU_SIZE, MAP_PY_HEIGHT + pos->y * DAOJU_SIZE, &daoju[num]);
}

//����
void step_num(int* p) {
	char str[10];
	sprintf_s(str, "����: %d", *p);

	settextcolor(RGB(255, 255, 255));
	settextstyle(20, 0, _T("����"));

	outtextxy(520, 20, str);
}

/*****************************************
*Ŀ��:   ʵ�������ƶ�
*����:   �����ƶ�����
*����ֵ: ��
******************************************/

void move(enum advance movexy) {
	struct _POS hero_pos = man;
	struct _POS hero_pos_ = man;


	switch (movexy) {
	case Up:
		hero_pos.y--;
		hero_pos_.y -= 2;
		break;
	case Down:
		hero_pos.y++;
		hero_pos_.y += 2;
		break;
	case Left:
		hero_pos.x--;
		hero_pos_.x -= 2;
		break;
	case Right:
		hero_pos.x++;
		hero_pos_.x += 2;
		break;
	}

	if (TRUE(hero_pos) && POS(hero_pos) == Floor) {         //����ǰһ���ǵذ�
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Floor;
		step++;
	}
	else if (TRUE(hero_pos) && POS(hero_pos) == Box_Goal) {//����ǰһ��������Ŀ�ĵ�
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Box_Goal;
		step++;
		//����ǰһ�������Ӻ�����Ŀ�ĵص��ص��������Ӻ�����Ŀ�ĵص��ص���ǰһ����ǽҲ��������
	}
	else if (TRUE(hero_pos) && POS(hero_pos) == Box_Goal_Box && POS(hero_pos_) != Wall && POS(hero_pos_) != Box && POS(hero_pos_) != Box_Goal_Box) {
		if (POS(hero_pos_) == Box_Goal) {
			image(&hero_pos_, Box_Goal_Box);
		}
		else {
			image(&hero_pos_, Box);
		}
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Box_Goal;
		step++;
	}
	else if (TRUE(hero_pos_) && POS(hero_pos) == Box && POS(hero_pos_) != Box) {//����ǰһ�������Ӷ�������ǰһ��������
		if (POS(hero_pos_) == Floor) {//����ǰһ���ǵذ�
			image(&hero_pos_, Box);
			image(&hero_pos, Man);
			image(&man, (enum daoju_num)age);
			man = hero_pos;
			age = Floor;
			step++;
		}
		else if (POS(hero_pos_) == Box_Goal) {//����ǰһ��������Ŀ�ĵ�
			image(&hero_pos_, Box_Goal_Box);
			image(&hero_pos, Man);
			image(&man, (enum daoju_num)age);
			man = hero_pos;
			age = Floor;
			step++;
		}
	}
}

/**************************************
*Ŀ��:   ��Ϸ��������
*����:   ��Ϸ����������Դ
*����ֵ: true��Ϸ���� false��Ϸ����
***************************************/
bool end_scene(IMAGE* img) {
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (map[i][j] == Box_Goal || map[i][j] == Box) {
				return false;
			}
		}
	}
	man.x = 0;
	man.y = 0;

	settextcolor(RGB(255, 0, 0));
	settextstyle(100, 0, _T("����"));

	cleardevice();

	putimage(0, 0, img);
	outtextxy(280, 334, _T("ͨ����!"));

	system("pause");
	return true;
}

/*******************************
*������Ϸ��Դ
*����:    img����������Ϸ����ͼƬ
*����ֵ:  ��
********************************/
void loadres(IMAGE& img) {
	char daoju_name[ALL][DAOJU_NAME_LEN];//������Ϸ��Դ���ļ���
	for (int i = 0; i < ALL; i++) {

	}

	loadimage(&img, _T("blackground.bmp"), WINDOW_WIDTH, WINDOW_HEIGHT, true);//���ر�����Դ
	putimage(0, 0, &img);													  //��ʾ����

	for (int i = Wall; i < ALL; i++) {                                             //������Ϸ������Դ
		sprintf_s(daoju_name[i], "daoju%d.bmp", i);
		loadimage(&daoju[i], daoju_name[i], DAOJU_SIZE, DAOJU_SIZE, true);
	}
	//outtextxy(0, 0, daoju_name[1]); system("pause"); //�鿴�ַ��Ƿ���ȷ
/*
	loadimage(&daoju[Wall], _T("daoju0.bmp"), DAOJU_SIZE, DAOJU_SIZE, true);
	loadimage(&daoju[Floor], _T("daoju1.bmp"), DAOJU_SIZE, DAOJU_SIZE, true);
	loadimage(&daoju[Box_Goal], _T("daoju2.bmp"), DAOJU_SIZE, DAOJU_SIZE, true);
	loadimage(&daoju[Box], _T("daoju3.bmp"), DAOJU_SIZE, DAOJU_SIZE, true);
	loadimage(&daoju[Man], _T("daoju4.bmp"), DAOJU_SIZE, DAOJU_SIZE, true);
	loadimage(&daoju[Box_Goal_Box], _T("daoju5.bmp"), DAOJU_SIZE, DAOJU_SIZE, true);
*/
}

/***********************************
*��Ϸ���Ƽ�:
*����:    img��Ϸ��������
*����ֵ:  ��
************************************/
void input(IMAGE& img) {
	while (!end_scene(&img)) {
		step_num(&step);
		if (_kbhit()) {	       //�Ƿ񰴼�
			char ch = _getch();//���µļ����ַ�
			if (ch == KBHIT_UP) {         //��
				move(Up);
			}
			else if (ch == KBHIT_DOWN) { //��
				move(Down);
			}
			else if (ch == KBHIT_LEFT) { //��
				move(Left);
			}
			else if (ch == KBHIT_RIGHT) {//��
				move(Right);
			}
			else if (ch == KBHIT_QUIT) { //�˳�
				break;
			}
		}
		Sleep(100);
	}
}

//��ʾ��Ϸ����
void dispiayScene(IMAGE& img) {
	cleardevice();
	putimage(0, 0, &img);
	for (int i = 0; i < MAP_HEIGHT; i++) {										  //��ʾ��Ϸ����
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (map[i][j] == Man) {//�����λ��
				man.x = j;
				man.y = i;
			}

			putimage(MAP_PY_WIDTH + j * DAOJU_SIZE, MAP_PY_HEIGHT + i * DAOJU_SIZE, &daoju[map[i][j]]);
		}
	}
	input(img);//��Ϸ���Ƽ�
}



//������ͼ
void createMap(IMAGE& img) {
	_POS temp_man = { 0, 0 };

	cleardevice();
	putimage(0, 0, &img);
	for (int i = 0; i < MAP_HEIGHT; i++) {										  //��ʾ��Ϸ����
		for (int j = 0; j < MAP_WIDTH; j++) {
			putimage(MAP_PY_WIDTH + j * DAOJU_SIZE, MAP_PY_HEIGHT + i * DAOJU_SIZE, &daoju[create_map[i][j]]);
		}
	}

	setbkmode(TRANSPARENT);         //���������ʱ�ı�����Ϊ͸����
	settextcolor(RGB(225, 0, 0));
	settextstyle(25, 0, _T("����"));

	outtextxy(640, 30, "w: ��");
	outtextxy(640, 60, "s: ��");
	outtextxy(640, 90, "a: ��");
	outtextxy(640, 120, "d: ��");
	outtextxy(640, 150, "t: �л�");
	outtextxy(640, 180, "k: ����");
	outtextxy(640, 210, "q: ����");

	while (true) {

		if (!_kbhit()) {	       //�Ƿ񰴼�
			putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
		}
		else {
			switch (_getch()) {//���µļ����ַ�
			case KBHIT_UP:          //��
				if (temp_man.y > 0) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.y--;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case KBHIT_DOWN:  //��
				if (temp_man.y < MAP_HEIGHT - 1) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.y++;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case KBHIT_LEFT: //��
				if (temp_man.x > 0) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.x--;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case KBHIT_RIGHT://��
				if (temp_man.x < MAP_WIDTH - 1) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.x++;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case 't': //�л�
				create_map[temp_man.y][temp_man.x] = (create_map[temp_man.y][temp_man.x] + 1) % ALL;
				putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
				Sleep(100);
				break;
			case 'k':
				for (int i = 0; i < MAP_HEIGHT; i++) {										  //��ʾ��Ϸ����
					for (int j = 0; j < MAP_WIDTH; j++) {
						map[i][j] = create_map[i][j];
					}
				}
			case KBHIT_QUIT: //�˳�
				return;
			}
		}
		Sleep(100);
	}
}

//��Ϸ��ʼ����
bool startInterface(IMAGE& img) {
	cleardevice();

	putimage(0, 0, &img);

	settextcolor(RGB(255, 0, 0));
	settextstyle(25, 0, _T("����"));

	outtextxy((WINDOW_WIDTH) / 5 * 2, WINDOW_HEIGHT / 2, _T("��ʼ��Ϸ[s]"));
	outtextxy((WINDOW_WIDTH) / 5 * 2, WINDOW_HEIGHT / 2 + 30, _T("������ͼ[c]"));
	outtextxy((WINDOW_WIDTH) / 5 * 2, WINDOW_HEIGHT / 2 + 30 + 30, _T("�˳���Ϸ[e]"));

	char ch = ' ';
	while (ch != 's' && ch != 'c' && ch != 'e') {
		ch = _getch();
	}

	if (ch == 's') {
		dispiayScene(img);//��ʾ��Ϸ����
	}
	else if (ch == 'c') {
		createMap(img);
	}
	else if (ch == 'e') {
		return false;
	}
	return true;
}

int main1(void) {
	IMAGE img;

	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);//��ʼ����ͼ����

	loadres(img);//������Ϸ��Դ

	while (startInterface(img)) {
		//��Ϸ��ʼ����
	}

	system("pause");
	closegraph();    //�ر�ͼ�ν���
	return 0;
}