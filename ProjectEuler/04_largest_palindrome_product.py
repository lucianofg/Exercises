# Find the largest palindrome made from the product of two 3-digit numbers. 
# Problem taken from https://projecteuler.net/problem=4 

def is_palindrome(number: int):
    n = str(number)
    return n == n[::-1]

palindrome_set = set([])

for i in range(100, 999):
    for j in range(i, 999):
        number = i * j
        if is_palindrome(number):
            palindrome_set.add(number)

print(max(palindrome_set))

