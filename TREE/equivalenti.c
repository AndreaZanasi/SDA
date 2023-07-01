#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

void EquivalentiRec(const Node* t1, const Node* t2, bool* b) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return;
	}
	else if (TreeIsEmpty(t1)) {
		*b = false;
		return;
	}
	else if (TreeIsEmpty(t2)) {
		*b = false;
		return;
	}

	if (*b == false) {
		return;
	}

	if (!TreeIsLeaf(t1) && !TreeIsLeaf(t2)) {
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
			*b = false;
			return;
		}
	}
	else if (TreeIsLeaf(t1), TreeIsLeaf(t2)) {
		if (*TreeGetRootValue(t1) >= *TreeGetRootValue(t2)) {
			if (*TreeGetRootValue(t1) % *TreeGetRootValue(t2) != 0) {
				*b = false;
				return;
			}
		}
		else {
			if (*TreeGetRootValue(t2) % *TreeGetRootValue(t1) != 0) {
				*b = false;
				return;
			}
		}
	}
	else {
		*b = false;
		return;
	}

	EquivalentiRec(TreeLeft(t1), TreeLeft(t2), b);
	EquivalentiRec(TreeRight(t1), TreeRight(t2), b);

}

bool Equivalenti(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	else if (TreeIsEmpty(t1)) {
		return false;
	}
	else if (TreeIsEmpty(t2)) {
		return false;
	}

	bool b = true;

	EquivalentiRec(t1, t2, &b);

	return b;
}