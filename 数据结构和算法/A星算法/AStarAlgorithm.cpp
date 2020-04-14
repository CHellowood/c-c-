#include "AStarAlgorithm.h"
#include <vector>

#define ads(a) ((a)*(a)) 

static int cost = 1;//��(����)���(����)֮��ľ���

static int* map;//��ͼ�׵�ַ
static int rows;//��ͼ������
static int cols;//��ͼ������

static std::list<Point*> openlist; //�����б�(����б�)
static std::list<Point*> closelist;//�ر��б�(ȷ���б�)

//Ѱ��·��
static Point* findPath(Point* startPoint, Point* endPoint);

//��ȡF��С�ĵ�
static Point* getMinFpoint();

//��ȡ�뵱ǰ�����ڿɴ�ĵ�
static std::vector<Point*> getSurroundPoint(const Point* point);

//��һ�����Ƿ�ɴ�
static bool isCanreach(const Point* point, const Point* target);

//���б����Ƿ���ڸõ�
static Point* isInList(std::list<Point*>& list, const Point* point);

//����Hֵ
static int calcH(Point* point, Point* endPoint) {
	return (int)(((unsigned)(point->x - endPoint->x)) + ((unsigned)(point->y - endPoint->y)));
}

//����Gֵ
static int calcG(Point* prev) {
	return  prev->G + cost;
}

static int calcF(Point* point) {
	return point->H + point->G;
}

//��ʼ����ͼ, _map:��ͼ�׵�ַ, _rows:��ͼ������, _cols:��ͼ������
void initMap(int* _map, int _rows, int _cols) {
	map  = _map;
	rows = _rows;
	cols = _cols;
}

//����һ����(����)
Point* genPoint(int x, int y) {
	Point* temp = new Point;

	memset(temp, 0, sizeof(Point));
	temp->x = x;
	temp->y = y;

	return temp;
}

//��ȡ·��
std::list<Point*> getPath(Point* startPoint, Point* endPoint) {
	Point* result = findPath(startPoint, endPoint);

	std::list<Point*> path;
	while (result) {
		path.push_front(result);
		result = result->prev;
	}
	return path;
}

//Ѱ��·��
static Point* findPath(Point* startPoint, Point* endPoint) {
	openlist.push_back(genPoint(startPoint->x, startPoint->y));

	while (!openlist.empty()) {
		//�ӿ����б��л�ȡF��С�ĵ�
		Point* minFpoint = getMinFpoint();

		//����ȡ���ĵ��Ƴ������б�ŵ��ر��б�
		openlist.remove(minFpoint);
		closelist.push_back(minFpoint);

		//��ȡ�뵱ǰ�����ڵĵ�
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

//��ȡF��С�ĵ�
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

//��ȡ�뵱ǰ�����ڿɴ�ĵ�
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

//��һ�����Ƿ�ɴ�
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

//���б����Ƿ���ڸõ�
static Point* isInList(std::list<Point*> &list, const Point* point) {
	std::list<Point*>::const_iterator iter;
	for (iter = list.begin(); iter != list.end(); iter++) {
		if (point->x == (*iter)->x && point->y == (*iter)->y)
			return *iter;
	}
	return NULL;
}


//������Դ
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