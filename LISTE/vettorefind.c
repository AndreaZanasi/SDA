#include "vettore.h"

int VectorFind(const Vector* v, const ElemType* e) {

	int pos;

	if (v == NULL) {
		return -1;
	}

	for (size_t i = 0; i < v->size; i++) {
		if (v->data[i] == *e) {
			pos = (int)i;
			return pos;
		}
	}

	return -1;
}