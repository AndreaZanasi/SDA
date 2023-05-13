#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

void PrintSolution(bool* vbest, size_t n, int* insieme) {

	if (n == 0) {
		printf("{ }, { }");
		return;
	}

	size_t j = 0;
	size_t z = 0;
	size_t u = 0;
	for (; j < n; j++) {
		if (vbest[j]) { 
			u++; 
		}
		else z++; 
	}
	printf("{ ");
	j = 0;
	for (; u != 1; j++) { 
		if (vbest[j]) { 
			printf("%d, ", insieme[j]); 
			u--; 
		} 
	}
	for (; u != 0; j++) { 
		if (vbest[j]) { 
			printf("%d ", insieme[j]); 
			u--; 
		} 
	}
	printf("}, ");
	printf("{ ");
	j = 0;
	for (; z != 1; j++) { 
		if (!vbest[j]) { 
			printf("%d, ", insieme[j]); 
			z--; 
		} 
	}
	for (; z != 0; j++) { if (!vbest[j]) { 
		printf("%d ", insieme[j]); 
		z--; 
	} 
	}
	printf("}");

}

void TiroAllaFuneRec(int* insieme, size_t n, int sub, int suma, int sumb, int* submin, size_t i, bool* vcurr, bool* vbest) {

	if (n != 0) {
		if (i == n) {
			size_t k = 0;
			size_t l = n / 2;
			for (size_t j = 0; j < n; j++) { 
				if (vcurr[j]) { 
					k++; 
				} 
			}
			if (k != l) {
				return;
			}
			for (size_t j = 0; j < n; j++) { 
				if (vcurr[j]) { 
					suma += insieme[j]; 
				} 
			}
			for (size_t j = 0; j < n; j++) { 
				if (!vcurr[j]) { 
					sumb += insieme[j]; 
				} 
			}
			sub = abs(suma - sumb);
			if (sub < *submin) {
				*submin = sub;
				memcpy(vbest, vcurr, n * sizeof(bool));
			}
			return;
		}

		vcurr[i] = 0;
		TiroAllaFuneRec(insieme, n, sub, suma, sumb, submin, i + 1, vcurr, vbest);
		vcurr[i] = 1;
		TiroAllaFuneRec(insieme, n, sub, suma, sumb, submin, i + 1, vcurr, vbest);
		vcurr[i] = 0;
	}
	else {
		return;
	}

}

int main(int argc, char** argv) {

	size_t n = argc - 1;
	size_t j = 0;
	int i = 1;
	int submin = INT_MAX;
	int* insieme = malloc((argc - 1) * sizeof(int));
	bool* vcurr = calloc(n, sizeof(bool));
	bool* vbest = calloc(n, sizeof(bool));

	for (; i < argc; i++) { 
		insieme[j] = atoi(argv[i]); 
		j++; 
	}

	TiroAllaFuneRec(insieme, n, 0, 0, 0, &submin, 0, vcurr, vbest);
	PrintSolution(vbest, n, insieme);

	free(vcurr);
	free(insieme);
	free(vbest);

	return 0;

}