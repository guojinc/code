from math import *
from scipy.optimize import fsolve
import numpy as np
import pandas as pd
import time
from pro1 import *
from simulate import *
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from matplotlib.animation import FuncAnimation

def step(t, lis, last_theta, ax, text):

    theta = head_theta_t(last_theta, t)
    last_theta = theta
    init = head / R(theta)
    theta_ = last_theta + head_pre_theta(theta, init)


    R_n = R(theta_)
    head_r = rectangle(point(R(theta), theta), point(R_n, theta_))
    # print(head_r)
    lis[0] = head_r
    for i in range(1, 223):
        delta_theta = pre_theta(theta_, d / R_n)
        rec = rectangle(point(R_n, theta_), point(R(theta_ + delta_theta), theta_ + delta_theta))
        lis[i] = rec
        R_n = R(theta_ + delta_theta)
        # print("0" + lis[i].__str__())
        # print(rec)
        theta_ += delta_theta


    ax.clear()

    text.set_text('t = %.5f' % t)

    a = 0.55 / (2 * pi)
    theta_max = 32 * pi
    num_points = 1000
    theta = np.linspace(0, theta_max, num_points)
    r = a * theta
    x = r * np.cos(theta)
    y = r * np.sin(theta)
    ax.plot(x, y, 'b')

    for it in lis:
        if it.last.r >= 8.8:
            continue
        rect_points = np.array([[float(it.vertical_a.x), float(it.vertical_a.y)],
                                [float(it.vertical_b.x), float(it.vertical_b.y)],
                                [float(it.vertical_c.x), float(it.vertical_c.y)],
                                [float(it.vertical_d.x), float(it.vertical_d.y)]])
        polygon = patches.Polygon(rect_points, closed=True, edgecolor='r', facecolor='none', linewidth=1)
        ax.add_patch(polygon)
        ax.plot(float(it.last.x), float(it.last.y), 'ro')
        ax.plot(float(it.Next.x), float(it.Next.y), 'ro')

    # print(lis[0])
    ax.set_xlim(-10,10)
    ax.set_ylim(-10,10)
    ax.set_aspect('equal', 'box')
    ax.add_artist(text)



    for i in range(len(lis)):
        if lis[i].last.r >= 5:
            continue
        r = min(len(lis), i + 15)
        for j in range(i + 2, r):
            if (lis[i].iscollision(lis[j])):
                print(t)
                print(i)
                print(j)
                print(lis[i])
                print(lis[j])
                time.sleep(10)
                exit(0)

    
def main():
    lis = [None] * 223
    last_theta = 32 * pi

    fig = plt.figure(figsize=(8, 8))
    ax = fig.add_subplot(1,1,1)
    text = ax.text(0.02, 0.95, '', transform=ax.transAxes)
    ani = FuncAnimation(fig, step, fargs=(lis, last_theta, ax, text), frames=np.arange(400, 430, 0.1), interval=10)

    plt.show()


    pass



if __name__ == '__main__':
    main()