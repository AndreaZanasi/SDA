#include "elemtype.h"
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

Item* PariDispari(Item* i) {

	if (i == NULL) {
		return NULL;
	}

	Item* tmp = i;
	Item start = { .next = i };
	Item* curr = i;
	Item* tmp2 = i;
	Item start2 = { .next = i };
	size_t j = 0, k = 0;
	bool pari = false, dispari = false;

	while (!ListIsEmpty(tmp)) {

		if (*ListGetHeadValue(tmp) % 2 == 0) {
			if (j == 0) {
				start.next = tmp;
				curr = tmp;
				pari = true;
			}
			else {
				curr->next = tmp;
				curr = ListGetTail(curr);
			}
			j++;
		}
		else {
			if (k == 0) {
				dispari = true;
				start2.next = tmp;
				tmp2 = tmp;
			}
			else {
				tmp2->next = tmp;
				tmp2 = ListGetTail(tmp2);
			}
			k++;
		}

		tmp = ListGetTail(tmp);
	}
	if (pari == false || dispari == false) {
		return i;
	}
	tmp2->next = NULL;
	curr->next = start2.next;

	return start.next;
}