#include <stdlib.h>

void Swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertionSort(int* v, size_t v_size) {
	for (size_t i = 0; i < v_size; i++) {
		for (size_t j = 0; j < i; j++) {
			if (v[i] < v[j]) {
				Swap(&v[i], &v[j]);
			}
		}
	}

}