#include "graph.h"

int Graph::getFirstNeighbor(int v) {
	if (v != -1) {
		Edge *p = nodeTable[v].adj;
		if (p != NULL) return p->dest;
	}
	return -1;
}

int Graph::getNextNeighbor(int v, int w) {
	if (v != -1) {
		Edge *p = nodeTable[v].adj;
		while (p != NULL&&p->dest != w)
			p = p->link;
		if (p != NULL&&p->link != NULL)
			return p->link->dest;
	}
	return -1;
}

int Graph::numberOfVertices() {
	return numVertices;
}


int Graph::numberOfEdges() {
	return numEdges;
}


Graph::Graph() {
	numEdges = 0;

	cout << "请输入顶点个数： ";
	cin >> numVertices;
	nodeTable = new Vertex[numVertices];
	cout << endl;
	cout << "请输入各顶点的名称：" << endl;

	for (int i = 0; i < numVertices; i++) {
		cin >> nodeTable[i].data;
	}

}


int Graph::getNumberByData(char data) {
	for (int i = 0; i < numVertices; i++)
		if (nodeTable[i].data == data)
			return i;

	return -1;
}


bool Graph::insertEdge(char start, char end, int weight) {
	int v1, v2;
	Edge *q, *p;
	v1 = getNumberByData(start);
	v2 = getNumberByData(end);
	if (-1 == v1 || -1 == v2)                          //如果不同时存在这样的两个顶点，则返回false
		return false;


	p = nodeTable[v1].adj;
	while (p && (p->dest != v2)) {
		p = p->link;
	}

	if (p)
		return false;                             //如果已经存在(v1,v2),则直接返回


	p = new Edge;
	q = new Edge;

	p->dest = v2; p->cost = weight;                    //将v2链入v1
	p->link = nodeTable[v1].adj;
	nodeTable[v1].adj = p;


	q->dest = v1; q->cost = weight;                  //将v1链入v2
	q->link = nodeTable[v2].adj;
	nodeTable[v2].adj = q;

	numEdges++;
	return true;

}

int Graph::getWeight(int v1, int v2) {
	Edge *p;

	if (v1 == -1 || v2 == -1) {
		cout << "No such edges!!!" << endl;
		return -1;
	}

	p = nodeTable[v1].adj;
	while (p&&p->dest != v2)
		p = p->link;

	if (p)
		return p->cost;

}


void Graph::completeEdge() {
	char v1, v2;
	int weight;
	cout << "请输入两个顶点及此边的权值,# # #结束";
	cin >> v1 >> v2 >> weight;
	while (v1 != '#') {
		insertEdge(v1, v2, weight);
		cin >> v1 >> v2 >> weight;
	}
}



Vertex* Graph::getNodeTable() {
	return nodeTable;
}
