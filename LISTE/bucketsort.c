#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

extern Item* BucketSort(Item* l) {
	int max, min, size;
	GetMinMaxSize(l, &min, &max, &size);

	if (size == 1) {
		return l;
	}
	if (l == NULL) {
		return NULL;
	}

	Item** v = calloc(size, sizeof(Item));

	for (Item* tmp = l; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		int index = ((size - 1) * (*ListGetHeadValue(tmp) - min)) / (max - min);
		for (int i = 0; i < size; i++) {
			if (i == index) {
				v[i] = ListInsertBack(v[i], ListGetHeadValue(tmp));
				break;
			}
		}
	}

	if (size == 2) {
		l = ConcatList(BucketSort(v[0]), BucketSort(v[1]));
		free(v);
		return l;
	}

	free(l);
	Item* ris = calloc(size, sizeof(Item));
	ris = BucketSort(v[0]);

	for (int i = 1; i < size; i++) {
		if (v[i] != NULL) {
			ris = ConcatList(ris, BucketSort(v[i]));
		}
	}

	free(v);

	return ris;
}