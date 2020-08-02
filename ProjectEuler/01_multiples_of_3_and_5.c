/* Find the sum of all the multiples of 3 or 5 below 1000 */
/* Taken from https://projecteuler.net/problem=1 */

#include <stdio.h>

int main(void)
{
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i%3 == 0 || i%5 == 0) {
            sum += i;
        }
    }

    printf("%d\n", sum);
    
    return 0;
} 
