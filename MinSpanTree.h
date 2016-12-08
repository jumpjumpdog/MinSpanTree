#pragma once
#include"MinHeap.h"
class MinSpanTree {                                    /*最小生成树因为其实是仅仅只是存储数据的，对于数据的选择其实是在													  */
public:
	MinSpanTree(int sz = 100) :maxSize(sz), n(0) {
		edgeValue = new MSTEdgeNode[sz];
	};

	int insert(MSTEdgeNode&item);
	void outPut(Graph * );

private:
	MSTEdgeNode* edgeValue;
	int maxSize, n;

};




