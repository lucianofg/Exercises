# Find the sum of all the primes below two million
# Taken from https://projecteuler.net/problem=10

from math import sqrt

primes = [3]
number = 5

while number < 2_000_000:
    square_of_number = sqrt(number)
    for i in primes:
        if i > square_of_number:
            primes.append(number)
            number += 2
            break
        if number % i == 0:
            number += 2
            break

# Since we didn't count 2 as prime:
print(sum(primes) + 2)





