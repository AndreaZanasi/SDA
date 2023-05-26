#include "tree.h"
#include "elemtype.h"
#include <stdlib.h>
#include <stdio.h>

void GetMaxLvl(const Node* t, int* maxlvl, int lvl) {

	if (*maxlvl < lvl) {
		*maxlvl = lvl;
	}

	if (!TreeIsEmpty(TreeLeft(t))) {
		GetMaxLvl(TreeLeft(t), maxlvl, lvl + 1);
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		GetMaxLvl(TreeRight(t), maxlvl, lvl + 1);
	}
}

void LevelOrderRec(const Node* t, int lvl, int currlvl) {

	if (lvl == currlvl) {
		ElemWriteStdout(TreeGetRootValue(t));
		printf(" ");
	}

	if (!TreeIsEmpty(TreeLeft(t))) {
		LevelOrderRec(TreeLeft(t), lvl, currlvl + 1);
	}
	if (!TreeIsEmpty(TreeRight(t))) {
		LevelOrderRec(TreeRight(t), lvl, currlvl + 1);
	}

}

void LevelOrder(const Node* t) {

	if (TreeIsEmpty(t)) {
		return;
	}

	int maxlvl = 0;
	GetMaxLvl(t, &maxlvl, 0);
	int lvl = 0;

	while (maxlvl >= 0) {
		LevelOrderRec(t, lvl, 0);
		lvl++;
		maxlvl--;
	}
}