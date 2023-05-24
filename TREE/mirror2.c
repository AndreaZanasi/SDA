#include "elemtype.h"
#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

void TreeIsMirrorRec(Node* l, Node* r, bool* ris) {

	if (l != NULL && r != NULL) {
		if (ElemCompare(TreeGetRootValue(l), TreeGetRootValue(r))) {
			*ris = false;
			return;
		}
	}
	else {
		return;
	}

	if (!TreeIsLeaf(l) && !TreeIsLeaf(r)) {
		TreeIsMirrorRec(l->left, r->right, ris);
		TreeIsMirrorRec(l->right, r->left, ris);
	}
	else if ((TreeIsLeaf(l) && !TreeIsLeaf(r)) || (TreeIsLeaf(r) && !TreeIsLeaf(l))) {
		*ris = false;
		return;
	}
	else{

		return;
	}

}

bool TreeIsMirror(Node* t) {

	if (TreeIsEmpty(t)) {
		return true;
	}
	if (TreeIsLeaf(t)) {
		return true;
	}

	bool ris = true;

	TreeIsMirrorRec(t->left, t->right, &ris);

	return ris;
}