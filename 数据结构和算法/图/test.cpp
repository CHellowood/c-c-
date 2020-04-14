#include <iostream>
#include <Windows.h>
#include "AdjListGraph.h"

using namespace std;

int main(void) {
	AdjListGraph graph;
	int vertex = 0, path = 0;

	initGraph(graph);

	cout << "���붥������·����: ";
	cin >> vertex >> path;

	createGraph(graph, vertex, path);

	PrintGraph(graph);

	//depthPrint(graph);

	//breadthPrint(graph);

	char start, end;
	cout << "���: ";
	cin >> start;
	cout << "�յ�: ";
	cin >> end;
	
	findway(graph, find(graph, start), find(graph, end));
	print_min_path(graph);
	
	system("pause");
	return 0;
}