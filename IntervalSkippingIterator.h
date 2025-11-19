//
// Created by curse on 11/11/25.
//

#ifndef MULTIPOLES_INTERVALSKIPPINGITERATOR_H
#define MULTIPOLES_INTERVALSKIPPINGITERATOR_H
#include <vector>
using namespace std;

/* Class for creating a vector of ordered ranges, represented as start (inclusive) and stop (exclusive) pairs
 * where no ranges overlap and all ranges are in ascending order, from the lowest index to the highest
 */

class RangeSet {
private:
    int size = 0;
    vector<pair<int,int>> ranges;
public:
    pair<int,int> at(int index);
    [[nodiscard]] int getSize() const;

    void reserve(int n);
    void addRange(int start, int stop);
};


/* Iterator that functions as standard range (start inclusive, stop exclusive)
 * but it leaves out all ranges found in excluded_ranges (start, stop pairs)
 * excluded_ranges is invalidated after construction
 */

// this is an incorrectly implemented iterator because I find the c++ implementation confusing
// but once I have the concept down I will fix it - TODO
class IntervalSkippingIterator {
private:
    int start;
    int stop;
    int current;
    int range_index;
    RangeSet excluded_ranges;
    void update();

public:
    // WARNING: constructor invalidates argument excluded_ranges
    IntervalSkippingIterator(int start, int stop, RangeSet excludedRanges);
    [[nodiscard]] bool hasNext() const;
    int next();
};


#endif //MULTIPOLES_INTERVALSKIPPINGITERATOR_H