#pragma once
#include"graph.h"
struct MSTEdgeNode {
	int tail, head, key;
	MSTEdgeNode() :tail(-1), head(-1), key(-1) {};
	bool operator <=(MSTEdgeNode & R) { return key <= R.key; };
	bool operator > (MSTEdgeNode & R) { return key > R.key; };
	MSTEdgeNode& operator = (const MSTEdgeNode &p) { tail = p.tail; head = p.head; key = p.key; return *this; };

};



class MinHeap {
private:
	MSTEdgeNode * heap;
	int currnetSize;                       //当前元素个数
	int maxHeapSize;                       //最多允许元素个数
	void siftDown(int start, int m);                                //从start到m下滑调整成为最小堆
	void siftUp(int start);

public:
	MinHeap(int size = 100) :maxHeapSize(size), currnetSize(0) { heap = new MSTEdgeNode[size]; };
	bool insert(const MSTEdgeNode &);
	bool isEmpty()const;
	bool remove(MSTEdgeNode &);
};
