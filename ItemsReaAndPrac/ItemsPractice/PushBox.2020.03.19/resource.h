#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

#include <graphics.h>
#include <iostream>
#include <fstream>

#define WINDOW_WIDTH 960  //窗口宽度
#define WINDOW_HEIGHT 760 //窗口高度

#define MAP_START_X 0     //地图起始x轴坐标(单位:像素)
#define MAP_START_Y 0     //地图起始y轴坐标(单位:像素)

#define TERRAIN_SIZE 40	  //每格地形大小
#define FILE_NAME_LEN 128  //文件名字长度

#define BG_IMAGE_NUM 1      //背景图片数量
#define ROLE_IMAGE_NUM 1    //人物图片数量
#define BOX_IMAGE_NUM 2     //箱子图片数量
#define TERRAIN_IMAGE_NUM 3 //地形图片数量

#define BOX_NUM 4    //箱子数量
#define KEYPAD_NUM 1 //按键数量

#define MAP_DATA_FILE "mapData.txt"           //地图数据文件
#define INPUT_CONTROL_FILE "inputControl.txt" //输入控制文件

//坐标
typedef struct {
	int x;
	int y;
}Pos;

enum class BG {
	BG1   //背景1
};

enum class ROLE {
	Tom   //人物1，汤姆
};

enum class BOX {
	Box,     //箱子
	Goal_Box //到达目的地的箱子
};

enum class Terrain {
	Wall,        //墙
	Floor,	     //地板
	Box_Goal     //箱子目的地
};

enum class Input {//输入
	UP,   //上
	DOWN, //下
	LEFT, //左
	RIGHT,//右
	QUIT  //退出
};

static IMAGE bgs[BG_IMAGE_NUM];           //背景图片
static IMAGE roles[ROLE_IMAGE_NUM];       //人物图片
static IMAGE boxs[BOX_IMAGE_NUM];         //箱子图片
static IMAGE terrains[TERRAIN_IMAGE_NUM]; //地形图片

static int* mapData;                 //地图数据
static int mapWidth;                 //地图宽度
static int mapLength;                //地图长度
static Pos rolePos;                  //人物坐标
static Pos boxsPos[BOX_NUM];         //所有箱子的坐标
static Pos keypadsPos[KEYPAD_NUM*2]; //按键坐标

static int moveDis = 1;//人物移动一步的距离

static char up;    //上
static char down;  //下
static char left;  //左
static char right; //右
static char quit;  //退出


void loadResource();//加载全部资源
void loadImage();   //加载图片资源
void loadMapData(); //加载地图数据
void loadInputControl();   //加载输入控制文件

inline void loadResource() {
	loadImage();
	loadMapData();
	loadInputControl();
}

inline void loadImage() {
	char fileName[FILE_NAME_LEN];

	//加载背景图片
	for (int i = 0; i < BG_IMAGE_NUM; i++) {
		sprintf_s(fileName, FILE_NAME_LEN, "bg%d.bmp", i);
		loadimage(&bgs[i], fileName, WINDOW_WIDTH, WINDOW_HEIGHT, true);//加载背景资源											  //显示背景
	}

	//加载人物图片
	for (int i = 0; i < ROLE_IMAGE_NUM; i++) {                                             //加载游戏场景资源
		sprintf_s(fileName, FILE_NAME_LEN, "role%d.bmp", i);
		loadimage(&roles[i], fileName, TERRAIN_SIZE, TERRAIN_SIZE, true);
	}

	//加载箱子图片
	for (int i = 0; i < BOX_IMAGE_NUM; i++) {                                             //加载游戏场景资源
		sprintf_s(fileName, FILE_NAME_LEN, "box%d.bmp", i);
		loadimage(&boxs[i], fileName, TERRAIN_SIZE, TERRAIN_SIZE, true);
	}

	//加载地形图片
	for (int i = (int)Terrain::Wall; i < TERRAIN_IMAGE_NUM; i++) {                                             //加载游戏场景资源
		sprintf_s(fileName, FILE_NAME_LEN, "terrain%d.bmp", i);
		loadimage(&terrains[i], fileName, TERRAIN_SIZE, TERRAIN_SIZE, true);
	}
}

inline void loadMapData() {
	std::ifstream input;

	input.open(MAP_DATA_FILE, std::ios::in);
	if (!input.is_open()) exit(-1);

	//读取地图宽度和长度
	input >> mapLength >> mapWidth;

	//读取地图数据
	mapData = new int[mapWidth * mapLength];
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapLength; j++) {
			input >> mapData[i * mapLength + j];
		}
	}

	//读取人物坐标
	input >> rolePos.x >> rolePos.y;

	//读取所有箱子的坐标
	for (int i = 0; i < BOX_NUM; i++) {
		input >> boxsPos[i].x >> boxsPos[i].y;
	}

	//读取当前地图所有按键的坐标
	for (int i = 0; i < KEYPAD_NUM*2; i++) {
		input >> keypadsPos[i].x >> keypadsPos[i].y;
	}

	input.close();
}

inline void loadInputControl() {
	std::ifstream input;

	input.open(INPUT_CONTROL_FILE, std::ios::in);
	if (!input.is_open()) exit(-1);

	input >> up >> down >> left >> right >> quit;

	input.close();
}

#endif 