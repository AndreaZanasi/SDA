#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>

void Swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

int KthLeast(const int* v, size_t n, int k) {

	Heap* h = malloc(sizeof(Heap));
	h->data = calloc(n, sizeof(ElemType));
	memcpy(h->data, v, n * sizeof(ElemType));
	h->size = n;
	int dim = (int)n;

	while (dim != 1) {
		for (int i = 0; i < dim - 1; i++) {
			if (h->data[i] > h->data[i + 1]) {
				Swap(&h->data[i], &h->data[i + 1]);
			}
		}
		dim--;
	}

	int min = (int)h->data[k - 1];
	free(h->data);
	free(h);

	return min;
}