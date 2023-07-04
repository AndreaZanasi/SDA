#include "reverse.h"

int ListGetLen(Item* i) {

	int len = 0;
	Item* tmp = i;

	for (; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}

	return len;
}

Item* ReverseRec(Item* list, int right, Item* start) {

	if (right == 0 || right == 1) {
		start = ListGetTail(start);
		return start;
	}

	Item* init = list;
	Item* init_next = list->next;
	Item* end = list;
	Item* end_prec = list;
	int i = 0;

	while(i != right - 1){
		end_prec = end;
		end = ListGetTail(end);
		i++;
	}

	if (right == 2) {
		start = end;
		init->next = end->next;
		end->next = init;
		return start;
	}

	start = end;
	init->next = end->next;
	end->next = init_next;
	end_prec->next = init;

	start->next = ReverseRec(start->next, right - 2, start);
	return start;
}

Item* Reverse(Item* list, int right) {

	if (list == NULL) {
		return NULL;
	}

	if (right <= 1) {
		return list;
	}

	size_t len = ListGetLen(list);

	if (right >= (int)len) {
		list = ReverseRec(list, (int)len, NULL);
		return list;
	}

	list = ReverseRec(list, right, NULL);

	return list;
}