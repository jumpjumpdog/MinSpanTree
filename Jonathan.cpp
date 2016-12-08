#include"MinSpanTree.h"

void prime(Graph & G, const char u0, MinSpanTree& MST) {
	MSTEdgeNode ed;
	int u, v, count;
	int n = G.numberOfVertices();
	int m = G.numberOfEdges();
	 u = G.getNumberByData(u0);


	MinHeap H(m);
	bool * Vmst = new bool[n];
	for (int i = 0; i < n; i++) Vmst[i] = false;
	Vmst[u] = true;
	count = 1;

	do {
		v = G.getFirstNeighbor(u);
		while (v != -1) {
			if (Vmst[v] == false) {
				ed.tail = u;
				ed.head = v;
				ed.key = G.getWeight(u, v);
				H.insert(ed);
			}
			v = G.getNextNeighbor(u, v);
		}

		while (H.isEmpty() == false && count < n) {
			H.remove(ed);
			MST.insert(ed);
			u = ed.head;
			Vmst[u] = true;
			count++;
			break;
		}
	} while (count < n);
}



typedef enum myEnum{A='A',B='B',C='C',D='D',E='E'};


int main() {

	cout << "**           �������ģ��ϵͳ           **" << endl;
	cout << "=================================================="<<endl;
	cout << "**           A --- ���������Ķ���       ** "<<endl;
	cout << "**           B --- ��ӵ����ı�         ** " << endl;
	cout << "**           C --- ������С������       ** " << endl;
	cout << "**           D --- ��ʾ��С������       ** " << endl;
	cout << "**           E --- �˳�����             ** " << endl;
	cout << "==================================================" << endl;

	myEnum  choice;
	char int_choice, u0;
	Graph *graph;
	MinSpanTree *minSpanTree = new MinSpanTree;
	while (true) {
		cout << "��ѡ�������";
		cin >> int_choice;
		choice = (myEnum)int_choice;
		
		switch (choice)
		{
		case A: 
			graph = new Graph; break;
		case B:
			graph->completeEdge();  break;
		case C: {

			cout << "�������ʼ�ڵ㣺";
			cin >> u0;
			prime(*graph, u0, *minSpanTree);
		} break;
		case D: {
			minSpanTree->outPut(graph);
		}break;	
		case E:
		{
			exit(0);
		}
			break;
		default:
			break;
		}
	}

	return 0;
}




