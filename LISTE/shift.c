#include "shift.h"

size_t ListGetLen(Item* i) {

	size_t ris = 0;
	Item* tmp = i;

	while (!ListIsEmpty(tmp)) {

		ris++;
		tmp = ListGetTail(tmp);

	}

	return ris;
}

Item* ShiftN(Item* list, size_t n) {

	if (ListIsEmpty(list)) {
		return list;
	}

	size_t len = ListGetLen(list);

	if (len == 1 || n == 0) {
		return list;
	}

	Item new_start = { .next = list->next };
	Item* old_start = list;
	Item* succ = list;
	Item* tmp = list;
	size_t i = 0;

	while (n > len) {
		n = n - (len - 1);
	}

	if (n == len) {
		n = 1;
	}

	while (true) {
		if (i == n) {
			succ = tmp->next;
			tmp->next = old_start;
			old_start->next = succ;
			break;
		}
		tmp = ListGetTail(tmp);
		i++;
	}


	return new_start.next;

}