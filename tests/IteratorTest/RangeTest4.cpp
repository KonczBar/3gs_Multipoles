//
// Created by curse on 11/19/25.
//

#include <stdexcept>

#include "../../IntervalSkippingIterator.h"

// illegal range set: out of order
int main() {
    try {
        RangeSet range_set;
        range_set.addRange(5, 10);
        range_set.addRange(1, 2);

        return 0;
    } catch (invalid_argument e) {
        return 1;
    }


}
