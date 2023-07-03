#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

void GetTreeLvl(Node* t, int lvl_curr, int* lvl_max) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (*lvl_max < lvl_curr) {
		*lvl_max = lvl_curr;
	}

	GetTreeLvl(TreeLeft(t), lvl_curr + 1, lvl_max);
	GetTreeLvl(TreeRight(t), lvl_curr + 1, lvl_max);
}

void Sum(Node* t, int* lvl, int lvl_curr) {

	if (TreeIsEmpty(t)) {
		return;
	}

	Sum(TreeLeft(t), lvl, lvl_curr + 1);
	Sum(TreeRight(t), lvl, lvl_curr + 1);

	if (TreeIsLeaf(t)) {
		return;
	}
	ElemType a, b, c;
	a = *TreeGetRootValue(t);
	if (TreeIsEmpty(t->left)) {
		b = 0;
		c = *TreeGetRootValue(t->right);
	}
	else if (TreeIsEmpty(t->right)) {
		c = 0;
		b = *TreeGetRootValue(t->left);
	}
	else {
		b = *TreeGetRootValue(t->left);
		c = *TreeGetRootValue(t->right);
	}
	t->value = a + b + c;
}

/*void Sum(Node* t, int* lvl, int lvl_curr) {

	if (TreeIsLeaf(t)) {
		return;
	}

	if (*lvl == lvl_curr) {
		*lvl = -1;
	}

	if (*lvl == -1) {
		ElemType a, a1, a2, sum;
		a = *TreeGetRootValue(t);
		if (TreeIsEmpty(TreeLeft(t))) {
			a1 = 0;
		}
		else if (TreeIsEmpty(TreeRight(t))) {
			a2 = 0;
		}
		else {
			a1 = *TreeGetRootValue(TreeLeft(t));
			a2 = *TreeGetRootValue(TreeRight(t));
		}

		sum = a1 + a2 + a;
		t->value = sum;
	}
	Sum(TreeLeft(t), lvl, lvl_curr + 1);
	Sum(TreeRight(t), lvl, lvl_curr + 1);

}*/

void SostituisciSomma(Node* t) {

	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return;
	}

	int lvl = 0;

	GetTreeLvl(t, 0, &lvl);

	lvl--;

	Sum(t, &lvl, 0);
}