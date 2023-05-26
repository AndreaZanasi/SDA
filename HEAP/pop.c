#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool HeapMinPop(Heap* h, ElemType* e) {

	if (h == NULL || e == NULL || h->size == 0) {
		return false;
	}

	if (h->size == 1) {
		e = HeapGetNodeValue(h, 0);
		HeapDelete(h);
		return true;
	}

	*e = ElemCopy(HeapGetNodeValue(h, 0));
	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);

	return true;
}