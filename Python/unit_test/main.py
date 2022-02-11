def double_num(num=0):
    try:
        if num:
            return int(num) * 2
        else:
            return 'please enter number'
    except ValueError as err:
        return err