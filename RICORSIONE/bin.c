#include <stdlib.h>
#include <stdio.h>

void PrintBin(int n) {

	if (n == 0) {
		printf("0");
		return;
	}
	if (n == 1) {
		printf("1");
		return;
	}
	else {
		PrintBin(n / 2);
	}

	if (n % 2 == 0) {
		 printf("0");
		 return;
	}
	if (n % 2 != 0) {
		printf("1");
		return;
	}

	

}

int main(int argc, char** argv) {

	if (argc != 2) {
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}

	PrintBin(n);

	return 0;
}