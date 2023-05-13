#include "elemtype.h"
#include "list.h"

Item* Sort(Item* i) {

	int cnt = 0;

	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		cnt++;
	}

	bool scambi = false;

	Item fake_head = { .next = i };

	i = &fake_head;

	while (!scambi) {

		scambi = true;
		Item* prev = &fake_head;
		Item* curr = prev->next;

		for (int j = 0; j < cnt && !ListIsEmpty(ListGetTail(curr)); j++) {

			Item* succ = curr->next;
			Item* succsucc = succ->next;
			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(succ)) > 0) {
				prev->next = succ;
				curr->next = succsucc;
				succ->next = curr;
				scambi = false;
				prev = succ;
			}
			prev = curr;
			curr = succ;
		}
		cnt--;
	}


	return fake_head.next;
}