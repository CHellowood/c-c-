//#pragma once

/*���ڽ��б���ͼ*/

#ifndef _ADJLISTGRAPH_H_
#define _ADJLISTGRAPH_H_

#define ADJLIST_SIZE 10

typedef struct _PathNode {
	int subscript;//�ڽӶ�����±�
	int number;   //����ѡ��·��,������ ����, ʱ��, Ǯ��...
	_PathNode* naxt; //��һ��·��
}Path, List; 

typedef struct  _VertexNode {
	char data;   //��������
	List* first; //ָ���ڽӵĵ�һ��·��
}VertexNode;

typedef struct _AdjListGraph {
	VertexNode* adjlist;
	int vertex;//������
	int path;  //·����
}AdjListGraph;

//��ʼ��ͼ
bool initGraph(AdjListGraph& graph);
//���ݶ������ݲ��Ҷ��㲢���ض�����±�
int find(AdjListGraph& graph, char ch);
//����ͼ
bool createGraph(AdjListGraph& graph, int vertex, int path);
//����
void PrintGraph(AdjListGraph& graph);
//��ȱ���
void depthPrint(AdjListGraph& graph);
//��ȱ���
void breadthPrint(AdjListGraph& graph);

/***findway��print_min_path��һ������***/

//Ѱ·
void findway(AdjListGraph& graph, int start, int end, int number = 0);
//��ӡ���·��
void print_min_path(AdjListGraph& graph);
/***************************************/

#endif 