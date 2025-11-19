//
// Created by curse on 11/19/25.
//

#include "../../IntervalSkippingIterator.h"
#include <cstdio>

// empty range set - exception
int main() {
    try {
        RangeSet range_set;
        range_set.at(0);
        return 0;
    } catch (exception e) {
        return 1;
    }
}