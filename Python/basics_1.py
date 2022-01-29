##---------------------------------------------
# (i)   Augumented assignment operator / short hand
# (ii)  Formatted string
# (iii) String Indexes
# (iv)  List
# (v)   List Methods
         # append
         # insert
         # extend
         # pop
         # index
         # count
         # sort
         # reverse
# (vi)  List Unpack ing
# (vii) Dictionary
# (viii) Tuple
# (ix)  Set
##---------------------------------------------


# ---------------------------------------------
# Augumented assignment operator / short hand
# ---------------------------------------------

some_value = 10
some_value += 5

print(some_value)

## Result:
#  15

# ---------------------------------------------
# Formatted string
# ---------------------------------------------

print("Hello {}, your balance is {}.".format("Cindy", 50))
print("Hello {1}, your balance is {0}.".format(50, "Cindy"))
print("Hello {name}, your balance is {amount}.".format(name="Cindy", amount=50))
print("Hello {0}, your balance is {amount}.".format("Cindy", amount=50))

## Result: 
#  Hello Cindy, your balance is 50.
#  Hello Cindy, your balance is 50.
#  Hello Cindy, your balance is 50.
#  Hello Cindy, your balance is 50.


# ---------------------------------------------
# String Indexes
# ---------------------------------------------

random_string = '0123456789'

# [start:stop:stepover]
print(random_string[0:len(random_string)])
print(random_string[0:8:2])
print(random_string[::1])
print(random_string[::-1])
print(random_string[::-2])

## Result:
#  0123456789
#  0246
#  0123456789
#  9876543210
#  97531

# ---------------------------------------------
# List
# ---------------------------------------------

new_list = ['a', 'b', 'c']
print(new_list[1])
print(new_list[1:3])
new_list[0] = 'z'
print(new_list)

my_list = [1,2,3]
bonus = my_list + [5]
my_list[0] = 'z'
print(my_list)
print(bonus)

## Result:
#  b
#  ['b', 'c']
#  ['z', 'b', 'c']
#  ['z', 2, 3]
#  [1, 2, 3, 5]

# ---------------------------------------------
# List Methods
# ---------------------------------------------

basket = [1, 2, 3, 4, 5]

#adding
basket.append(6)
print(basket)
## Result
#  [1, 2, 3, 4, 5, 6]

#insert
basket.insert(5, 10)
print(basket)
## Result
#  [1, 2, 3, 4, 5, 10, 6]

#extend - is an iterator
basket.extend([20, 30])
print(basket)
## Result
#  [1, 2, 3, 4, 5, 10, 6, 20, 30]

#pop - remove with index
basket.pop(0)
print(basket)
## Result
#  [2, 3, 4, 5, 10, 6, 20, 30] 

#pop - remove with value
basket.remove(6)
print(basket)
## Result
# [2, 3, 4, 5, 10, 20, 30]

new_basket = ['a', 'b', 'c', 'd', 'e', 'd']
#index
print(new_basket.index('d'))
print(new_basket.index('d', 0, 3))
## Result
#  3
#  Error: 'd' is not in the list

#count
print(new_basket.count('d'))
## Result
#  2

#sort
print(sorted(new_basket))
new_basket.sort()
print(new_basket)
## Result
#  ['a', 'b', 'c', 'd', 'd', 'e']
#  ['a', 'b', 'c', 'd', 'd', 'e']

#reverse
print(new_basket[::-1])
new_basket.reverse()
print(new_basket)
## Result
#  ['e', 'd', 'd', 'c', 'b', 'a']
#  ['e', 'd', 'd', 'c', 'b', 'a']


# ---------------------------------------------
# List Unpacking
# ---------------------------------------------

a, b, c, *others, d = [1, 2, 3, 4, 5, 6, 7, 8, 9]
print(a)
print(b)
print(c)
print(others)
print(d)

## Result
#  1
#  2
#  3
#  [4, 5, 6, 7, 8]
#  9


# ---------------------------------------------
# Dictionary - unordered key-value pair
# ---------------------------------------------

user = {
    'age': 22,
    'username': 'Shogun',
    'weapons': ['katana', 'shuriken'],
    'is_active': True,
    'clan': 'Japan'
}

print(user.keys())
## Result:
#  dict_keys(['age', 'username', 'weapons', 'is_active', 'clan'])

user['weapons'].append('shield')
print(user)
## Result: 
# {'age': 22, 'username': 'Shogun', 'weapons': ['katana', 'shuriken', 'shield'], 'is_active': True, 'clan': 'Japan'}

user.update({'is_banned': False}) 
print(user)
## Result: 
# {'age': 22, 'username': 'Shogun', 'weapons': ['katana', 'shuriken', 'shield'], 'is_active': True, 'clan': 'Japan', 'is_banned': False}

user2 = user.copy()
user2.update({'age': 100, 'username': 'Timbo'})
print(user2)
## Result: 
# {'age': 100, 'username': 'Timbo', 'weapons': ['katana', 'shuriken', 'shield'], 'is_active': True, 'clan': 'Japan', 'is_banned': True}


# ---------------------------------------------
# Tuple - For a constant list
# ---------------------------------------------

my_tuple = (1, 2, 3, 4, 5)
print(my_tuple[1:2])
## Result: 
#  (2,)

print(my_tuple[1:3])
## Result: 
#  (2,3)


# ---------------------------------------------
# Set - Unordered collection of unique objects
#       - difference()
#       - difference_update()
#       - intersection()
#       - disjoint()
#       - issubset()
#       - issuperset()
#       - union()
# ---------------------------------------------

my_list = [1, 2, 3, 4, 4, 4, 5]
print(set(my_list))
## Result: 
#  {1, 2, 3, 4, 5}

my_set = {1, 2, 3, 4, 5}
next_set = {4, 5, 6, 7, 8, 9}

print(my_set.difference(next_set))
## Result: 
#  {1, 2, 3}