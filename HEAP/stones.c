#include "elemtype.h"
#include "maxheap.h"
#include <stdlib.h>

void Swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}

int LastStoneWeight(Heap* h) {

	if (HeapIsEmpty(h) || h->data == NULL || h->size == 0) {
		return 0;
	}

    ElemType popped = 0, stone = 0;

    while (true) {

        if (h->data[0] <= 0) {
            Pop(h, &popped);
        }
        if (h->size == 1) {
            break;
        }

        stone = h->data[0] - h->data[1];
        if (stone > 0) {
            h->data[0] -= h->data[1];
            h->data[1] = 0;
            Swap(&h->data[0], &h->data[1]);
        }
        else if (stone == 0) {
            h->data[0] = 0;
            h->data[1] = 0;
        }
        else if (stone < 0) {
            h->data[0] -= h->data[1];
        }
    }

    if (h->data[0] == 0) {
        Pop(h, &popped);
        return 0;
    }

    return h->data[0];
}