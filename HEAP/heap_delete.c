#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

void HeapDeleteNode(Heap* h, int k) {

	if (k < 0 || k >= (int)h->size || h->size == 0 || h == NULL || h->data == NULL) {
		return;
	}

	ElemSwap(HeapGetNodeValue(h, k), HeapGetNodeValue(h, (int)h->size - 1));
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, k);
}