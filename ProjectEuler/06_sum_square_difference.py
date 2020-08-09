# Find the difference between the sum of the squares of the first one
# hundred natural numbers and the square of the sum
# Taken from https://projecteuler.net/problem=6

number = 100
sum_numbers = sum(range(1, number+1))
sum_squares = sum([x ** 2 for x in range(1, number+1)])

result = (sum_numbers ** 2) - sum_squares

print(result)
