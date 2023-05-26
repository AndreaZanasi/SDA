#include "elemtype.h"
#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {

	if (h == NULL || i > (int)h->size || h->data == NULL || i < 0) {
		return;
	}

    int l, r, small = i;
    bool isinl = true;
    bool isinr = true;

    l = HeapLeft(i);
    r = HeapRight(i);

    if (l < (int)h->size) {
        if (ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, i)) < 0) {
            small = l;
            isinl = true;
        }
    }
    else {
        isinl = false;
    }

    if (r < (int)h->size) {
        if (ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, i)) < 0) {
            small = r;
            isinr = true;
        }
    }
    else {
        isinr = false;
    }

    if (isinr == false && isinl == false) {
        return;
    }

    if (isinr != false && isinl != false) {
        if (ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, i)) > 0 && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, i)) > 0) {
            return;
        }
    }
   
    ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, small));

	HeapMinMoveDownRec(h, small);
}