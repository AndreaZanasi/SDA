#include "elemtype.h"
#include "minheap.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	Heap* ris = HeapCreateEmpty();

	if (v == NULL) {
		return ris;
	}

	ris->data = malloc(v_size * sizeof(ElemType));
	ris->size = v_size;
	ris->data = memcpy(ris->data, v, v_size * sizeof(ElemType));

	for (int i = 0; i < (int)v_size; i++) {
		HeapMinMoveDown(ris, i);
	}

	return ris;
}