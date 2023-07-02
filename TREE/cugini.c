#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

void GetLvl(const Node* t, int lvl, int n, int* nodelvl) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (ElemCompare(&n, TreeGetRootValue(t)) == 0) {
		*nodelvl = lvl;
		return;
	}

	GetLvl(TreeLeft(t), lvl + 1, n, nodelvl);
	GetLvl(TreeRight(t), lvl + 1, n, nodelvl);
}

void SameFather(const Node* t, int a, int b, bool* is_same) {

	if (*is_same == true) {
		return;
	}

	if (TreeIsLeaf(t)) {
		return;
	}
	else if (TreeIsEmpty(TreeLeft(t))) {
		*is_same = false;
		return;
	}
	else if (TreeIsEmpty(TreeRight(t))) {
		*is_same = false;
		return;
	}

	if ((ElemCompare(TreeGetRootValue(TreeLeft(t)), &a) == 0 || ElemCompare(TreeGetRootValue(TreeRight(t)), &a) == 0) &&
		(ElemCompare(TreeGetRootValue(TreeLeft(t)), &b) == 0 || ElemCompare(TreeGetRootValue(TreeRight(t)), &b) == 0)) {
		*is_same = true;
		return;
	}

	SameFather(TreeLeft(t), a, b, is_same);
	SameFather(TreeRight(t), a, b, is_same);
}

bool Cugini(const Node* t, int a, int b) {

	if (TreeIsEmpty(t)) {
		return false;
	}

	int lvla = 0, lvlb = 0;
	GetLvl(t, 0, a, &lvla);
	GetLvl(t, 0, b, &lvlb);

	if (lvla != lvlb) {
		return false;
	}

	bool is_same = false;
	SameFather(t, a, b, &is_same);
	if (is_same == true) {
		return false;
	}
	
	return true;
}