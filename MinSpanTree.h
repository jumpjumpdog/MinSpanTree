#pragma once
#include"MinHeap.h"
class MinSpanTree {                                    /*��С��������Ϊ��ʵ�ǽ���ֻ�Ǵ洢���ݵģ��������ݵ�ѡ����ʵ����													  */
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




