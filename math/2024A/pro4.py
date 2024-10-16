from math import *
import matplotlib.pyplot as plt
from simulate import *
import matplotlib.patches as patches
from matplotlib.animation import FuncAnimation
from scipy.optimize import fsolve
from scipy.integrate import quad
import numpy as np
# from sympy import *
import pandas as pd

cir_large = point(-0.7600091166555292, -1.3057264263462565, coordinate="dicar")
cir_small = point(1.7359324901810935, 2.448401974553666, coordinate="dicar")
radio = 1.5027088338945178
rotate = 3.021486841980652
C = 13.621244906821126

b = 1.7
d = 1.65
Head = 2.86
R_in = lambda theta: b / (2 * pi) * theta
R_out = lambda theta: b / (2 * pi) * (theta + pi)
theta_in = float((9 / 1.7) * pi)
theta_out = float((73 / 17) * pi)
Pin = point(R_in(theta_in), theta_in)
Pout = point(R_out(theta_out), theta_out)
Ptan = point(cir_large.x / 3 + 2 * cir_small.x / 3, cir_large.y / 3 + 2 * cir_small.y / 3)

B = b / (2 * pi)

S = lambda theta: B * (theta * sqrt(1 + theta ** 2) + np.arcsinh(theta))

def integrate_R(start, end):
    # theta = Symbol('theta')
    # integrand = sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * theta) ** 2)
    # return integrate(integrand, (theta, start, end))
    integrand = lambda theta: sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * theta) ** 2)
    return quad(integrand, start, end)[0]

def integrate_R_(start, end):
    # theta = Symbol('theta')
    # integrand = sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * (theta + pi)) ** 2)
    # return integrate(integrand, (theta, start, end))
    integrand = lambda theta: sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * (theta + pi)) ** 2)
    return quad(integrand, start, end)[0]

change_t_to_large_circle = integrate_R(theta_in, 32 * pi)
change_t_to_small_circle = change_t_to_large_circle + 2 * C / 3
change_t_to_reverse_line = change_t_to_small_circle + C / 3
# print(change_t_to_large_circle, change_t_to_small_circle, change_t_to_reverse_line)
def head_t(t:float) -> point:
    if t > change_t_to_large_circle and t < change_t_to_small_circle:
        S_more = t - change_t_to_large_circle
        alpha = S_more / radio
        beta = np.arctan((Pin.y - cir_large.y) / (Pin.x - cir_large.x))
        phi = beta - alpha
        return point(cir_large.x + radio * np.cos(phi), cir_large.y + radio * np.sin(phi))
    if t > change_t_to_small_circle and t < change_t_to_reverse_line:
        S_more = t - change_t_to_small_circle
        alpha = S_more / radio
        beta = np.arctan((Ptan.y - cir_small.y) / (Ptan.x - cir_small.x))
        phi = beta + alpha
        return point(cir_small.x + radio * np.cos(phi), cir_small.y + radio * np.sin(phi))
    def f(x):
        # x = Symbol('x')
        if t < change_t_to_large_circle: 
            # x, theta = sympy.symbols('x theta')
            # f = sympy.Function('f')(x)
            # g = sympy.Function('g')(sympy.sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * theta) ** 2) - t)
            return integrate_R(0, x) - integrate_R(0, 32 * pi) + t
        if t > change_t_to_reverse_line:
            return integrate_R_(theta_out, x) - t + change_t_to_reverse_line
    # x = Symbol('x')
    # ret = solve(f(x), x)
    # res = min([float(i) for i in ret if i > 0])
    res = fsolve(f, theta_in)[0]
    # res = solve(f(x), x)

    if t <= change_t_to_large_circle:
        return point(R_in(res), res)
    if t >= change_t_to_reverse_line:
        return point(R_out(res), res)

def head_pre_point(last : point, t):
    def f(x):
        l = x
        r = t
        mid = (l + r) / 2
        while abs(head_t(mid).distance(last) - d) < 1e-8:
            if head_t(mid).distance(last) < d:
                l = mid
            else:
                r = mid
            mid = (l + r) / 2
        return mid
    # init = t - Head
    # x = Symbol('x')
    # res = solve(f(x), x)
    # for i in res:
    #     if i > 0 and i < 2 * Head:
    #         return head_t(i), i
    res = f(t - Head * 1.5)
    # print(float(res))

    # res = solve(f(x), x)
    # res = min([float(i) for i in res if i > 0])
    # print(eval(res))
    return head_t(res), res



