#include <stdlib.h>

void Swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void GnomeSort(int* v, size_t v_size) {

	size_t i = 0;

	if (v_size == 1 || v == NULL) {
		return;
	}

	while (i < v_size) {

		if (i == 0) {
			i++;
		}

		if (v[i] >= v[i - 1]) {
			i++;
		}
		else {
			Swap(&v[i], &v[i - 1]);
			i--;
		}

	}
}