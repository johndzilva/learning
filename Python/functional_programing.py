# ---------------------------------------------
# (i)   Map()
# (ii)  Filter()
# (iii) Zip()
# (iv)  Reduce
# (v)   Super()
# (vi)  Dunder method
# (vii) Multiple inheritance
# ---------------------------------------------


# ---------------------------------------------
# Map
# ---------------------------------------------

def multiply_by2(item):
    return item ** 2

print(list(map(multiply_by2, [1, 2, 3])))

# Result:
#  [1, 4, 9]

# ---------------------------------------------
# Filter
# ---------------------------------------------

def only_odd(item):
    return item % 2 != 0

print(list(filter(only_odd, [1, 2, 3, 6, 4])))

# Result:
#  [1, 3]

# ---------------------------------------------
# Zip()
# ---------------------------------------------

first_name = ["John", "Charles", "Mike"]
last_name = ("Jenny", "Christy", "Monica")

print(list(zip(first_name, last_name)))

# Result:
#  [('John', 'Jenny'), ('Charles', 'Christy'), ('Mike', 'Monica')]

# ---------------------------------------------
# Reduce()
# ---------------------------------------------

from functools import reduce

my_list = [1, 2, 3, 4, 7]

def accumulator(acc, item):
    return acc + item

print(reduce(accumulator, my_list, 0))
print(reduce(accumulator, my_list, 10))

# Result:
#  17
#  27

# ---------------------------------------------
# Lambda
# ---------------------------------------------

# lambda param: action

my_list = [1, 2, 3, 4, 7]
print(list(map(lambda item: item * 2, my_list)))
print(list(filter(lambda item: item % 2 == 0, my_list)))
print(reduce(lambda acc, item: item ** 2, my_list, 0))

# Result:
#  [2, 4, 6, 8, 14]
#  [2, 4]
#  49

# ---------------------------------------------
# List comprehension
# ---------------------------------------------

my_list = [char for char in 'hello']
print(my_list)

my_list = [num ** 2 for num in range(0,10)]
print(my_list)

my_list = [num ** 2 for num in range(0,10) if num % 2 == 0]
print(my_list)

# Result:
# ['h', 'e', 'l', 'l', 'o']
# [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
# [0, 4, 16, 36, 64]

# ---------------------------------------------
# Dict comprehension
# ---------------------------------------------

simple_dict = {
    'a':1,
    'b':2
}

my_dict = {k:v**2 for k,v in simple_dict.items()}
print(my_dict)

# Result:
# {'a': 1, 'b': 4}
