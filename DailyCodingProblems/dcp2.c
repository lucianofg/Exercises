/*
   Given an array of integers, return a new array such that each
   element at index i of the new array is the product of all the
   numbers in the original array except the one at i.
   */

#include <assert.h>
#include <stdio.h>
#include <string.h>

void solution(int *input, int *output, int n) {
    int res = 1;
    for (int i = 0; i < n; i++)
        res *= input[i];
    for (int i = 0; i < n; i++)
        output[i] = res / input[i];
}

/* What if you can't use division? :D */
void without_division(int *input, int *output, int n) {
    for (int i = 0; i < n; i++) {
        output[i] = 1;
        for (int j = 0; j < n; j++) {
            if (i != j)
                output[i] *= input[j];
        }
    }
}

int two_arrays_are_equal(int *arr1, int *arr2, int n) {
    for (int i = 0; i < n; i++) {
        if (arr1[i] != arr2[i])
            return 0;
    }
    return 1;
}

int main(void) {
    int input[]  = {1, 2, 3, 4, 5};
    int output[5] = {0};
    int expected_output[] = {120, 60, 40, 30, 24};

    solution(input, output, 5);
    assert(two_arrays_are_equal(output, expected_output, 5));

    without_division(input, output, 5);
    assert(two_arrays_are_equal(output, expected_output, 5));

    int input2[]  = {3, 2, 1};
    int output2[3] = {0};
    int expected_output2[] = {2, 3, 6};

    solution(input2, output2, 3);
    assert(two_arrays_are_equal(output2, expected_output2, 3));

    without_division(input2, output2, 3);
    assert(two_arrays_are_equal(output2, expected_output2, 3));

    return 0;
}
