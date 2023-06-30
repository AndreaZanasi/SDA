#include <stdlib.h>
#include <stdio.h>

void FrazioneEgiziaRec(int n, int d) {

	int first_d = d / n + (d % n != 0);

	printf("1/%d ", first_d);

	if (d % n == 0) {
		return;
	}

	printf("+ ");
	int new_n = n * first_d - d;
	int new_d = d * first_d;
	
	FrazioneEgiziaRec(new_n, new_d);
}

void FrazioneEgizia(int n, int d) {

	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia.");
		return;
	}

	FrazioneEgiziaRec(n, d);

}
