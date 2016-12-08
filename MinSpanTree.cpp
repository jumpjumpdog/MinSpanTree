#include"MinSpanTree.h"

void MinSpanTree::outPut(Graph* p) {
	Vertex* q = p->getNodeTable();
	for (int i = 0; i < n; i++) {  
		cout <<q[edgeValue[i].head].data <<  "-(" << edgeValue[i].key <<")-"<< q[edgeValue[i].tail].data<< "       ";
	}
}


int MinSpanTree::insert(MSTEdgeNode& item) {                  //���߽ڵ�����ֵ����

	if (n <= maxSize - 1)
	{
		edgeValue[n] = item;
		n++;
		return 1;
	}
	return 0;
}