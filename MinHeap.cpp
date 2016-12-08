#include"MinHeap.h"


bool MinHeap::insert(const MSTEdgeNode & p) {
	if (currnetSize == maxHeapSize)
	{
		cerr << "HeapFULL"; return false;
	}

	heap[currnetSize] = p;
	siftUp(currnetSize);
	currnetSize++;
	return true;

}


bool MinHeap::isEmpty()const {
	if (!currnetSize)
		return true;
	else
		return false;
}


bool MinHeap::remove(MSTEdgeNode & p) {
	if (!currnetSize) { cerr << "heap empty" << endl; return false; }

	p = heap[0];
	heap[0] = heap[currnetSize - 1];
	currnetSize--;
	siftDown(0, currnetSize - 1);
	return true;
}

void MinHeap::siftDown(int start, int m) {
	int i = start, j = 2 * i + 1;
	MSTEdgeNode  temp = heap[i];
	while (j <= m) {
		if (j<m&&heap[i]>heap[j + 1])  j = j + 1;
		if (temp <= heap[j])break;
		else {
			heap[i] = heap[j];
			i = j;
			j = 2 * i + 1;
		}
	}

	heap[i] = temp;
}


void MinHeap::siftUp(int start) {

	int j = start, i = (j - 1) / 2;
	MSTEdgeNode temp = heap[j];

	while (j > 0) {
		if (heap[i] <= temp)
			break;
		else {
			heap[j] = heap[i];
			j = i;
			i = (i - 1) / 2;
		}
	}
	heap[j] = temp;
}

