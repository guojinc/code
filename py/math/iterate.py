import numpy as np

max_iter_time = 7
prime_number = 2.5
LSD : int = 6

def formula(x):
    x_k = np.arccos(1 / (1 + np.exp(2 * x)) - 1)
    return x_k

def formula_newton(x):
    f_e = np.exp(-2 * x)
    f = lambda x: np.cos(x) + 1 / (1 + f_e)
    df = lambda x: 2 * f_e / ((1 + f_e)**2) - np.sin(x)
    return x - f(x) / df(x)

def newton3(x):
    A = 5500
    P = 25000

    def Formula(x):
        par = (x + 1)**6
        return P * x * par / (par - 1) - A

    def formula(x):
        return P/A * x - 1 + (1 + x)**(-6)

    dt = 0.0000001
    df = (Formula(x) - Formula(x-dt)) / dt
    f = Formula(x)
    return x - f / df


def formula2(theta0):
    y = 1
    y0 = 2
    # v0 = 20
    v0 = 19.8
    x = 35
    g = 9.81
    par1 = 2 * (v0**2) * (np.cos(theta0)**2)
    return np.tan(theta0) * x - g / par1 *x *x + y0 - y


def compute_y(theta):
    y0 = 2
    # v0 = 20
    v0 = 19.8
    x = 35
    g = 9.81
    par1 = 2 * (v0**2) * (np.cos(theta)**2)
    return np.tan(theta) * x - g / par1 *x *x + y0
    
def dichotomy(formula, times = 11, L = 0, R = 1):
    l = L
    r = R
    cnt = 0
    while cnt <= times:
        mid = (l + r) / 2
        print(f"l: {l:.5g}, r: {r:.5g}, theta: {mid:.5g}")
        if formula(l) * formula(mid) >= 0:
            l = mid
        if formula(r) * formula(mid) >= 0:
            r = mid

        
        cnt += 1

def iterate(formula, times = max_iter_time, x0 = prime_number):
    x_0 = x0
    for _ in range(times):
        x_k = formula(x_0)
        x_0 = x_k
        print("x{} = {:.5g}".format(_ + 1, x_k))

def Steffensen(formula, times = max_iter_time, x0 = prime_number):
    x_0 = x0

    for _ in range(times):
        x = formula(x_0)
        x_k = x - (formula(x) - x)**2/(formula(formula(x)) - 2 * formula(x) + x)
        x_0 = x_k
        print("x{} = {:.6g}".format(_ + 1, x_k))
    
def Aitken(formula, times = max_iter_time, x0 = prime_number):
    iter_list = []
    
    x_0 = x0
    iter_list.append(x_0)

    for i in range(times):
        x = formula(x_0)
        x3 = x
        x_k = x3
        if len(iter_list) < 2: 
            iter_list.append(x3)
            x_0 = formula(x_0)
        else:
            x1 = iter_list[i-1]
            x2 = iter_list[i]
            x_k = x1 - (x2 - x1)**2/(x3 - 2 * x2 + x1)
            iter_list.append(x_k)
            x_0 = formula(x_0)
        print("x{} = {:.6g}".format(i + 1, x_k))

def main():
    # iterate(formula, max_iter_time, prime_number)
    # iterate(formula_newton)
    # Steffensen(formula)
    # Aitken(formula)
    iterate(newton3, x0=0.1)
    # dichotomy(formula2)
    # print(compute_y(0.47485))

    pass

if __name__ == '__main__':
    main()
