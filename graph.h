#pragma once
#include"iostream"

using std::cin;
using std::cout;
using std::cout;
using std::endl;
using std::cerr;
struct Edge                                   //�߽ڵ�
{
	int dest;
	int cost;                                //Ȩֵ

	Edge * link;
	Edge() {};
	Edge(int num, int weight) :dest(num), cost(weight) {};
	bool operator != (Edge & R) {
		return (dest != R.dest);
	};
};


struct Vertex {                                 //����ڵ�
	char data;
	Edge* adj = NULL;
};


class Graph {                                   //ͼ
private:
	Vertex* nodeTable;
	int numVertices;
	int numEdges;
	int getVertexPos(char vertex) {
		for (int i = 0; i < numVertices; i++)
			if (nodeTable[i].data == vertex) return i;
		return -1;
	}
public:
	Graph();
	int getWeight(int, int );
	void completeEdge();
	bool insertEdge(char, char, int);
	int getNumberByData(char);
	int numberOfVertices();
	int numberOfEdges();
	int  getFirstNeighbor(int);
	int  getNextNeighbor(int, int);
	Vertex * getNodeTable();
};