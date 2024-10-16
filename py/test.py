i = 0
arr = []
@profile
def func():
    global i, arr
    while (i != 100000):
        i += 1
        arr.append(i)


if __name__ == '__main__':
    func()

    
