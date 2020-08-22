# Find the thirteen adjacent digits in the 1000-digit number that have the
# greatest product. What is the value of this product?
# A pythagorean triplet is:
#   a < b < c
#   a^2 + b^2 = c^2
# Problem taken from https://projecteuler.net/problem=8 

from math import sqrt

for a in range(1, 1000):
    for b in range(a + 1, 1000):
        c = sqrt(a**2 + b**2)
        if (a + b + c == 1000):
            print(int(a * b * c))
            exit()
