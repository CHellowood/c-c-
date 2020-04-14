#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

#include <graphics.h>
#include <iostream>
#include <fstream>

#define WINDOW_WIDTH 960  //���ڿ��
#define WINDOW_HEIGHT 760 //���ڸ߶�

#define MAP_START_X 0     //��ͼ��ʼx������(��λ:����)
#define MAP_START_Y 0     //��ͼ��ʼy������(��λ:����)

#define TERRAIN_SIZE 40	  //ÿ����δ�С
#define FILE_NAME_LEN 128  //�ļ����ֳ���

#define BG_IMAGE_NUM 1      //����ͼƬ����
#define ROLE_IMAGE_NUM 1    //����ͼƬ����
#define BOX_IMAGE_NUM 2     //����ͼƬ����
#define TERRAIN_IMAGE_NUM 3 //����ͼƬ����

#define BOX_NUM 4    //��������
#define KEYPAD_NUM 1 //��������

#define MAP_DATA_FILE "mapData.txt"           //��ͼ�����ļ�
#define INPUT_CONTROL_FILE "inputControl.txt" //��������ļ�

//����
typedef struct {
	int x;
	int y;
}Pos;

enum class BG {
	BG1   //����1
};

enum class ROLE {
	Tom   //����1����ķ
};

enum class BOX {
	Box,     //����
	Goal_Box //����Ŀ�ĵص�����
};

enum class Terrain {
	Wall,        //ǽ
	Floor,	     //�ذ�
	Box_Goal     //����Ŀ�ĵ�
};

enum class Input {//����
	UP,   //��
	DOWN, //��
	LEFT, //��
	RIGHT,//��
	QUIT  //�˳�
};

static IMAGE bgs[BG_IMAGE_NUM];           //����ͼƬ
static IMAGE roles[ROLE_IMAGE_NUM];       //����ͼƬ
static IMAGE boxs[BOX_IMAGE_NUM];         //����ͼƬ
static IMAGE terrains[TERRAIN_IMAGE_NUM]; //����ͼƬ

static int* mapData;                 //��ͼ����
static int mapWidth;                 //��ͼ���
static int mapLength;                //��ͼ����
static Pos rolePos;                  //��������
static Pos boxsPos[BOX_NUM];         //�������ӵ�����
static Pos keypadsPos[KEYPAD_NUM*2]; //��������

static int moveDis = 1;//�����ƶ�һ���ľ���

static char up;    //��
static char down;  //��
static char left;  //��
static char right; //��
static char quit;  //�˳�


void loadResource();//����ȫ����Դ
void loadImage();   //����ͼƬ��Դ
void loadMapData(); //���ص�ͼ����
void loadInputControl();   //������������ļ�

inline void loadResource() {
	loadImage();
	loadMapData();
	loadInputControl();
}

inline void loadImage() {
	char fileName[FILE_NAME_LEN];

	//���ر���ͼƬ
	for (int i = 0; i < BG_IMAGE_NUM; i++) {
		sprintf_s(fileName, FILE_NAME_LEN, "bg%d.bmp", i);
		loadimage(&bgs[i], fileName, WINDOW_WIDTH, WINDOW_HEIGHT, true);//���ر�����Դ											  //��ʾ����
	}

	//��������ͼƬ
	for (int i = 0; i < ROLE_IMAGE_NUM; i++) {                                             //������Ϸ������Դ
		sprintf_s(fileName, FILE_NAME_LEN, "role%d.bmp", i);
		loadimage(&roles[i], fileName, TERRAIN_SIZE, TERRAIN_SIZE, true);
	}

	//��������ͼƬ
	for (int i = 0; i < BOX_IMAGE_NUM; i++) {                                             //������Ϸ������Դ
		sprintf_s(fileName, FILE_NAME_LEN, "box%d.bmp", i);
		loadimage(&boxs[i], fileName, TERRAIN_SIZE, TERRAIN_SIZE, true);
	}

	//���ص���ͼƬ
	for (int i = (int)Terrain::Wall; i < TERRAIN_IMAGE_NUM; i++) {                                             //������Ϸ������Դ
		sprintf_s(fileName, FILE_NAME_LEN, "terrain%d.bmp", i);
		loadimage(&terrains[i], fileName, TERRAIN_SIZE, TERRAIN_SIZE, true);
	}
}

inline void loadMapData() {
	std::ifstream input;

	input.open(MAP_DATA_FILE, std::ios::in);
	if (!input.is_open()) exit(-1);

	//��ȡ��ͼ��Ⱥͳ���
	input >> mapLength >> mapWidth;

	//��ȡ��ͼ����
	mapData = new int[mapWidth * mapLength];
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapLength; j++) {
			input >> mapData[i * mapLength + j];
		}
	}

	//��ȡ��������
	input >> rolePos.x >> rolePos.y;

	//��ȡ�������ӵ�����
	for (int i = 0; i < BOX_NUM; i++) {
		input >> boxsPos[i].x >> boxsPos[i].y;
	}

	//��ȡ��ǰ��ͼ���а���������
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