//
// Created by curse on 11/19/25.
//

#include <stdexcept>

#include "../../IntervalSkippingIterator.h"

// completely empty iterator - trying to access next element
int main() {
    try {
        const RangeSet range_set;
        IntervalSkippingIterator it(0, 0, range_set);
        it.next();
    } catch (logic_error e) {
        return 1;
    }
}
