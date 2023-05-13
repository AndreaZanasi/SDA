#include "vettore.h"

void VectorSort(Vector* v) {

	if (v == NULL) {
		return;
	}
	
	bool ordinato = false;
	size_t dim = v->size;

	while (dim > 1 && !ordinato) {
		ordinato = true;
		for (size_t i = 0; i < dim - 1; i++) {
			if (v->data[i] > v->data[i + 1]) {
				ordinato = false;
				ElemSwap(&v->data[i], &v->data[i + 1]);
			}
		}
		dim--;
	}
}