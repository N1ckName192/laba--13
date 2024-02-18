#include "bitset.h"
#include "../util.h"
#include <stdio.h>

bitset bitset_create(unsigned maxValue) {
    return (bitset) {0, maxValue};
}

bool bitset_in(bitset set, unsigned int value) {
    return (value <= set.maxValue) && (set.values & (1 << value));
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return (set1.values == set2.values) && (set1.maxValue == set2.maxValue);
}

bool bitset_isSubset(bitset subset, bitset set) {
    return ((subset.values & set.values) == subset.values) && (subset.maxValue <= set.maxValue);
}

void bitset_insert(bitset *set, unsigned int value) {
    if (value <= set->maxValue) {
        set->values |= (1 << value);
    }
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    if (value <= set->maxValue) {
        set->values &= ~(1 << value);
    }
}

bitset bitset_union(bitset set1, bitset set2) {
    return (bitset) {
        set1.values | set2.values,
        max(set1.maxValue, set2.maxValue)
    };
}

bitset bitset_intersection(bitset set1, bitset set2) {
    return (bitset) {
        set1.values & set2.values,
        max(set1.maxValue, set2.maxValue)
    };
}

bitset bitset_difference(bitset set1, bitset set2) {
    return (bitset) {
        set1.values & ~set2.values,
        max(set1.maxValue, set2.maxValue)
    };
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    return (bitset) {
        set1.values ^ set2.values,
        max(set1.maxValue, set2.maxValue)
    };
}

bitset bitset_complement(bitset set) {
    return (bitset) {
        ~set.values & ((1 << (set.maxValue + 1)) - 1),
        set.maxValue
    };
}

void bitset_print(bitset set) {
    printf("{");

    for (unsigned int i = 0; i <= set.maxValue; i++) {
        if (bitset_in(set, i)) {
            printf(" %u", i);
        }
    }

    printf(" }\n");
}