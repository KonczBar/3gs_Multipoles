//
// Created by curse on 11/11/25.
//

#include "IntervalSkippingIterator.h"

#include <utility>
#include <stdexcept>
using namespace  std;

// indexes into internal vector
pair<int, int> RangeSet::at(const int index) {
    return ranges.at(index);
}

// returns size of internal vector
int RangeSet::getSize() const {
    return size;
}

// same as reserve function for vectors
void RangeSet::reserve(const int n) {
    this->ranges.reserve(n);
}

// adds a start, stop pair to the vector
// and checks correctness
void RangeSet::addRange(const int start, const int stop) {

    if (start > stop) {
        throw invalid_argument("Range start higher than stop");
    }

    if (!ranges.empty()) {
        if (ranges.back().second > start) {
            throw invalid_argument("Attempted to add out of order range");
        }
    }
    ranges.emplace_back(start,stop);
    size++;
}




// the heart of the iterator :)
void IntervalSkippingIterator::update() {
    // does nothing if already finished
    if (current >= stop) {
        return;
    }

    // basic increment
    current++;

    // potentially skips multiple intervals if their starts and stops line up
    while (current < stop && range_index < excluded_ranges.getSize()) {

        // skips one specific interval
        if (current >= excluded_ranges.at(range_index).first) {
            current = excluded_ranges.at(range_index).second;
            range_index++;
        } else {
            break;
        }
    }

}

// initialization and first update
IntervalSkippingIterator::IntervalSkippingIterator(const int start, const int stop, RangeSet excludedRanges) {
    if (stop < start) {
        throw invalid_argument("Start higher than stop");
    }

    this->start = start;
    this->stop = stop;
    this->current = start - 1; //sentinel value
    this->range_index = 0;
    this->excluded_ranges = std::move(excludedRanges);

    // sets proper index into ranges
    // because update() assumes it to be the next applicable range
    while (range_index < this->excluded_ranges.getSize()) {
        if (this->excluded_ranges.at(range_index).second <= start) {
            range_index++;
        } else {
            break;
        }
    }

    update();
}

// I did this like Java, I am not sorry
bool IntervalSkippingIterator::hasNext() const {
    return current < stop;
}

// I did this like Java, I am not sorry
int IntervalSkippingIterator::next() {
    if (!hasNext()) {
        throw logic_error("IntervalSkippingIterator: No next element");
    }

    const int tmp = current;
    update();
    return tmp;
}


