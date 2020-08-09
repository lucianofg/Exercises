/* Find the difference between the sum of the squares of the first one
 * hundred natural numbers and the square of the sum */
/* Taken from https://projecteuler.net/problem=6 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int sum = 0;
    int sum_of_the_squares = 0;

    for (int i = 1; i <= 100; i++) {
        sum += i;
        sum_of_the_squares += i * i;
    }

    int square_of_sum = sum * sum;
    printf("%d\n", square_of_sum - sum_of_the_squares);

    return 0;
}
