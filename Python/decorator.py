##---------------------------------------------
# Decorator
##---------------------------------------------

def my_decorator(func):
    def wrapper_func():
        print("#########")
        func()
        print("#########")
    return wrapper_func

@my_decorator
def hello():
    print('hellloooo')

hello()
# or
my_decorator(hello)()

## Result:
# #########
# hellloooo
# #########


# Performance profiling
from time import time

def performance(fn):
    def wrapper(*args, **kwargs):
        t1 = time()
        result = fn(*args, **kwargs)
        t2 = time()
        print(f'time taken: {t2-t1}s')
        return result
    return wrapper

@performance
def longtime():
    for i in range(1, 1000):
        i ** 2

longtime()

## Result:
# time taken: 0.0009975433349609375s