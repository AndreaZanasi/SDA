#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>

bool IsHeap(const Heap* h) {

	if (h == NULL || h->size == 0 || h->data == NULL) {
		return true;
	}
	for (int i = 0; i < (int)h->size; i++) {
		int l, r;
		if (HeapLeft(i) < (int)h->size) {
			l = HeapLeft(i);
			if (ElemCompare(&h->data[i], &h->data[l]) > 0) {
				return false;
			}
		}
		if (HeapRight(i) <= (int)h->size) {
			r = HeapRight(i);
			if (ElemCompare(&h->data[i], &h->data[r]) > 0) {
				return false;
			}
		}
	}

	return true;
}
