#include <stdlib.h>
#include <stdbool.h>

void Swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void CocktailSort(int* v, size_t v_size) {

	int start = 0, end = (int)v_size - 1, i;
	bool flag = false;

	while (true) {
		for (i = start; i < end; i++) {
			if (v[i] > v[i + 1]) {
				flag = true;
				Swap(&v[i], &v[i + 1]);
			}
		}
		end--;
		for (i = end; i >= start; i--) {
			if (v[i] < v[i - 1]) {
				flag = true;
				Swap(&v[i], &v[i - 1]);
			}
		}
		start++;
		if (end <= start || flag == false) {
			return;
		}
		flag = false;
	}
}