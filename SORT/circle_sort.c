#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void CircleSortRec(int* v, size_t v_size, bool* swap) {

	size_t dim = v_size;
	size_t i = 0;

	if (dim == 1) {
		return;
	}

	while (i != v_size/2) {

		if (v[i] > v[dim - 1]) {
			Swap(&v[i], &v[dim - 1]);
			*swap = true;
		}
		dim--;
		i++;
	}
	if ((v_size % 2) != 0) {
		if (v[v_size/2] > v[(v_size / 2) + 1]) {
			Swap(&v[v_size / 2], &v[(v_size / 2) + 1]);
			*swap = true;
		}
		CircleSortRec(v, (v_size / 2) + 1, swap);
		CircleSortRec(v + (v_size / 2) + 1, v_size / 2, swap);
	}
	else {
		CircleSortRec(v + v_size / 2, v_size / 2, swap);
		CircleSortRec(v, v_size / 2, swap);
	}
}

void CircleSort(int* v, size_t v_size) {

	if (v == NULL || v_size == 0) {
		return;
	}

	bool swap = false;

	CircleSortRec(v, v_size, &swap);

	while (swap == true) {
		swap = false;
		CircleSortRec(v, v_size, &swap);
	}
}