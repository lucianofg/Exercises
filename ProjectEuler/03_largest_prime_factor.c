/* What is the largest prime factor of the number: */
#define NUMBER 600851475143

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long *values;
    size_t size;
    size_t last;
} vect;

vect *vect_create(size_t size) {
    vect *v = (vect *)malloc(sizeof(vect));
    v->size = size;
    v->last = 0;
    v->values = malloc(sizeof(long) * v->size);
    return v;
}

void vect_append(vect *v, long value) {
    if (v->last >= v->size) {
        v->size *= 2;
        v->values = realloc(v->values, sizeof(long) * v->size);
    }

    v->values[v->last] = value;
    v->last += 1;
}

void vect_destroy(vect *v) {
    free(v->values);
    free(v);
}

int main(void) {
    long number = NUMBER;
    vect *prime_factors = vect_create(32);
    for (size_t i = 2; i <= number; i++) {
        if (number % i == 0) {
            vect_append(prime_factors, i);
            number = number / i;
            i = 2;
        }
    }

    long largest = prime_factors->values[0];
    for (size_t i = 1; i < prime_factors->last; i++) {
        if (prime_factors->values[i] > largest) {
            largest = prime_factors->values[i];
        }
    }

    printf("Largest: %ld\n", largest);
    vect_destroy(prime_factors);

    return 0;
}
