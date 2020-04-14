#include "AStarAlgorithm.h"
#include <vector>

#define ads(a) ((a)*(a)) 

static int cost = 1;//点(格子)与点(格子)之间的距离

static int* map;//地图首地址
static int rows;//地图总行数
static int cols;//地图总列数

static std::list<Point*> openlist; //开放列表(检测列表)
static std::list<Point*> closelist;//关闭列表(确认列表)

//寻找路经
static Point* findPath(Point* startPoint, Point* endPoint);

//获取F最小的点
static Point* getMinFpoint();

//获取与当前点相邻可达的点
static std::vector<Point*> getSurroundPoint(const Point* point);

//下一个点是否可达
static bool isCanreach(const Point* point, const Point* target);

//在列表里是否存在该点
static Point* isInList(std::list<Point*>& list, const Point* point);

//计算H值
static int calcH(Point* point, Point* endPoint) {
	return (int)(((unsigned)(point->x - endPoint->x)) + ((unsigned)(point->y - endPoint->y)));
}

//计算G值
static int calcG(Point* prev) {
	return  prev->G + cost;
}

static int calcF(Point* point) {
	return point->H + point->G;
}

//初始化地图, _map:地图首地址, _rows:地图总行数, _cols:地图总列数
void initMap(int* _map, int _rows, int _cols) {
	map  = _map;
	rows = _rows;
	cols = _cols;
}

//生成一个点(格子)
Point* genPoint(int x, int y) {
	Point* temp = new Point;

	memset(temp, 0, sizeof(Point));
	temp->x = x;
	temp->y = y;

	return temp;
}

//获取路径
std::list<Point*> getPath(Point* startPoint, Point* endPoint) {
	Point* result = findPath(startPoint, endPoint);

	std::list<Point*> path;
	while (result) {
		path.push_front(result);
		result = result->prev;
	}
	return path;
}

//寻找路经
static Point* findPath(Point* startPoint, Point* endPoint) {
	openlist.push_back(genPoint(startPoint->x, startPoint->y));

	while (!openlist.empty()) {
		//从开放列表中获取F最小的点
		Point* minFpoint = getMinFpoint();

		//将获取到的点移出开放列表放到关闭列表
		openlist.remove(minFpoint);
		closelist.push_back(minFpoint);

		//获取与当前点相邻的点
		std::vector<Point*> surroundPoint = getSurroundPoint(minFpoint);

		std::vector<Point*>::const_iterator iter;
		for (iter = surroundPoint.begin(); iter != surroundPoint.end();) {
			Point* exist = isInList(openlist, *iter);
			if (!exist) {
				(*iter)->H = calcH((*iter), endPoint);
				(*iter)->G = calcG(minFpoint);
				(*iter)->F = calcF((*iter));

				(*iter)->prev = minFpoint;
				openlist.push_back((*iter));
				iter++;
			}
			else {
				int G = calcG(minFpoint);
				if (G < exist->G) {
					exist->prev = minFpoint;
					exist->G = G;
					exist->F = calcF(exist);
				}
				delete *iter;
				iter = surroundPoint.erase(iter);
			}
		}
		surroundPoint.clear();

		Point* result = isInList(openlist, endPoint);
		if (result) {
			return result;
		}
	}
	return NULL;
}

//获取F最小的点
static Point* getMinFpoint() {
	if (!openlist.empty()) {
		Point* minFpoint = openlist.front();

		std::list<Point*>::const_iterator iter;
		for (iter = openlist.begin(); iter != openlist.end(); iter++) {
			if ((*iter)->F < minFpoint->F) {
				minFpoint = *iter;
			}
		}
		return minFpoint;
	}
	return NULL;
}

//获取与当前点相邻可达的点
static std::vector<Point*> getSurroundPoint(const Point* point) {
	std::vector<Point*> surroundPoint;

	for (int x = point->x - 1; x <= point->x + 1; x++) {
		for (int y = point->y - 1; y <= point->y + 1; y++) {
			Point* temp = genPoint(x, y);
			if (isCanreach(point, temp)) {
				surroundPoint.push_back(temp);
			}
			else {
				delete temp;
			}
		}
	}
	return surroundPoint;
}

//下一个点是否可达
static bool isCanreach(const Point * point, const Point * target) {
	if ((target->x < 0 || target->x > cols - 1)
		|| (target->y < 0 || target->y > rows - 1)
		|| (point->x == target->x && point->y == target->y)
		|| isInList(closelist, target)
		|| map[target->y * cols + target->x] == 0
		|| map[target->y * cols + target->x] == 3) {
		return false;
	}
	if (ads((point->x - target->x) + (point->y - target->y)) == 1) {
		return true;
	}
	return false;
}

//在列表里是否存在该点
static Point* isInList(std::list<Point*> &list, const Point* point) {
	std::list<Point*>::const_iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++) {
		if (point->x == (*iter)->x && point->y == (*iter)->y)
			return *iter;
	}
	return NULL;
}


//清理资源
void cleanRes() {
	std::list<Point*>::const_iterator iter;

	for (iter = openlist.begin(); iter != openlist.end();) {
		delete* iter;
		iter = openlist.erase(iter);
	}

	for (iter = closelist.begin(); iter != closelist.end();) {
		delete* iter;
		iter = closelist.erase(iter);
	}
}