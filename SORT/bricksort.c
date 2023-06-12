#include <stdlib.h>
#include <stdbool.h>

void Swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BrickSort(int* v, size_t v_size) {

	if (v == NULL || v_size == 0) {
		return;
	}

	size_t dim = v_size;
	bool inorder = false;
	while (!inorder) {
		inorder = true;
		for (int i = 1; i < dim - 1; i += 2) {
			if (v[i] > v[i + 1]) {
				Swap(&v[i], &v[i + 1]);
				inorder = false;
			}
		}
		for (int i = 0; i < dim - 1; i += 2) {
			if (v[i] > v[i + 1]) {
				Swap(&v[i], &v[i + 1]);
				inorder = false;
			}
		}
	}

}