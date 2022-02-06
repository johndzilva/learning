##---------------------------------------------
# Generator function
##---------------------------------------------

def generator_fucntion(num):
    for i in range(num):
        yield i

g = generator_fucntion(10)
print(g)
print(next(g))
print(next(g))
print(next(g))
print(next(g))

# Results:
# <generator object generator_fucntion at 0x0000018BEDAE1D90>
# 0
# 1
# 2
# 3

# Underneath the hood 

class MyGen:
    current = 0
    def __init__(self, first, last):
        MyGen.current = first
        self.last = last
    
    def __iter__(self):
        return self

    def __next__(self):
        if self.current < self.last:
            MyGen.current += 1
            return MyGen.current
        raise StopIteration

for i in MyGen(22, 30):
    print(i)

# Results:
# 23
# 24
# 25
# 26
# 27
# 28
# 29
# 30

# Fibonacci series

def fibonacci(num):
    a = 0
    b = 1
    for i in range(num):
        yield a
        temp = a
        a = b
        b = temp + b
        
for i in fibonacci(10):
    print(i)

## Results:
# 0
# 1
# 1
# 2
# 3
# 5
# 8
# 13
# 21
# 34