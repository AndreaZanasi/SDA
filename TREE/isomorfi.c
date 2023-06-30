#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

void Lvl(const Node* t, size_t* lvlmax, size_t lvlcur) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (*lvlmax < lvlcur) {
		*lvlmax = lvlcur;
	}

	Lvl(TreeLeft(t), lvlmax, lvlcur + 1);
	Lvl(TreeRight(t), lvlmax, lvlcur + 1);
}

void CompareElements(const ElemType* e, const Node* t2, bool* is_iso, int lvl, int liv) {

	if (TreeIsEmpty(t2)) {
		return;
	}

	if (ElemCompare(e, TreeGetRootValue(t2)) == 0 && liv == lvl) {
		*is_iso = true;
		return;
	}
	else if(ElemCompare(e, TreeGetRootValue(t2)) != 0 && liv == lvl){
		if (*is_iso == true) {
			return;
		}
		*is_iso = false;
	}

	CompareElements(e, TreeLeft(t2), is_iso, lvl, liv + 1);
	CompareElements(e, TreeRight(t2), is_iso, lvl, liv + 1);
}

void IsomorfiRec(const Node* t1, const Node* t2, bool* is_iso, int lvl) {

	if (TreeIsEmpty(t1)) {
		return;
	}

	*is_iso = false;
	CompareElements(TreeGetRootValue(t1), t2, is_iso, lvl, 0);

	if (*is_iso == false) {
		return;
	}

	IsomorfiRec(TreeLeft(t1), t2, is_iso, lvl + 1);
	IsomorfiRec(TreeRight(t1), t2, is_iso, lvl + 1);
}

bool Isomorfi(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	else if (TreeIsEmpty(t1)) {
		return false;
	}
	else if (TreeIsEmpty(t2)) {
		return false;
	}

	size_t lvlt1 = 0, lvlt2 = 0;
	Lvl(t1, &lvlt1, 0);
	Lvl(t2, &lvlt2, 0);

	if (lvlt1 != lvlt2) {
		return false;
	}

	bool is_iso = true;

	IsomorfiRec(t1, t2, &is_iso, 0);

	return is_iso;
}
