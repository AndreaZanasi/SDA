#include <stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int FindMax(int* v, size_t v_size) {

	int posmax = 0;
	for (size_t i = 0; i <= v_size; i++) {
		if (v[posmax] < v[i]) {
			posmax = (int)i;
		}
	}

	return posmax;
}

void Flip(int* v, size_t v_size) {
	if (v_size <= 1) {
		Swap(&v[v_size], &v[0]);
		return;
	}
	Swap(&v[v_size], &v[0]);
	Flip(v + 1, v_size - 2);
}

void PancakeSort(int* v, size_t v_size) {

	if (v == NULL || v_size == 0) {
		return;
	}

	if (v_size == 1) {
		return;
	}

	size_t curr_size = v_size;
	int m = FindMax(v, curr_size - 1);
	Flip(v, m);
	Flip(v, curr_size - 1);
	curr_size--;

	PancakeSort(v, curr_size);
}