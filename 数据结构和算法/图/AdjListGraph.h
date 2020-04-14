//#pragma once

/*以邻接列表构建图*/

#ifndef _ADJLISTGRAPH_H_
#define _ADJLISTGRAPH_H_

#define ADJLIST_SIZE 10

typedef struct _PathNode {
	int subscript;//邻接顶点的下标
	int number;   //用来选择路径,可以是 距离, 时间, 钱数...
	_PathNode* naxt; //下一个路径
}Path, List; 

typedef struct  _VertexNode {
	char data;   //顶点数据
	List* first; //指向邻接的第一条路径
}VertexNode;

typedef struct _AdjListGraph {
	VertexNode* adjlist;
	int vertex;//顶点数
	int path;  //路径数
}AdjListGraph;

//初始化图
bool initGraph(AdjListGraph& graph);
//根据顶点数据查找顶点并返回顶点的下标
int find(AdjListGraph& graph, char ch);
//创建图
bool createGraph(AdjListGraph& graph, int vertex, int path);
//遍历
void PrintGraph(AdjListGraph& graph);
//深度遍历
void depthPrint(AdjListGraph& graph);
//广度遍历
void breadthPrint(AdjListGraph& graph);

/***findway和print_min_path是一个整体***/

//寻路
void findway(AdjListGraph& graph, int start, int end, int number = 0);
//打印最短路径
void print_min_path(AdjListGraph& graph);
/***************************************/

#endif 