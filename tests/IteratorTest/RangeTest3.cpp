//
// Created by curse on 11/19/25.
//

#include <cstdio>

#include "../../IntervalSkippingIterator.h"

// legal range set of 4 elements
int main() {
    RangeSet range_set;
    range_set.reserve(4);

    range_set.addRange(0, 1);
    range_set.addRange(1, 2);
    range_set.addRange(2, 8);
    range_set.addRange(25, 100);

    printf("%d\n", range_set.getSize());
}
