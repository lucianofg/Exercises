/* By considering the terms in the Fibonacci sequence whose values do not
 * exceed four million, find the sum of the even-valued terms */
/* Taken from https://projecteuler.net/problem=3 */

#include <stdio.h>

#define SIZE 64
int fibonacci[SIZE] = {0, 1, 1};

int calc_fibonacci(int nth) {
    if (!fibonacci[nth])
        fibonacci[nth] = calc_fibonacci(nth - 1) + calc_fibonacci(nth - 2);
    return fibonacci[nth];
}

int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = 1; i < SIZE; i++) {
        int tmp = calc_fibonacci(i);
        if (tmp > 4000000)
            break;

        if (tmp % 2 != 0)
            sum += tmp;
    }

    printf("SUM: %d\n", sum);

    return 0;
}