def pre_point(last : point, L):
    
    def f(x):
        r = L
        l = x
        mid = (r + l) / 2
        while abs(head_t(mid).distance(last) - d) < 1e-8 :
            if head_t(mid).distance(last) < d:
                l = mid
            else:
                r = mid
            mid = (r + l) / 2
        return mid
    # x = Symbol('x')
    # res = solve(f(x), x)
    # for i in res: 
    #     if i > 0 and i < 2 * d:
    #         return head_t(i), i
    # xi = 1
    # if L > change_t_to_large_circle and L < change_t_to_reverse_line:
    #     xi = 8
    xi = 2
    res = f(L - d * xi)
    # print(res)
    # res = solve(f(x), x)
    # res = min([float(i) for i in res if i > 0])
    # print(float(res))
    return head_t(res), res
    

def head_pre_v(theta0, theta1, v0=1):

    pass

def pre_v(theta0, theta1, v0):
    pass

def main():
    result = np.zeros((448, 201))
    result_v = np.zeros((224, 201))

    dt = 0.001
    Max_v = 0
    # for i in np.arange(23.01, 25, 0.001):
    for i in range(-100, 101):
        print(i)
        tmp = change_t_to_large_circle
        # print(tmp)
        T = tmp + i
        dT = T + dt
        head_point = head_t(T)
        head_point_ = head_t(dT)
        head_v = (dT - T) / dt
        head_v = np.round(head_v, 6)
        Max_v = max(Max_v, head_v)

        # print(head_point.r, head_point.theta)
        # print(head_point.x, head_point.y)

        result[0][i + 100] = np.round(head_point.x, 6)
        result[1][i + 100] = np.round(head_point.y, 6)
        result_v[0][i + 100] = head_v


        # print(head_v)
        p_point, SL = head_pre_point(head_point, T)


        p_point_ , SL_ = head_pre_point(head_point_, dT)
        p_v = (p_point_.distance(p_point)) / dt
        p_v = np.round(p_v, 6)
        
        Max_v = max(Max_v, p_v)

        result_v[1][i + 100] = p_v

        # print(p_v)
        # print(p_point.r, p_point.theta)


        result[2][i + 100] = np.round(p_point.x, 6)
        result[3][i + 100] = np.round(p_point.y, 6)
        # print(SL)
        la = SL
        la_ = SL_
        for num in range(2, 224):
            now_point, SL = pre_point(p_point, la)

            now_point_, SL_ = pre_point(p_point_, la_)
            n_v = (now_point_.distance(now_point)) / dt
            n_v = np.round(n_v, 6)

            
            if n_v > Max_v:
                Max_v = n_v
                print(Max_v)
                print(i)
                # exit(0)
            # n_v = (SL_ - SL) / dt

            result_v[num][i + 100] = n_v

            # print(n_v)
            # print(SL)
            # print(now_point.r, now_point.theta)

            result[num * 2][i + 100] = np.round(now_point.x, 6)
            result[num * 2 + 1][i + 100] = np.round(now_point.y, 6)

            p_point = now_point
            la = SL
            p_point_ = now_point_
            la_ = SL_
            # print(Max_v)
            # print("num" + str(num))

    # print(Max_v)
        # for _ in range(224):
        #     print(f'{result[i][_ * 2]:.10f} {result[i][_ * 2 + 1]:.10f}')
    # print(result)
    # for l in range(20):
    #     for i in range(224):
    #         if it[i] > 2:
    #             print()

    # result = result.transpose()
    row_name = []
    for i in range(1, 225):
        if i == 1:
            row_name.append("龙头x(m)")
            row_name.append("龙头y(m)")
            continue
        if i == 223:
            row_name.append("龙尾x(m)")
            row_name.append("龙尾y(m)")
            continue
        if i == 224:
            row_name.append("龙尾(后)x(m)")
            row_name.append("龙尾(后)y(m)")
            continue
        row_name.append("第" + str(i - 1) + "节龙身x(m)")
        row_name.append("第" + str(i - 1) + "节龙身y(m)")
    column_name = []
    for i in range(-100, 101):
        column_name.append(str(i) + 's')
    df_pos = pd.DataFrame(result, index=row_name, columns=column_name)
    # result_v = result_v.transpose()
    row_name = []
    for i in range(1, 225):
        if i == 1:
            row_name.append("龙头(m/s)")
            continue
        if i == 223:
            row_name.append("龙尾(m/s)")
            continue
        if i == 224:
            row_name.append("龙尾(后)(m/s)")
            continue
        row_name.append("第" + str(i) + "节龙身(m/s)")
    df_vel = pd.DataFrame(result_v, index=row_name, columns=column_name)
    with pd.ExcelWriter("result4.xlsx") as writer:
        df_pos.to_excel(writer, sheet_name="位置")
        df_vel.to_excel(writer, sheet_name="速度")

if __name__ == "__main__":
    main()