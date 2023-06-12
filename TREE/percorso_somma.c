#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

void PercorsoSommaRec(Node* t, const ElemType* target, ElemType sum, bool* b) {

	sum += *TreeGetRootValue(t);
	if (sum == *target && TreeIsLeaf(t)) {
		*b = true;
	}

	if (!TreeIsEmpty(TreeLeft(t))) {
		PercorsoSommaRec(TreeLeft(t), target, sum, b);
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		PercorsoSommaRec(TreeRight(t), target, sum, b);
	}
}

bool PercorsoSomma(Node* t, const ElemType* target) {

	if (TreeIsEmpty(t)) {
		return false;
	}

	bool b = false;
	PercorsoSommaRec(t, target, 0, &b);

	return b;
}
