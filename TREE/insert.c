#include "elemtype.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* BstInsertRec(const ElemType* e, Node* n) {

	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}

	Node* tmp = n;

	if (ElemCompare(e, TreeGetRootValue(tmp)) > 0) {
		if (tmp->right == NULL) {
			tmp->right = TreeCreateRoot(e, NULL, NULL);
			return tmp;
		}
		tmp = BstInsertRec(e, tmp->right);
	}
	else if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
		if (tmp->left == NULL) {
			tmp->left = TreeCreateRoot(e, NULL, NULL);
			return tmp;
		}
		tmp = BstInsertRec(e, tmp->left);
	}

	return n;
}

Node* BstInsert(const ElemType* e, Node* n) {

	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}

	Node* tmp = n;

	while (true) {

		if (ElemCompare(e, TreeGetRootValue(tmp)) > 0) {
			if (tmp->right == NULL) {
				tmp->right = TreeCreateRoot(e, NULL, NULL);
				break;
			}
			tmp = TreeRight(tmp);
		}
		else if (ElemCompare(e, TreeGetRootValue(tmp)) <= 0) {
			if (tmp->left == NULL) {
				tmp->left = TreeCreateRoot(e, NULL, NULL);
				break;
			}
			tmp = TreeLeft(tmp);
		}
	}

	return n;
}

