#include "AdjListGraph.h"
#include <iostream>

using namespace std;

//初始化图
bool initGraph(AdjListGraph& graph) {
	graph.adjlist = new VertexNode[ADJLIST_SIZE];
	if (!graph.adjlist) {
		printf("createGraph: graph.adjlist new error!");
		return false;
	}
	graph.vertex = 0;
	graph.path = 0;

	return true;
}

//根据顶点数据查找顶点并返回顶点的下标
int find(AdjListGraph& graph, char ch) {
	if (!graph.adjlist) return -1;

	for (int i = 0; i < graph.vertex; i++) {
		if (graph.adjlist[i].data == ch) return i;
	}
	return -1;
}

//创建图
bool createGraph(AdjListGraph& graph, int vertex, int path) {
	//如果顶点数或路径数小于等于0,那么创建出来的图将没有任何意义
	if (vertex <= 0 || vertex > ADJLIST_SIZE || path <= 0) return false;


	graph.vertex = vertex;
	graph.path = path;

	//初始化顶点
	cout << "输入全部顶点: ";
	for (int i = 0; i < vertex; i++) {
		cin >> graph.adjlist[i].data;
		graph.adjlist[i].first = NULL;
	}
	cout << endl;

	//初始化路径
	char vertex1, vertex2;
	int sub1, sub2, number;
	cout << "输入全部路径: " << endl;
	for (int i = 0; i < path; i++) {
		cin >> vertex1 >> vertex2 >> number;
		
		sub1 = find(graph, vertex1);
		sub2 = find(graph, vertex2);

		if (sub1 != -1 && sub2 != -1 && number >= 0) {
			Path* path = new Path;
			if (path) {
				path->subscript = sub2;
				path->number = number;//用来选择路径,可以是 距离, 时间, 钱数...
				path->naxt = graph.adjlist[sub1].first;
				graph.adjlist[sub1].first = path;
			}
		}
	}
	return true;
}

//遍历
void PrintGraph(AdjListGraph& graph) {
	if (!graph.adjlist) return;

	for (int i = 0; i < graph.vertex; i++) {
		cout << "顶点: " << graph.adjlist[i].data << " 路径: ";

		Path* p = graph.adjlist[i].first;
		while (p) {
			cout << graph.adjlist[p->subscript].data << " ";
			p = p->naxt;
		}
		cout << endl;
	}
}

/*************************深度遍历**************************/
void depth(AdjListGraph& graph, int i, bool* tf) {
	if (tf[i]) return;
	
	cout << " " << graph.adjlist[i].data;
	tf[i] = true;

	Path* p = graph.adjlist[i].first;
	while (p) {
		depth(graph, p->subscript, tf);
		p = p->naxt;
	}
}

//深度遍历
void depthPrint(AdjListGraph& graph) {
	if (!graph.adjlist) return;

	bool tf[ADJLIST_SIZE] = { false };
	for (int i = 0; i < graph.vertex; i++) {
		depth(graph, i, tf);
	}
	cout << endl;
}
/***********************************************************/

/*************************广度遍历**************************/
void breadth(AdjListGraph& graph, int i, bool* tf) {
	if (!tf[i]) {
		cout << " " << graph.adjlist[i].data;
		tf[i] = true;
	}

	Path* p = graph.adjlist[i].first;
	while (p) {
		if (!tf[p->subscript]) {
			cout << " " << graph.adjlist[p->subscript].data;
			tf[p->subscript] = true;
		}
		p = p->naxt;
	}

	p = graph.adjlist[i].first;
	while (p) {
		depth(graph, p->subscript, tf);
		p = p->naxt;
	}
}

//广度遍历
void breadthPrint(AdjListGraph& graph) {
	if (!graph.adjlist) return;

	bool tf[ADJLIST_SIZE] = { false };
	for (int i = 0; i < graph.vertex; i++) {
		breadth(graph, i, tf);
	}
	cout << endl;
}
/***********************************************************/

bool _tf[ADJLIST_SIZE];
int step = 0;
int _path[ADJLIST_SIZE];
int min_path[ADJLIST_SIZE];
int min_number = 0X7FFFFFFF;
//寻路
void findway(AdjListGraph& graph, int start, int end, int number) {
	if (start == end) {
		for (int i = 0; i < step; i++) {
			cout << graph.adjlist[_path[i]].data << " ";
		}
		cout << number << "(单位)" << endl;

		if (min_number > number) {
			min_number = number;
			memcpy(min_path, _path, step*sizeof(int));
		}
		return;
	}
	
	Path* p = graph.adjlist[start].first;
	while (p) {
		if (!_tf[start]) {
			_tf[start] = true;
			_path[step++] = p->subscript;
			findway(graph, p->subscript, end, number + p->number);
			_tf[start] = false;
			_path[--step] = 0;
		}
		p = p->naxt;
	}
}

//打印最短路径
void print_min_path(AdjListGraph& graph) {
	if (min_number < 0X7FFFFFFF) {
		cout << "最短路径: ";
		for (int i = 0; i < ADJLIST_SIZE && min_path[i] > 0; i++) {
			cout << graph.adjlist[min_path[i]].data << " ";
		}
		cout << min_number << "(单位)" << endl;
	}
	else {
		cout << "不存在路径!" << endl;
	}
}