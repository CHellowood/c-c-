//#pragma once
#ifndef _ASTARALGORITHM_H_
#define _ASTARALGORITHM_H_

#include <list>

typedef struct  _Point{//��(����)
	int x;//��ǰ���x��(����)
	int y;//��ǰ���y��(����)
	int H;//�ӵ�ǰλ�õ�Ŀ�ĵصľ���
	int G;//�ӵ�ǰλ�õ����ľ���
	int F;//F = G + H
	_Point* prev;//ǰһ����(����)
}Point;


//��ʼ����ͼ, _map:��ͼ�׵�ַ, _rows:��ͼ������, _cols:��ͼ������
void initMap(int* _map, int _rows, int _cols);

//����һ����(����)
Point* genPoint(int x, int y);

//��ȡ·��
std::list<Point*> getPath(Point* startPoint, Point* endPoint);

//������Դ
void cleanRes();

#endif 