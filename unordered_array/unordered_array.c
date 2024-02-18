#include "unordered_array.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

unordered_array_set unordered_array_set_create(size_t capacity) {
    unordered_array_set set;

    set.data = (int *) malloc(capacity * sizeof(int));
    set.size = 0;
    set.capacity = capacity;

    return set;
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set;

    set.data = (int *) malloc(size * sizeof(int));
    set.size = size;
    set.capacity = size;

    for (size_t i = 0; i < size; i++) {
        set.data[i] = a[i];
    }

    return set;
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    for (size_t i = 0; i < set.size; i++) {
        if (set.data[i] == value) {
            return i;
        }
    }

    return set.size;
}

bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++) {
        if (unordered_array_set_in(set, subset.data[i]) == set.size) {
            return false;
        }
    }

    return true;
}

bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size) {
        return false;
    }

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            return false;
        }
    }

    return true;
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    if (set->size >= set->capacity) {
        printf("Error: Set is full and cannot append more elements.\n");
        exit(1);
    }
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    unordered_array_set_isAbleAppend(set);

    set->data[set->size] = value;
    set->size++;
}

void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t index = unordered_array_set_in(*set, value);

    if (index < set->size) {
        set->data[index] = set->data[set->size - 1];
        set->size--;
    }
}

unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size + set2.size);

    for (size_t i = 0; i < set1.size; i++) {
        unordered_array_set_insert(&result, set1.data[i]);
    }

    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&result, set2.data[i]);
    }

    return result;
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) != set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }

    return result;
}

unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set result = unordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_in(set2, set1.data[i]) == set2.size) {
            unordered_array_set_insert(&result, set1.data[i]);
        }
    }

    return result;
}

unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set result = unordered_array_set_create(universumSet.size);

    for (size_t i = 0; i < universumSet.size; i++) {
        if (unordered_array_set_in(set, universumSet.data[i]) == set.size) {
            unordered_array_set_insert(&result, universumSet.data[i]);
        }
    }

    return result;
}

unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    return unordered_array_set_union(
            unordered_array_set_difference(set1, set2),
            unordered_array_set_difference(set2, set1)
    );
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{ ");

    size_t lastIndex = set.size - 1;

    for (size_t i = 0; i <= lastIndex; i++) {
        printf("%d", set.data[i]);

        if (i != lastIndex) {
            printf(", ");
        }
    }

    printf(" }\n");
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}