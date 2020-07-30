# Given this implementation of a function that constructs a pair

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

# Implement car and cdr which:
#  - car(pair) return the first element of the pair 
#  - cdr(pair) return the last element of the pair 

def car(pair):
    def f(x, y):
        return x
    return pair(f)

def cdr(pair):
    def f(x, y):
        return y
    return pair(f)

assert car(cons(3, 4)) == 3
assert cdr(cons(3, 4)) == 4


