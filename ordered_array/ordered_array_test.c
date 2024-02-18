#include "ordered_array.h"
#include "assert.h"

void test_ordered_array_set_create() {
    ordered_array_set set = ordered_array_set_create(5);

    assert(set.size == 0);
    assert(set.capacity == 5);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_create_from_array() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(set.size == 3);
    assert(set.capacity == 3);
    assert(set.data[0] == 1);
    assert(set.data[1] == 2);
    assert(set.data[2] == 3);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_in() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(ordered_array_set_in(&set, 1) == 0);
    assert(ordered_array_set_in(&set, 2) == 1);
    assert(ordered_array_set_in(&set, 3) == 2);
    assert(ordered_array_set_in(&set, 4) == set.size);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_isSubset() {
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set3 = ordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);

    assert(ordered_array_set_isSubset(&set2, 3));
    assert(!ordered_array_set_isSubset(&set3, 3));

    ordered_array_set_delete(set2);
    ordered_array_set_delete(set3);
}

void test_ordered_array_set_isEqual() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set3 = ordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);

    assert(ordered_array_set_isEqual(set1, set2));
    assert(!ordered_array_set_isEqual(set1, set3));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(set3);
}

void test_ordered_array_set_insert() {
    ordered_array_set set = ordered_array_set_create(5);

    ordered_array_set_insert(&set, 1);
    ordered_array_set_insert(&set, 2);
    ordered_array_set_insert(&set, 3);

    assert(set.size == 3);
    assert(set.data[0] == 1);
    assert(set.data[1] == 2);
    assert(set.data[2] == 3);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_deleteElement() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set_deleteElement(&set, 2);

    assert(set.size == 2);
    assert(set.data[0] == 1);
    assert(set.data[1] == 3);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_union() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet = ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_intersection() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    ordered_array_set resSet = ordered_array_set_intersection(set1, &set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {2, 3}, 2);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_difference() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    ordered_array_set resSet = ordered_array_set_difference(set1, &set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1}, 1);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 = ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    ordered_array_set resSet = ordered_array_set_symmetricDifference(&set1, set2);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {1, 4}, 2);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set1);
    ordered_array_set_delete(set2);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_complement() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet = ordered_array_set_complement(&set, universumSet);
    ordered_array_set expectedSet = ordered_array_set_create_from_array((int[]) {4, 5}, 2);

    assert(ordered_array_set_isEqual(resSet, expectedSet));

    ordered_array_set_delete(set);
    ordered_array_set_delete(universumSet);
    ordered_array_set_delete(resSet);
    ordered_array_set_delete(expectedSet);
}

void test_ordered_array_set_print() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set_print(set);

    ordered_array_set_delete(set);
}

void test_ordered_array_set_delete() {
    ordered_array_set set = ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);

    ordered_array_set_delete(set);
}

void test_ordered_array() {
    test_ordered_array_set_create();
    test_ordered_array_set_create_from_array();
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_isEqual();
    test_ordered_array_set_insert();
    test_ordered_array_set_deleteElement();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
    test_ordered_array_set_print();
    test_ordered_array_set_delete();
}