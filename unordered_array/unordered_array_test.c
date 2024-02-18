#include "unordered_array.h"
#include <assert.h>

void test_unordered_array_set_create() {
    unordered_array_set set = unordered_array_set_create(5);

    assert(set.size == 0);
    assert(set.capacity == 5);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_create_from_array() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(set.size == 3);
    assert(set.capacity == 3);
    assert(set.data[0] == 1);
    assert(set.data[1] == 2);
    assert(set.data[2] == 3);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_in() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(unordered_array_set_in(set, 1) == 0);
    assert(unordered_array_set_in(set, 2) == 1);
    assert(unordered_array_set_in(set, 3) == 2);
    assert(unordered_array_set_in(set, 4) == set.size);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_isSubset() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set3 = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);

    assert(unordered_array_set_isSubset(set2, set1) == 1);
    assert(unordered_array_set_isSubset(set3, set1) == 0);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
}

void test_unordered_array_set_isEqual() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set3 = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);

    assert(unordered_array_set_isEqual(set1, set2) == 1);
    assert(unordered_array_set_isEqual(set1, set3) == 0);

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(set3);
}

void test_unordered_array_set_insert() {
    unordered_array_set set = unordered_array_set_create(5);

    unordered_array_set_insert(&set, 1);
    unordered_array_set_insert(&set, 2);
    unordered_array_set_insert(&set, 3);

    assert(set.size == 3);
    assert(set.data[0] == 1);
    assert(set.data[1] == 2);
    assert(set.data[2] == 3);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_deleteElement() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    unordered_array_set_deleteElement(&set, 2);

    assert(set.size == 2);
    assert(set.data[0] == 1);
    assert(set.data[1] == 3);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_union() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3}, 2);

    assert(unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1}, 1);

    assert(unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set universumSet = unordered_array_set_create_from_array((int[])
            {1, 2, 3, 4, 5},5);
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4, 5}, 2);

    assert(unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 4}, 2);

    assert(unordered_array_set_isEqual(resSet, expectedSet));

    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_print() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    unordered_array_set_print(set);

    unordered_array_set_delete(set);
}

void test_unordered_array_set_delete() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    unordered_array_set_delete(set);
}

void test_unordered_array() {
    test_unordered_array_set_create();
    test_unordered_array_set_create_from_array();
    test_unordered_array_set_in();
    test_unordered_array_set_isSubset();
    test_unordered_array_set_isEqual();
    test_unordered_array_set_insert();
    test_unordered_array_set_deleteElement();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_complement();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_print();
    test_unordered_array_set_delete();
}