#include "AdjListGraph.h"
#include <iostream>

using namespace std;

//��ʼ��ͼ
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

//���ݶ������ݲ��Ҷ��㲢���ض�����±�
int find(AdjListGraph& graph, char ch) {
	if (!graph.adjlist) return -1;

	for (int i = 0; i < graph.vertex; i++) {
		if (graph.adjlist[i].data == ch) return i;
	}
	return -1;
}

//����ͼ
bool createGraph(AdjListGraph& graph, int vertex, int path) {
	//�����������·����С�ڵ���0,��ô����������ͼ��û���κ�����
	if (vertex <= 0 || vertex > ADJLIST_SIZE || path <= 0) return false;


	graph.vertex = vertex;
	graph.path = path;

	//��ʼ������
	cout << "����ȫ������: ";
	for (int i = 0; i < vertex; i++) {
		cin >> graph.adjlist[i].data;
		graph.adjlist[i].first = NULL;
	}
	cout << endl;

	//��ʼ��·��
	char vertex1, vertex2;
	int sub1, sub2, number;
	cout << "����ȫ��·��: " << endl;
	for (int i = 0; i < path; i++) {
		cin >> vertex1 >> vertex2 >> number;
		
		sub1 = find(graph, vertex1);
		sub2 = find(graph, vertex2);

		if (sub1 != -1 && sub2 != -1 && number >= 0) {
			Path* path = new Path;
			if (path) {
				path->subscript = sub2;
				path->number = number;//����ѡ��·��,������ ����, ʱ��, Ǯ��...
				path->naxt = graph.adjlist[sub1].first;
				graph.adjlist[sub1].first = path;
			}
		}
	}
	return true;
}

//����
void PrintGraph(AdjListGraph& graph) {
	if (!graph.adjlist) return;

	for (int i = 0; i < graph.vertex; i++) {
		cout << "����: " << graph.adjlist[i].data << " ·��: ";

		Path* p = graph.adjlist[i].first;
		while (p) {
			cout << graph.adjlist[p->subscript].data << " ";
			p = p->naxt;
		}
		cout << endl;
	}
}

/*************************��ȱ���**************************/
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

//��ȱ���
void depthPrint(AdjListGraph& graph) {
	if (!graph.adjlist) return;

	bool tf[ADJLIST_SIZE] = { false };
	for (int i = 0; i < graph.vertex; i++) {
		depth(graph, i, tf);
	}
	cout << endl;
}
/***********************************************************/

/*************************��ȱ���**************************/
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

//��ȱ���
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
//Ѱ·
void findway(AdjListGraph& graph, int start, int end, int number) {
	if (start == end) {
		for (int i = 0; i < step; i++) {
			cout << graph.adjlist[_path[i]].data << " ";
		}
		cout << number << "(��λ)" << endl;

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

//��ӡ���·��
void print_min_path(AdjListGraph& graph) {
	if (min_number < 0X7FFFFFFF) {
		cout << "���·��: ";
		for (int i = 0; i < ADJLIST_SIZE && min_path[i] > 0; i++) {
			cout << graph.adjlist[min_path[i]].data << " ";
		}
		cout << min_number << "(��λ)" << endl;
	}
	else {
		cout << "������·��!" << endl;
	}
}