def pro3():
    a = int(input("a: "))
    b = int(input("b: "))
    c = int(input("c: "))
    cal = a + b + c
    duce = a - b - c
    multi = a * b * c
    # %表示
    print("a + b + c: %d" % (cal))
    print("a - b - c: %d" % (duce))
    print("a * b * c: %d" % (multi))
    try:
        div = a / b / c
    except ZeroDivisionError:
        print("Division by zero")
    else:
        print("a / b / c: %.2f" % (div))#保留两位小数
    #{}表示
    print("a + b + c: {}".format(cal))
    print("a - b - c: {}".format(duce))
    print("a * b * c: {}".format(multi))
    try:
        div = a / b / c
    except ZeroDivisionError:
        print("Division by zero")
    else:
        print("a / b / c: {:.2f}".format(div))#保留两位小数

