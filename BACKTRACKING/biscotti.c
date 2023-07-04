#include <stdlib.h>
#include <string.h>

void Swap(int* a, int* b) {

    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void BambiniSwap(int* bam, int* bis, size_t bam_size, size_t i, size_t bis_size, int* ris) {

    if (i == bam_size) {

        int soddisfatti = 0;
        int j = 0;
        int grammi = 0;
        for (size_t k = 0; k < bis_size; k++) {
            grammi += bis[k];
            if (bam[j] - grammi <= 0) {
                soddisfatti++;
                grammi = 0;
                j++;
            }
        }
        if (bam[j] - grammi <= 0 && j < bam_size) {
            soddisfatti++;
        }

        if (soddisfatti > *ris) {
            *ris = soddisfatti;
        }

        return;

    }

    for (size_t j = i; j < bam_size; j++) {
        Swap(&bam[i], &bam[j]);
        BambiniSwap(bam, bis, bam_size, i + 1, bis_size, ris);
    }

}

void AssegnaBiscottiRec(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size, size_t i, int* ris, int* vcurr, int* bamcurr) {

    if (i == bis_size) {

        BambiniSwap(bamcurr, vcurr, bam_size, 0, bis_size, ris);
        memcpy(bamcurr, bam, bam_size * sizeof(int));

        int soddisfatti = 0;
        int j = 0;
        int grammi = 0;
        for (size_t k = 0; k < bis_size; k++) {
            grammi += bis[k];
            if (bam[j] - grammi <= 0) {
                soddisfatti++;
                grammi = 0;
                j++;
            }
        }
        if (bam[j] - grammi <= 0 && j < bam_size) {
            soddisfatti++;
        }

        if (soddisfatti > *ris) {
            *ris = soddisfatti;
        }

        return;
    }

    for (size_t j = i; j < bis_size; j++) {
        Swap(&vcurr[i], &vcurr[j]);
        AssegnaBiscottiRec(bam, bam_size, bis, bis_size, i + 1, ris, vcurr, bamcurr);
    }

}

int AssegnaBiscotti(const int* bam, size_t bam_size,
    const int* bis, size_t bis_size) {
    
    if (bam == NULL || bis == NULL || bam_size == 0 || bis_size == 0) {   
        return 0;
    }

    int* vcurr = malloc(bis_size * sizeof(int));
    int* bamcurr = malloc(bam_size * sizeof(int));
    memcpy(bamcurr, bam, bam_size * sizeof(int));
    memcpy(vcurr, bis, bis_size * sizeof(int));
    int best = 0;

    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, 0, &best, vcurr, bamcurr);

    free(vcurr);
    free(bamcurr);

    return best;
}

