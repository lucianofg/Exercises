# What is the 10 001st prime number?
# Taken from https://projecteuler.net/problem=7

from math import sqrt

# I am omitting 2 to avoid unnecessary calculations, since I am only 
# analysing the odd numbers, this is also why is 10_000 instead 10_001
primes = [3]
number = 5

while len(primes) < 10_000:
    square_of_number = sqrt(number)
    for i in primes:
        if i > square_of_number:
            primes.append(number)
            number += 2
            break
        if number % i == 0:
            number += 2
            break
    else:
        primes.append(number)
        number += 2

print(primes[-1])
