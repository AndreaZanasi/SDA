#include "vettore.h"

Vector* VectorRead(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* vr = malloc(sizeof(Vector));
	vr->capacity = 1;
	vr->size = 0;
	vr->data = malloc(sizeof(ElemType));

	while (true) {
		ElemType tmp = 0;
		int j = ElemRead(f, &tmp);
		if (j == 0) {
			return NULL;
		}
		else if (j != 1) {
			break;
		}
		if (vr->size == vr->capacity) {
			vr->capacity *= 2;
			vr->data = realloc(vr->data, vr->capacity * sizeof(ElemType));
		}
		vr->data[vr->size] = tmp;
		(vr->size)++;

	}

	fclose(f);
	return vr;
}

Vector* VectorReadSorted(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* vrs = malloc(sizeof(Vector));
	vrs->capacity = 1;
	vrs->size = 0;
	vrs->data = malloc(sizeof(ElemType));
	size_t i = 0;

	while (true) {
		ElemType tmp = 0;

		int j = ElemRead(f, &tmp);
		if (j == 0) {
			return NULL;
		}
		else if (j != 1) {
			break;
		}
		if (vrs->size == vrs->capacity) {
			vrs->capacity *= 3;
			vrs->data = realloc(vrs->data, vrs->capacity * sizeof(ElemType));
		}
		(vrs->size)++;

		if (i == 0) {
			vrs->data[i] = tmp;
		}

		bool flag = false;

		for (size_t k = 0; k < vrs->size; k++) {

			if (tmp < vrs->data[k]) {
				memcpy((&vrs->data[k + 1]), &vrs->data[k], (vrs->size - k) * sizeof(ElemType));
				vrs->data[k] = tmp;
				flag = true;
				break;
			}
		}
		if (flag == false) {
			vrs->data[i] = tmp;
		}
		i++;
	}
	fclose(f);
	return vrs;
}