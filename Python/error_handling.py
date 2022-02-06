##---------------------------------------------
# Error handling
##---------------------------------------------

def run():
    try:
        age = int(input('what is your age?'))
        10 / age
    except ValueError as err:
        print(f'please enter a number\n {err}')
    except ZeroDivisionError:
        print('please enter a non 0 value')
    else:
        print('thank you!')
        
run()