#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>

void Push(Heap* h, const ElemType* e) {

	if (h == NULL || h->size == 0 || h->data == NULL || e == NULL) {
		return;
	}

	h->size++;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	h->data[h->size - 1] = *e;

	for (int i = 0; i < (int)h->size; i++) {
		HeapMinMoveUp(h, i);
	}
}