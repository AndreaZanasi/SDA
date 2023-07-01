#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool Pop(Heap* h, ElemType* e) {

	if (h == NULL || h->data == NULL || h->size == 0) {
		return false;
	}

	*e = ElemCopy(&h->data[0]);
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	h->size--;
	realloc(h->data, h->size * sizeof(ElemType));
	for (size_t i = 0; i < h->size; i++) {
		HeapMinMoveDown(h, (int)i);
	}

	return true;
}