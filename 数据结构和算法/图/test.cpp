#include <iostream>
#include <Windows.h>
#include "AdjListGraph.h"

using namespace std;

int main(void) {
	AdjListGraph graph;
	int vertex = 0, path = 0;

	initGraph(graph);

	cout << "输入顶点数和路径数: ";
	cin >> vertex >> path;

	createGraph(graph, vertex, path);

	PrintGraph(graph);

	//depthPrint(graph);

	//breadthPrint(graph);

	char start, end;
	cout << "起点: ";
	cin >> start;
	cout << "终点: ";
	cin >> end;
	
	findway(graph, find(graph, start), find(graph, end));
	print_min_path(graph);
	
	system("pause");
	return 0;
}