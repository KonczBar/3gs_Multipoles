//
// Created by curse on 11/19/25.
//

#include <cstdio>

#include "../../IntervalSkippingIterator.h"

// range set covers all from start to stop
// has no next element
int main() {
    RangeSet range_set;
    range_set.addRange(1, 10);

    IntervalSkippingIterator it(5, 6, range_set);

    printf("%d\n", it.hasNext());
}
