//
// Created by curse on 11/19/25.
//

#include <cstdio>
#include "../../IntervalSkippingIterator.h"

// standard range function with no skipping
int main() {
    const RangeSet range_set;
    IntervalSkippingIterator it(0, 10, range_set);

    while (it.hasNext()) {
        printf("%d ", it.next());
    }

    printf("end\n");
}