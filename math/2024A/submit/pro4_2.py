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

    integrand = lambda theta: sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * theta) ** 2)
    return quad(integrand, start, end)[0]

def integrate_R_(start, end):

    integrand = lambda theta: sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * (theta + pi)) ** 2)
    return quad(integrand, start, end)[0]

change_t_to_large_circle = integrate_R(theta_in, 32 * pi)
change_t_to_small_circle = change_t_to_large_circle + 2 * C / 3
change_t_to_reverse_line = change_t_to_small_circle + C / 3

def head_t(t:float) -> point:
    if t == change_t_to_small_circle:
        return Ptan
    if t > change_t_to_large_circle and t < change_t_to_small_circle:
        S_more = t - change_t_to_large_circle
        alpha = S_more * 0.5 / radio
        beta = np.arctan((Pin.y - cir_large.y) / (Pin.x - cir_large.x)) + pi
        phi = beta - alpha
        return point(cir_large.x + radio * 2 * np.cos(phi), cir_large.y + radio * 2 * np.sin(phi), coordinate='dicar')
    if t > change_t_to_small_circle and t < change_t_to_reverse_line:
        S_more = t - change_t_to_small_circle
        alpha = S_more / radio
        beta = np.arctan((Ptan.y - cir_small.y) / (Ptan.x - cir_small.x))
        phi = beta + alpha + pi
        return point(cir_small.x + radio * np.cos(phi), cir_small.y + radio * np.sin(phi),coordinate='dicar')
    def f(x):
        if t < change_t_to_large_circle: 
            return integrate_R(0, x) - integrate_R(0, 32 * pi) + t
        if t > change_t_to_reverse_line:
            return integrate_R_(theta_out, x) - t + change_t_to_reverse_line


    res = fsolve(f, theta_in, xtol=1e-10)[0]
    if t == change_t_to_large_circle:
        return Pin
    if t == change_t_to_reverse_line:
        return Pout
    if t < change_t_to_large_circle:
        return point(R_in(res), res)
    if t > change_t_to_reverse_line:
        return point(R_out(res), res)

def head_pre_point(last : point, t):
    def f(x):
        l = x
        r = t
        mid = (l + r) / 2
        while abs(head_t(mid).distance(last) - Head) > 1e-3:
            if head_t(mid).distance(last) < Head:
                r = mid
            else:
                l = mid
            mid = (l + r) / 2
        return mid

    res = f(t - Head * 1.2)

    return head_t(res), res



def pre_point(last : point, L):
    
    def f(x):
        r = L
        l = x
        mid = (r + l) / 2
        while abs(head_t(mid).distance(last) - d) > 1e-3 :
            if head_t(mid).distance(last) < d:
                r = mid
            else:
                l = mid
            mid = (r + l) / 2
        return mid

    xi = 1.5
    res = f(L - d * xi)

    return head_t(res), res
    

def head_pre_v(theta0, theta1, v0=1):

    pass

def pre_v(theta0, theta1, v0):
    pass

def main():
    result = np.zeros((448, 201))
    result_v = np.zeros((224, 201))

    dt = 1e-3
    Max_v = 0
    # for i in np.arange(23.01, 25, 0.001):
    
    def update(t, ax, text):
        nonlocal Max_v
        ax.clear()
        text.set_text('t = %.5f' % t)
        for i in np.arange(t, t + 0.1):
            print(i)
            tmp = change_t_to_large_circle

            T = tmp + i
            dT = T + dt
            head_point = head_t(T)
            head_point_ = head_t(dT)
            head_v = (dT - T) / dt
            # head_v = np.round(head_v, 6)
            Max_v = max(Max_v, head_v)
            # print(head_v)
            ax.plot(float(head_point.x), float(head_point.y), 'ro')

            # result[0][i + 100] = np.round(head_point.x, 6)
            # result[1][i + 100] = np.round(head_point.y, 6)
            # result_v[0][i + 100] = head_v


            p_point, SL = head_pre_point(head_point, T)

            # print(head_point.distance(p_point))
            p_point_ , SL_ = head_pre_point(head_point_, dT)
            p_v = (p_point_.distance(p_point)) / dt
            # p_v = (SL_ - SL) / dt
            # p_v = np.round(p_v, 6)
            ax.plot(float(p_point.x), float(p_point.y), 'ro', color = 'blue')
            # print(p_v)
            Max_v = max(Max_v, p_v)
            ax.plot([float(head_point.x), float(p_point.x)], [float(head_point.y), float(p_point.y)], 'r-', color='black')
            
            
            # result_v[1][i + 100] = np.round(p_v, 6)
            # result[2][i + 100] = np.round(p_point.x, 6)
            # result[3][i + 100] = np.round(p_point.y, 6)

            la = SL
            la_ = SL_
            for num in range(2, 224):
                now_point, SL = pre_point(p_point, la)
                ax.plot(float(now_point.x), float(now_point.y), 'ro', color = 'green')
                # print(p_point.distance(now_point))
                ax.plot([float(p_point.x), float(now_point.x)], [float(p_point.y), float(now_point.y)], 'r-', color='black')
                now_point_, SL_ = pre_point(p_point_, la_)
                n_v = (now_point_.distance(now_point)) / dt
                # n_v = (SL_ - SL) / dt
                # n_v = np.round(n_v, 6)

                # print(n_v)
                # if n_v > Max_v:
                #     Max_v = n_v
                #     print(Max_v)
                #     print(i)


                # result_v[num][i + 100] = np.round(n_v, 6)



                # result[num * 2][i + 100] = np.round(now_point.x, 6)
                # result[num * 2 + 1][i + 100] = np.round(now_point.y, 6)

                p_point = now_point
                la = SL
                p_point_ = now_point_
                la_ = SL_
        ax.set_xlim(-10,10)
        ax.set_ylim(-10,10)
        ax.set_aspect('equal', 'box')
        ax.add_artist(text)

    fig, ax = plt.subplots()
    text = ax.text(0, 0, '', fontsize=15)
    ani = FuncAnimation(fig, update, frames=np.arange(0, 101,0.1), fargs=(ax, text), interval=100)
    
    plt.show()

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
        row_name.append("第" + str(i - 1) + "节龙身(m/s)")
    df_vel = pd.DataFrame(result_v, index=row_name, columns=column_name)
    with pd.ExcelWriter("result4.xlsx") as writer:
        df_pos.to_excel(writer, sheet_name="位置")
        df_vel.to_excel(writer, sheet_name="速度")

if __name__ == "__main__":
    main()