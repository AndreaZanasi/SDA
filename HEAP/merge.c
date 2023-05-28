#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap* ris = malloc(sizeof(Heap));

	if (h1 == NULL) {
		ris->size = h2->size;
		ris->data = malloc(ris->size * sizeof(ElemType));
		ris->data = memcpy(ris->data, h2->data, ris->size * sizeof(ElemType));
		return ris;
	}
	if (h2 == NULL) {
		ris->size = h1->size;
		ris->data = malloc(ris->size * sizeof(ElemType));
		ris->data = memcpy(ris->data, h1->data, ris->size * sizeof(ElemType));
		return ris;
	}
	if (h1 == NULL && h2 == NULL) {
		return NULL;
	}

	ris->size = h1->size + h2->size;
	ris->data = calloc(ris->size, sizeof(ElemType));
	int i = 0;

	for (; i < (int)h1->size; i++) {
		ris->data[i] = h1->data[i];
	}
	for (int j = 0; j < (int)h2->size; j++) {
		ris->data[i] = h2->data[j];
		i++;
	}
	for (i = 0; i < (int)ris->size; i++) {
		HeapMinMoveUp(ris, i);
	}

	return ris;
}