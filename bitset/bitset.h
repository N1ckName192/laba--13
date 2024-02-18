#ifndef BITSET_H
#define BITSET_H

#include <stdint.h>
#include <stdbool.h>

typedef struct bitset {
    uint32_t values; // множество
    uint32_t maxValue; // максимальный элемент универсума
} bitset;

bitset bitset_create(unsigned maxValue);

bool bitset_in(bitset set, unsigned int value);

bool bitset_isEqual(bitset set1, bitset set2);

bool bitset_isSubset(bitset subset, bitset set);

void bitset_insert(bitset *set, unsigned int value);

void bitset_deleteElement(bitset *set, unsigned int value);

bitset bitset_union(bitset set1, bitset set2);

bitset bitset_intersection(bitset set1, bitset set2);

bitset bitset_difference(bitset set1, bitset set2);

bitset bitset_symmetricDifference(bitset set1, bitset set2);

bitset bitset_complement(bitset set);

void bitset_print(bitset set);

#endif