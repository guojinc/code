from math import *
from scipy.optimize import fsolve
import numpy as np
import pandas as pd

d = 1.65
head = 2.86
b = 0.45091174
a = b / (2 * pi)

R = lambda theta: b / (2 * pi) * theta
S = lambda theta: a / 2 * (theta * sqrt(1 + theta ** 2) + np.arcsinh(theta))
S0 = S(32 * pi)

def head_theta_t(theta_0, t):
    def f(x):
        return S(x) - S0 + t
    return fsolve(f, theta_0)    

def head_pre_theta(theta, init):
    def f(x):
        return 2 * a * a * theta * theta * (1 - np.cos(x)) + 2 * a * a * theta * x * (np.cos(x) - 1) + a * a * x * x - head * head
    return fsolve(f, init)

def pre_theta(theta, init):
    def f(x):
        return 2 * a * a * theta * theta * (1 - np.cos(x)) + 2 * a * a * theta * x * (np.cos(x) - 1) + a * a * x * x - d * d
    return fsolve(f, init)

def pre_v(theta0, theta1, v0):
    # k0 = (np.sin(theta0) + theta0 * np.cos(theta0)) / (np.cos(theta0) - theta0 * np.sin(theta0))
    # k1 = (np.sin(theta1) + theta1 * np.cos(theta1)) / (np.cos(theta1) - theta1 * np.sin(theta1))
    # a = (theta0 * np.cos(theta0) - theta1 * np.cos(theta1) + k0 * (theta0 * np.sin(theta0) - theta1 * np.sin(theta1)))
    # b = (theta0 * np.cos(theta0) - theta1 * np.cos(theta1) + k1 * (theta0 * np.sin(theta0) - theta1 * np.sin(theta1)))
    # s = sqrt((1 + theta1**2) / (1 + theta0**2))
    # c = abs((np.cos(theta0) - theta0 * np.sin(theta0)) / (np.cos(theta1) - theta1 * np.sin(theta1)))
    # ret = v0 * (a / b) * s * c
    
    
    # a = theta0 - theta1 * np.sin(theta0) * np.sin(theta1) - theta1 * np.cos(theta0) * np.cos(theta1) + theta0 * theta1 * (np.sin(theta0) * np.cos(theta1) - np.sin(theta1) * np.cos(theta0))
    # b = theta0 * np.sin(theta0) * np.sin(theta1) + theta0 * np.cos(theta0) * np.cos(theta1) - theta1 + theta0 * theta1 * (np.sin(theta0) * np.cos(theta1) - np.sin(theta1) * np.cos(theta0))
    # # print(a , b)
    # s = sqrt((1 + theta1**2) / (1 + theta0**2))
    # ret = abs(a / b) * s * v0
    # ret = np.round(ret, 6)

    k0 = (theta0 * np.sin(theta0) - theta1 * np.sin(theta1)) / (theta0 * np.cos(theta0) - theta1 * np.cos(theta1))
    k1 = (np.sin(theta0) + theta0 * np.cos(theta0)) / (np.cos(theta0) - theta0 * np.sin(theta0))
    k2 = (np.sin(theta1) + theta1 * np.cos(theta1)) / (np.cos(theta1) - theta1 * np.sin(theta1))
    
    a = v0 * np.cos(np.arctan(abs((k0 - k1) / (1 + k0 * k1))))
    b = np.cos(np.arctan(abs((k0 - k2) / (1 + k0 * k2))))

    ret = a / b
    ret = np.round(ret, 6)
    return ret
    pass

# def F(theta, x):
#     return 2 * a * a * theta * theta * (1 - np.cos(x)) + 2 * a * a * theta * x * (np.cos(x) - 1) + a * a * x * x - head * head

# for i in range(1, 200):
#     print(F(32 * pi, i / 100))

# for i in range(10):
#     print(head_theta_t(32 * pi, i) / pi)
def trans(r, theta):
    x = r * cos(theta)
    y = r * sin(theta)
    x = np.round(x, 6)
    y = np.round(y, 6)
    return x, y

def main():


    theta = 0
    v = 0
    row, col = (301, 448)
    result_pos = np.zeros((row, col))
    result_vel = np.zeros((row, int(col / 2)))
    #position
    for t in range(301):
        if t == 0:
            last_theta = 32 * pi

        else:
            last_theta = theta


        theta = head_theta_t(last_theta, t)
        x, y = trans(R(theta), theta)
        result_pos[t][0] = x
        result_pos[t][1] = y

        last_v = 1
        result_vel[t][0] = 1

        R_n = R(theta)
        init = head / R_n
        delta_theta = head_pre_theta(theta, init)
        next_theta = theta
        for n in range(1,224):
            
            last_v = pre_v(next_theta, next_theta + delta_theta, last_v)
            result_vel[t][n] = last_v

            next_theta += delta_theta
            R_n = R(next_theta)
            init = d / R_n
            delta_theta = pre_theta(next_theta, init)
            x, y = trans(R_n, next_theta)
            result_pos[t][2 * n] = x
            result_pos[t][2 * n + 1] = y
            pass
    

        

    
    
    result_pos = result_pos.transpose()
    row_name = []
    for i in range(1, 225):
        if i == 1:
            row_name.append("龙头x(m)")
            row_name.append("龙头y(m)")
            continue
        elif i == 223:
            row_name.append("龙尾x(m)")
            row_name.append("龙尾y(m)")
            continue
        elif i == 224:
            row_name.append("龙尾(后)x(m)")
            row_name.append("龙尾(后)y(m)")
            continue
        row_name.append("第" + str(i - 1) + "节龙身x(m)")
        row_name.append("第" + str(i - 1) + "节龙身y(m)")
    column_name = []

    for i in range(301):
        column_name.append(str(i) + 's')
    df_pos = pd.DataFrame(result_pos, index=row_name, columns=column_name)

    result_vel = result_vel.transpose()
    row_name = []
    column_name = []

    for i in range(1, 225):
        if i == 1:
            row_name.append("龙头(m/s)")
            continue
        elif i == 223:
            row_name.append("龙尾(m/s)")
            continue
        elif i == 224:
            row_name.append("龙尾(后)(m/s)")
            continue
        row_name.append("第" + str(i - 1) + "节龙身(m/s)")
    for i in range(301):
        column_name.append(str(i) + 's')
    
    df_vel = pd.DataFrame(result_vel, index=row_name, columns=column_name)

    with pd.ExcelWriter('result1.xlsx') as writer:
        df_pos.to_excel(writer, sheet_name='位置')
        df_vel.to_excel(writer, sheet_name='速度')
    
if __name__ == '__main__':
    main()
    pass