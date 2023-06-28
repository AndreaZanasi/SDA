#include "next_greater.h"

size_t ListLen(const Item* i) {
	size_t len = 0;
	const Item* tmp = i;
	while (!ListIsEmpty(tmp)) {
		tmp = ListGetTail(tmp);
		len++;
	}
	return len;
}

ElemType* NextGreater(const Item* list, size_t* answer_size) {

	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}

	*answer_size = ListLen(list);
	ElemType* v = calloc(*answer_size, sizeof(ElemType));
	size_t i = 0;
	bool isgrater;

	for (const Item* tmp1 = list; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
		isgrater = false;
		for (const Item* tmp2 = ListGetTail(tmp1); !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
			if (*ListGetHeadValue(tmp1) < *ListGetHeadValue(tmp2) && tmp2 != NULL) {
				isgrater = true;
				v[i] = *ListGetHeadValue(tmp2);
				i++;
				break;
			}
		}
		if (isgrater == false) {
			v[i] = INT_MIN;
			i++;
		}
	}

	return v;
}