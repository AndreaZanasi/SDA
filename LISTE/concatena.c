#include "doublelist.h"
#include "elemtype.h"
#include <stdlib.h>

Item* ConcatenaN(Item** v, size_t v_size) {
	
	if (v_size == 0 || v == NULL) {
		return NULL;
	}

	Item* head = DListCreateEmpty();
	Item* init = v[0];
	size_t i = 0;

	for (; i < v_size; i++) {
		if (v[i] != NULL) {
			head = v[i];
			init = v[i];
			break;
		}
	}

	i++;

	if (DListIsEmpty(head)) {
		return NULL;
	}

	for (; i < v_size; i++) {

		if (DListIsEmpty(v[i])) {
			continue;
		}

		Item* tmp = v[i];
		for (; !DListIsEmpty(head->next); head = DListGetTail(head));
		head->next = tmp;
		tmp->prev = head;
		if (i == v_size - 1) {
			for (; !DListIsEmpty(tmp->next); tmp = DListGetTail(tmp));
			tmp->next = NULL;
			break;
		}
	}

	return init;
}