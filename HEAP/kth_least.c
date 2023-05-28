#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>

void BubbleSort(ElemType* v, size_t size) {

	int i = 0;

	while (size > 1) {

		for (i = 0; i < (int)size - 1; i++) {
			if (v[i] > v[i + 1]) {
				ElemSwap(&v[i], &v[i + 1]);
			}
		}
		size--;
	}

}

ElemType KthLeast(const Heap* h, int k) {

	if (k < 1 || h == NULL || h->size == 0 || h->data == NULL || k > (int)h->size) {
		return 0;
	}

	if (k == 1) {
		return h->data[0];
	}

	ElemType e = 0;

	ElemType* v = malloc(h->size * sizeof(ElemType));
	memcpy(v, h->data, h->size * sizeof(ElemType));

	BubbleSort(v, h->size);
	e = v[k - 1];
	free(v);

	return e;
}