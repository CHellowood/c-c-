//#pragma once
#ifndef _ASTARALGORITHM_H_
#define _ASTARALGORITHM_H_

#include <list>

typedef struct  _Point{//点(格子)
	int x;//当前点的x轴(列数)
	int y;//当前点的y轴(行数)
	int H;//从当前位置到目的地的距离
	int G;//从当前位置到起点的距离
	int F;//F = G + H
	_Point* prev;//前一个点(格子)
}Point;


//初始化地图, _map:地图首地址, _rows:地图总行数, _cols:地图总列数
void initMap(int* _map, int _rows, int _cols);

//生成一个点(格子)
Point* genPoint(int x, int y);

//获取路径
std::list<Point*> getPath(Point* startPoint, Point* endPoint);

//清理资源
void cleanRes();

#endif 