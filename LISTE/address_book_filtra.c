#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

Item* Filtra(const Item* i, const char* city) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	ElemType e;
	strcpy(e.city, city);

	Item* filtred = ListCreateEmpty();

	while (!ListIsEmpty(i)) {

		if (ElemCompare(ListGetHeadValue(i), &e) == 0) {

			filtred = ListInsertBack(filtred, ListGetHeadValue(i));

		}

		i = ListGetTail(i);
	}

	return filtred;
}