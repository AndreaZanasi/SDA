#include "elemtype.h"
#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {

	if (h == NULL || i > (int)h->size || h->data == NULL || i < 0) {
		return;
	}

	if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
	}
	else {
		return;
	}

	HeapMinMoveUpRec(h, i);
}