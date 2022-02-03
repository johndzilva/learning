##---------------------------------------------
# (i)  Conditional Logic
# (ii)  Ternary Operator
# (iii)  For Loop
# (iv)  Enumerate
# (v)  While Loop
# (vi)  Function
# (vii)  Docstring
# (viii)  Walrus operator
##---------------------------------------------


# ---------------------------------------------
# Conditional Logic
# ---------------------------------------------

from email import message


is_user = True
is_password = True

if is_user and is_password:
    print('Existing user')

elif is_user:
    print('wrong password')

else:
    print('No user data')

## Result: 
#  existing user

# ---------------------------------------------
# Terary operator
# ---------------------------------------------

is_friend = True
can_message = "allowed" if is_friend else "not allowed"
print(can_message)

## Result: 
#  allowed


# ---------------------------------------------
# For Loop
# ---------------------------------------------

for item in 'No money':
    print(item)

## Result: 
# N
# o
 
# m
# o
# n
# e
# y

for _ in range(0, 10):
    print('Hi')

# ---------------------------------------------
# Enumerate
# ---------------------------------------------

for i, char in enumerate('Hello'):
    print(i, char)

## Result: 
# 0 H
# 1 e
# 2 l
# 3 l
# 4 o

# ---------------------------------------------
# While loop
# ---------------------------------------------

i = 0
while i < 5:
    print(i)
    i+=1
else:
    print('done')

## Result: 
# 0
# 1
# 2
# 3
# 4
# done

i = 0
while i < 5:
    # pass is a palceholder if no operation
    pass


# ---------------------------------------------
# Function
# ---------------------------------------------

def greetings(name='pikachu', emoji='xD'):
    print(f'hellooo {name} {emoji}')

greetings()
greetings('Danny', ':)')

## Result: 
# hellooo pikachu xD
# hellooo Danny :)


# ---------------------------------------------
# Docstring
# ---------------------------------------------

def test(a):
    '''
    Info: sample function for showing docstring
    '''
    return a + a

help(test)
print(test.__doc__)
## Result:
# Help on function test in module __main__:

# test(a)
#     Info: sample function for showing docstring


# ---------------------------------------------
# *args, **kwargs (argument and keyword argument)
#    Rule: params, *args, default params, **kwargs
# ---------------------------------------------

def super_func(name, *args, i="hi", **kwargs):
    total = 0
    print(name)
    print(args)
    print(kwargs)
    for item in kwargs.values():
        total += item
    return sum(args) + total

print(super_func('Andrew', 1,2,3,4,5, num1=5, num2=10))

## Result:
# Andrew
# (1, 2, 3, 4, 5)
# {'num1': 5, 'num2': 10}
# 30


# ---------------------------------------------
# Walrus operator :=
# ---------------------------------------------

a = "pikachuuuuuu"

if (a := len(a) > 10):
    print(a)
