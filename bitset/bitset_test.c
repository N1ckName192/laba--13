#include "bitset.h"
#include <stdio.h>

void fill(bitset* set, const unsigned int* values, unsigned int size) {
    for (int i = 0; i < size; ++i) {
        bitset_insert(set, values[i]);
    }
}

void test_bitset() {
    unsigned int arrayA[] = {1, 3, 5, 7, 9};
    unsigned int arrayB[] = {2, 4, 6, 8, 10};

    unsigned int sizeA = sizeof(arrayA) / sizeof(arrayA[0]);
    unsigned int sizeB = sizeof(arrayB) / sizeof(arrayB[0]);

    bitset setA = bitset_create(arrayA[sizeA - 1]);
    bitset setB = bitset_create(arrayB[sizeB - 1]);

    fill(&setA, arrayA, sizeA);
    fill(&setB, arrayB, sizeB);

    printf("Set A: ");
    bitset_print(setA);

    printf("Set B: ");
    bitset_print(setB);

    printf("Union: ");
    bitset_print(bitset_union(setA, setB));

    printf("Intersection: ");
    bitset_print(bitset_intersection(setA, setB));

    printf("Difference (A - B): ");
    bitset_print(bitset_difference(setA, setB));

    printf("Symmetric Difference: ");
    bitset_print(bitset_symmetricDifference(setA, setB));

    printf("Complement of Set A: ");
    bitset_print(bitset_complement(setA));

    printf("Complement of Set B: ");
    bitset_print(bitset_complement(setB));
}