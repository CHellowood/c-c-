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

struct _POS man = {0, 0};//人物坐标

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

//创建新地图
int create_map[MAP_HEIGHT][MAP_WIDTH] = {0};

/*********************************************************************
*目的:   在指定位置打印指定图片
*输入:   保存坐标的结构体的地址, 图片
*返回值: 无
**********************************************************************/
void image(struct _POS *pos, enum daoju_num num) {
	map[pos->y][pos->x] = num;
	putimage(MAP_PY_WIDTH + pos->x * DAOJU_SIZE, MAP_PY_HEIGHT + pos->y * DAOJU_SIZE, &daoju[num]);
}

//步数
void step_num(int *p) {
	char str[10];
	sprintf(str, "步数: %d", *p);

	settextcolor(RGB(255, 255, 255));
	settextstyle(20, 0, _T("偕体"));
	
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
	man.x = 0;
	man.y = 0;

	settextcolor(RGB(255, 0, 0));
	settextstyle(100, 0, _T("偕体"));

	cleardevice();

	putimage(0, 0, img);
	outtextxy(280, 334, _T("通关了!"));

	system("pause");
	return true;
}

/*******************************
*加载游戏资源
*输入:    img用来保存游戏背景图片
*返回值:  无
********************************/
void loadres(IMAGE& img) {
	char daoju_name[ALL][DAOJU_NAME_LEN];//保存游戏资源的文件名
	
	loadimage(&img, "blackground.bmp", WINDOW_WIDTH, WINDOW_HEIGHT, true);//加载背景资源
	putimage(0, 0, &img);													  //显示背景

	for(int i=Wall; i<ALL; i++) {                                             //加载游戏场景资源
		sprintf(daoju_name[i], "daoju%d.bmp", i);
		loadimage(&daoju[i], daoju_name[i], DAOJU_SIZE, DAOJU_SIZE, true);
	}
	//outtextxy(0, 0, daoju_name[1]); system("pause"); //查看字符是否正确
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
*游戏控制键:
*输入:    img游戏结束背景
*返回值:  无
************************************/
void input(IMAGE& img) {
	while(!end_scene(&img)) {
		step_num(&step);
		if(_kbhit()) {	       //是否按键
			char ch = _getch();//按下的键盘字符
			if(ch == KBHIT_UP) {         //上
				move(Up);
			}else if(ch == KBHIT_DOWN) { //下
				move(Down);
			}else if(ch == KBHIT_LEFT) { //左
				move(Left);
			}else if(ch == KBHIT_RIGHT) {//右
				move(Right);
			}else if(ch == KBHIT_QUIT) { //退出
				break;
			}
		}
		Sleep(100);
	}
}

//显示游戏场景
void dispiayScene(IMAGE& img) {
	cleardevice();
	putimage(0, 0, &img);
	for(int i=0; i<MAP_HEIGHT; i++) {										  //显示游戏场景
		for(int j=0; j<MAP_WIDTH; j++) {
			if(map[i][j] == Man) {//人物的位置
				man.x = j;  
				man.y = i;
			}
			
			putimage(MAP_PY_WIDTH +j*DAOJU_SIZE, MAP_PY_HEIGHT+i*DAOJU_SIZE, &daoju[map[i][j]]);
		}
	}
	input(img);//游戏控制键
}



//创建地图
void createMap(IMAGE& img) {
	_POS temp_man = { 0, 0 };

	cleardevice();
	putimage(0, 0, &img);
	for(int i=0; i<MAP_HEIGHT; i++) {										  //显示游戏场景
		for(int j=0; j<MAP_WIDTH; j++) {
			putimage(MAP_PY_WIDTH +j*DAOJU_SIZE, MAP_PY_HEIGHT+i*DAOJU_SIZE, &daoju[create_map[i][j]]);
		}
	}

	setbkmode(TRANSPARENT);         //把文字输出时的背景改为透明的
	settextcolor(RGB(225, 0, 0));
	settextstyle(25, 0, _T("偕体"));

	outtextxy(640, 30, "w: 上");
	outtextxy(640, 60, "s: 下");
	outtextxy(640, 90, "a: 左");
	outtextxy(640, 120, "d: 右");
	outtextxy(640, 150, "t: 切换");
	outtextxy(640, 180, "k: 保存");
	outtextxy(640, 210, "q: 返回");

	while(true) {
		
		if(!_kbhit()) {	       //是否按键
			putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
		}
		else{
			switch(_getch()) {//按下的键盘字符
			case KBHIT_UP:          //上
				if (temp_man.y > 0) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.y--;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case KBHIT_DOWN:  //下
				if (temp_man.y < MAP_HEIGHT-1) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.y++;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case KBHIT_LEFT: //左
				if (temp_man.x > 0) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.x--;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case KBHIT_RIGHT://右
				if (temp_man.x < MAP_WIDTH-1) {
					putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
					temp_man.x++;
					//putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[Man]);
				}
				break;
			case 't': //切换
				create_map[temp_man.y][temp_man.x] = (create_map[temp_man.y][temp_man.x] + 1)%ALL;
				putimage(MAP_PY_WIDTH + temp_man.x * DAOJU_SIZE, MAP_PY_HEIGHT + temp_man.y * DAOJU_SIZE, &daoju[create_map[temp_man.y][temp_man.x]]);
				Sleep(100);
				break;
			case 'k':
				for(int i=0; i<MAP_HEIGHT; i++) {										  //显示游戏场景
					for(int j=0; j<MAP_WIDTH; j++) {
						map[i][j] = create_map[i][j];
					}
				}
			case KBHIT_QUIT: //退出
				return;
			}
		}
		Sleep(100);
	}
}

//游戏开始界面
bool startInterface(IMAGE& img) {
	cleardevice();

	putimage(0, 0, &img);
	
	settextcolor(RGB(255, 0, 0));
	settextstyle(25, 0, _T("偕体"));

	outtextxy((WINDOW_WIDTH)/5*2, WINDOW_HEIGHT/2, _T("开始游戏[s]"));
	outtextxy((WINDOW_WIDTH)/5*2, WINDOW_HEIGHT/2+30, _T("创建地图[c]"));
	outtextxy((WINDOW_WIDTH)/5*2, WINDOW_HEIGHT/2+30+30, _T("退出游戏[e]"));

	char ch = ' ';
	while (ch != 's' && ch != 'c' && ch != 'e') {
		ch = _getch();
	}

	if (ch == 's') {
		dispiayScene(img);//显示游戏场景
	}
	else if (ch == 'c') {
		createMap(img);	
	}
	else if (ch == 'e') {
		return false;
	}
	return true;
}

int main(void) {
	IMAGE img;
	
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);//初始化绘图窗口

	loadres(img);//加载游戏资源

	while (startInterface(img)) {
		//游戏开始界面
	}

	system("pause");
	closegraph();    //关闭图形界面
	return 0;
}