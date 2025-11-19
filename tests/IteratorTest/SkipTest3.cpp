//
// Created by curse on 11/19/25.
//

#include <cstdio>

#include "../../IntervalSkippingIterator.h"
// "average" case of skipping iterator
// has a range set that has ranges below the start value and after stop value
int main() {
    RangeSet range_set;
    range_set.addRange(0, 10);
    range_set.addRange(10, 11);
    range_set.addRange(11, 11);
    range_set.addRange(11, 12);
    range_set.addRange(15, 16);
    range_set.addRange(18, 20);
    range_set.addRange(100, 200);

    IntervalSkippingIterator it(11, 21, range_set);

    // should be "12 13 14 16 17 20" - i = 6
    int i = 0;
    while (it.hasNext()) {
        it.next();
        i++;
    }

    printf("%d\n", i);
}