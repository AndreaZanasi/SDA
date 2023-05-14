#include <stdlib.h>
#include <stdio.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Stooge(int* vector, size_t vector_size) {

	if (vector == NULL || vector_size == 0) {
		return;
	}

	size_t size = vector_size;
	if (vector[0] > vector[size - 1]) {
		Swap(&vector[0], &vector[vector_size - 1]);
	}
	size = ((vector_size * 2) / 3) + ((vector_size * 2) % 3 != 0);
	if (vector_size >= 3) {
		Stooge(vector, size);
		Stooge(vector + (vector_size - size), size);
		Stooge(vector, size);
	}
}