#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void ValidTimesRec(uint8_t n, int* times, bool* vcurr, size_t i) {

	if (i == 11) {

		int cnt = 0;

		for (size_t j = 0; j < 11; j++) {
			if (vcurr[j] == 1) {
				cnt++;
			}
		}

		if (cnt != n) {
			return;
		}

		int m = 0;
		int h = 0;

		for (size_t j = 0; j < 5; j++) {
			if (vcurr[j] == 1) {
				h += times[j];
			}
		}
		for (size_t j = 5; j < 11; j++) {
			if (vcurr[j] == 1) {
				m += times[j];
			}
		}

		if (h > 23 || m > 59) {
			return;
		}

		if (h / 10 == 0) {
			printf("0%d:", h);
		}
		else if (h == 0) {
			printf("00:");
		}
		else {
			printf("%d:", h);
		}
		if (m / 10 == 0) {
			printf("0%d, ", m);
		}
		else if (m == 0) {
			printf("00, ");
		}
		else {
			printf("%d, ", m);
		}

		return;
	}

	vcurr[i] = 0;
	ValidTimesRec(n, times, vcurr, i + 1);

	vcurr[i] = 1;
	ValidTimesRec(n, times, vcurr, i + 1);
}

void ValidTimes(uint8_t n) {

	if (n > 11) {
		return;
	}

	int times[] = { 16, 8, 4, 2, 1, 32, 16, 8, 4, 2, 1 };

	bool* vcurr = calloc(11, sizeof(bool));

	ValidTimesRec(n, times, vcurr, 0);

	free(vcurr);
}