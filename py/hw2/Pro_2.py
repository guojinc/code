def pro2():
    a = int(input("a: "))
    b = int(input("b: "))
    c = int(input("c: "))
    cal = a + b + c
    duce = a - b - c
    multi = a * b * c
    print("a + b + c: " + str(cal))
    print("a - b - c: " + str(duce))
    print("a * b * c: " + str(multi))
    try:
        div = a / b / c
    except ZeroDivisionError:
        print("Division by zero")
    else:
        print("a / b / c: " + str(round(div, 2)))#保留两位小数