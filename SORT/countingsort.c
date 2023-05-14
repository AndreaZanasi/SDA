#include <stdlib.h>

void CountingSort(int* v, size_t v_size) {

	if (v == NULL || v_size == 0) {
		return;
	}

	int max = v[0], min = v[0];

	for (int i = 0; i < (int)v_size; i++) {
		if (v[i] > max) {
			max = v[i];
		}
		if (v[i] < min) {
			min = v[i];
		}
	}
	int size = max - min + 1;
	int supp = min;
	int *tmp = calloc(sizeof(int), size * sizeof(int));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (int)v_size; j++) {

			if (v[j] == supp) {
				tmp[i]++;
			}

		}
		supp++;
	}
	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < tmp[i]; j++){
			v[k] = min;
			k++;
		}
		min++;
	}

	free(tmp);

}