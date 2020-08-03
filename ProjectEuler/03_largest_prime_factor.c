/* What is the largest prime factor of 600851475143 */
/* Taken from https://projecteuler.net/problem=3 */

#include <stdio.h>

int main(void) {
    long number = 600851475143;
    long largest_prime_factor = 0;
    for (size_t i = 2; i <= number; i++) {
        if (number % i == 0) {
            if (i > largest_prime_factor) {
                largest_prime_factor = i;
            }

            number = number / i;
            i = 2;
        }
    }

    printf("Largest: %ld\n", largest_prime_factor);

    return 0;
}
