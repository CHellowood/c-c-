#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define WINDOW_WIDTH 960  //窗口宽度
#define WINDOW_HEIGHT 760 //窗口高度

#define TRUE(pos) pos.y >= 0 && pos.y < MAP_HEIGHT && pos.x >= 0 && pos.x < MAP_WIDTH
#define POS(pos) map[pos.y][pos.x]

#define MAP_PY_WIDTH 0  //地图偏移宽度
#define MAP_PY_HEIGHT 0 //地图偏移高度

#define DAOJU_NAME_LEN 64 //道具名字长度
#define DAOJU_SIZE 40	  //道具大小

#define MAP_WIDTH 12      //地图宽度
#define MAP_HEIGHT 9	  //地图高度

#define BOX_GOAL_NUM 4    //箱子目的地的数量

#define KBHIT_UP 'w'   //上
#define KBHIT_DOWN 's' //下
#define KBHIT_LEFT 'a' //左
#define KBHIT_RIGHT 'd'//右
#define KBHIT_QUIT 'q' //退出

enum daoju_num{
	Wall,        //墙
	Floor,	     //地板
	Box_Goal,    //箱子目的地
	Box,         //箱子
	Man,	     //人
	Box_Goal_Box,//箱子和箱子目的地重叠
	ALL          //道具数量
};

struct _POS {    //坐标 
	int x;
	int y;
};

enum advance{//方向
	Up,   //上
	Down, //下
	Left, //左
	Right //右
};

struct _POS man;//人物坐标

int age = Floor; //标记  
int step = 0;
IMAGE daoju[ALL];//道具

//初始化游戏地图
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
*目的:   在指定位置打印指定图片
*输入:   保存坐标的结构体的地址, 图片
*返回值: 无
**********************************************************************/
void image(struct _POS *pos, enum daoju_num num) {
	map[pos->y][pos->x] = num;
	putimage(MAP_PY_WIDTH + pos->x * DAOJU_SIZE, MAP_PY_HEIGHT + pos->y * DAOJU_SIZE, &daoju[num]);
}


void step_num(int *p) {
	char str[10];
	sprintf(str, "步数: %d", *p);

	settextcolor(RGB(255, 255, 255));
	settextstyle(20, 0, "偕体");
	
	outtextxy(520, 20, str);
}

/*****************************************
*目的:   实现人物移动
*输入:   人物移动方向
*返回值: 无
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

	if(TRUE(hero_pos) && POS(hero_pos) == Floor) {         //人物前一格是地板
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Floor;
		step++;
	}else if(TRUE(hero_pos) && POS(hero_pos) == Box_Goal) {//人物前一格是箱子目的地
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Box_Goal;
		step++;
	 //人物前一格是箱子和箱子目的地的重叠而且箱子和箱子目的地的重叠的前一格不是墙也不是箱子
	}else if(TRUE(hero_pos) && POS(hero_pos) == Box_Goal_Box && POS(hero_pos_) != Wall && POS(hero_pos_) != Box && POS(hero_pos_) != Box_Goal_Box) {
		if(POS(hero_pos_) == Box_Goal) {
			image(&hero_pos_, Box_Goal_Box);
		}else {
			image(&hero_pos_, Box);
		}
		image(&hero_pos, Man);
		image(&man, (enum daoju_num)age);
		man = hero_pos;
		age = Box_Goal;
		step++;
	}else if(TRUE(hero_pos_) && POS(hero_pos) == Box && POS(hero_pos_) != Box) {//人物前一格是箱子而且箱子前一格不是箱子
		if(POS(hero_pos_) == Floor) {//箱子前一格是地板
			image(&hero_pos_, Box);
			image(&hero_pos, Man);
			image(&man, (enum daoju_num)age);
			man = hero_pos;
			age = Floor;
			step++;
		}else if(POS(hero_pos_) == Box_Goal) {//箱子前一格是箱子目的地
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
*目的:   游戏结束场景
*输入:   游戏结束场景资源
*返回值: true游戏结束 false游戏继续
***************************************/
bool end_scene(IMAGE *img) {
	for(int i=0; i<MAP_HEIGHT; i++) {
		for(int j=0; j<MAP_WIDTH; j++) {
			if(map[i][j] == Box_Goal || map[i][j] == Box) {
				return false;
			}
		}
	}
	settextcolor(RGB(255, 0, 0));
	settextstyle(100, 0, "偕体");

	cleardevice();

	putimage(0, 0, img);
	outtextxy(280, 334, "通关了!");
	return true;
}

int main(void) {

	IMAGE img;
	char daoju_name[ALL][DAOJU_NAME_LEN];								      //保存游戏资源的文件名
	
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);

	loadimage(&img, _T("blackground.bmp"), WINDOW_WIDTH, WINDOW_HEIGHT, true);//加载背景资源
	putimage(0, 0, &img);													  //显示背景

	for(int i=Wall; i<ALL; i++) {                                             //加载游戏场景资源
		sprintf(daoju_name[i], "daoju%d.bmp", i);
		loadimage(&daoju[i], _T(daoju_name[i]), DAOJU_SIZE, DAOJU_SIZE, true);
	}
	
	for(int i=0, num=0; i<MAP_HEIGHT; i++) {										  //显示游戏场景
		for(int j=0; j<MAP_WIDTH; j++) {
			if(map[i][j] == Man) {
				man.x = j;
				man.y = i;
			}
			
			putimage(MAP_PY_WIDTH +j*DAOJU_SIZE, MAP_PY_HEIGHT+i*DAOJU_SIZE, &daoju[map[i][j]]);
		}
	}
	
	bool quit = false;
	while(!quit) {
		step_num(&step);
		if(_kbhit()) {	       //是否按键
			char ch = _getch();//按下的键盘字符
			end_scene(&img);
			if(ch == KBHIT_UP) {         //上
				move(Up);
			}else if(ch == KBHIT_DOWN) { //下
				move(Down);
			}else if(ch == KBHIT_LEFT) { //左
				move(Left);
			}else if(ch == KBHIT_RIGHT) {//右
				move(Right);
			}else if(ch == KBHIT_QUIT) { //退出
				quit = true;
			}
			quit = end_scene(&img);
		}
		Sleep(100);
	}

	system("pause");
	closegraph();    //关闭图形界面
	return 0;
}