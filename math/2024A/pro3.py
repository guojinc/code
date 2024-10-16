from math import *
import matplotlib.pyplot as plt
from simulate import *
import matplotlib.patches as patches
from matplotlib.animation import FuncAnimation
from scipy.optimize import fsolve
from scipy.integrate import quad
import numpy as np
import pandas as pd

d = 1.65
head = 2.86
b = 1.7
a = b / (2 * pi)

R_in = lambda theta: b / (2 * pi) * theta
R_out = lambda theta: b / (2 * pi) * (theta + pi)

S = lambda theta: a / 2 * (theta * sqrt(1 + theta ** 2) + np.arcsinh(theta))

end_ = 9 * pi / 1.7 

S_in_end = S(end_)

S_out_begin = S(end_)
S_out_end = S(32 * pi)

def integrate_R(start, end):
    integrand = lambda theta: sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * theta) ** 2)
    return quad(integrand, start, end)[0]

def integrate_R_(start, end):
    integrand = lambda theta: sqrt((b / (2 * pi)) ** 2 + (b / (2 * pi) * (theta + pi)) ** 2)
    return quad(integrand, start, end)[0]


S_in_begin = S(32 * pi)

end_ = 9 * pi / 1.7


def head_in_theta_t(theta_0, t):
    def f(x):
        return S(x) - S_in_begin + t
    return fsolve(f, theta_0)   

def head_out_theta_t(theta_0, t):
    def f(x):
        return S_out_begin - integrate_R_(end_, x) + t








def head_in_pre_theta(theta, init):
    def f(x):
        return 2 * a * a * theta * theta * (1 - np.cos(x)) + 2 * a * a * theta * x * (np.cos(x) - 1) + a * a * x * x - head * head
    return fsolve(f, init)

def pre_in_theta(theta, init):
    def f(x):
        return 2 * a * a * theta * theta * (1 - np.cos(x)) + 2 * a * a * theta * x * (np.cos(x) - 1) + a * a * x * x - d * d
    return fsolve(f, init)

def pre_in_v(theta0, theta1, v0):
    k0 = (theta0 * np.sin(theta0) - theta1 * np.sin(theta1)) / (theta0 * np.cos(theta0) - theta1 * np.cos(theta1))
    k1 = (np.sin(theta0) + theta0 * np.cos(theta0)) / (np.cos(theta0) - theta0 * np.sin(theta0))
    k2 = (np.sin(theta1) + theta1 * np.cos(theta1)) / (np.cos(theta1) - theta1 * np.sin(theta1))
    
    a = v0 * np.cos(np.arctan(abs((k0 - k1) / (1 + k0 * k1))))
    b = np.cos(np.arctan(abs((k0 - k2) / (1 + k0 * k2))))

    ret = a / b
    ret = np.round(ret, 6)
    return ret

def main():
    global S_out_end, S_out_begin, S_in_end

    cir_l = point(1, 1, "dicar")
    cir_r = point(1, 1, "dicar")
    big_round = 0
    small_round = 0
    MIN = 10000
    PR = 0
    I = 0
    O = 0
    for i in np.arange(0, 0.8 * pi, 0.0001):
        In = end_ - i
        
        S_in_end = S(In)

        S_out_begin = S(In)
        S_out_end = S(32 * pi)
        change_t = integrate_R(In, 32 * pi)
        # for j in np.arange(0, 0.8 * pi, 0.01):
        for j in range(1):
            # End = 73 / 17 * pi - j
            End = In - pi 
            alpha0 = np.arctan(-(a * cos(In) - a * In * sin(In)) / (a*sin(In) + a * In * cos(In))) 
            beta0 = np.arctan( - (a * cos(End) - a * End * sin(End) - pi * a * sin(End)) / (a * sin(End) + a * End * cos(End) + pi * a * cos(End)))
            alpha = alpha0
            beta = beta0 + pi
            
            IN = point(R_in(In), In)
            OUT = point(R_out(End), End)
            
            # print(str(IN.x) + " " + str(IN.y))
            # print(str(OUT.x) + " " + str(OUT.y))
            
            # print(str(IN.r) + " " + str(IN.theta))
            # print(str(OUT.r) + " " + str(OUT.theta))
            A = OUT.x - IN.x
            B = OUT.y - IN.y
            


            # sqt = sqrt((A * cos(alpha) + B * sin(alpha))**2 + (A * cos(beta)/2 + B * sin(beta)/2)**2 + (A * sin(alpha) - B * cos(alpha)) * (A * sin(beta) - B * cos(beta)) + A**2 + B**2)
            # tmp_a = A * (cos(beta)/2 - cos(alpha)) + B * (sin(beta)/2 - sin(alpha)) + sqt
            # # tmp_b = A * (cos(beta)/2 - cos(alpha)) + B * (sin(beta)/2 - sin(alpha)) - sqt
            # tmp_un = 2 * (1 + cos(alpha) * cos(beta) + sin(alpha) * sin(beta))
            # if tmp_un == 0:
            #     continue



            # R = tmp_a / tmp_un
            
            R = 0.25 * (A**2 + B**2) / (A * (cos(alpha) - 0.5 * cos(beta)) + B * (sin(alpha) - 0.5 * sin(beta)))

            if R < 1.5:
                continue
            # R_2 = tmp_b / tmp_un
            # print(R)
            # print(R_2)
            # print()
            cir_lar = point(IN.x + 2 * R * cos(alpha), IN.y + 2 * R * sin(alpha), "dicar")
            cir_sma = point(OUT.x + R * cos(beta), OUT.y + R * sin(beta), "dicar")



            S1 = 2 * R * np.arccos(((IN.x - cir_lar.x) * (cir_sma.x - cir_lar.x) + (IN.y - cir_lar.y) * (cir_sma.y - cir_lar.y)) / (6*R*R)) + R * np.arccos(((OUT.x - cir_sma.x) * (cir_lar.x - cir_sma.x) + (OUT.y - cir_sma.y) * (cir_lar.y - cir_sma.y)) / (3*R*R))
            S2 = integrate_R(In, (90 / 17) * pi) + integrate_R_(End + pi, (90 / 17) * pi)
            # print(((IN.x - cir_lar.x) * (cir_sma.x - cir_lar.x) + (IN.y - cir_lar.y) * (cir_sma.y - cir_lar.y)))
            # if str(S1) == "nan":
            #     print(str(In)+ " " + str(End))

            # print("S1:" + str(S1))
            # print("S2:" + str(S2))

            # print(S1 + S2)
            Big_round = np.arccos(((IN.x - cir_lar.x) * (cir_sma.x - cir_lar.x) + (IN.y - cir_lar.y) * (cir_sma.y - cir_lar.y)) / (6*R*R))
            Small_round = np.arccos(((OUT.x - cir_sma.x) * (cir_lar.x - cir_sma.x) + (OUT.y - cir_sma.y) * (cir_lar.y - cir_sma.y)) / (3*R*R))
            if Big_round + Small_round < 1 * pi:
                continue
            if MIN > S1 + S2:
                MIN = S1 + S2
                I = In
                O = End
                PR = R
                big_round = np.arccos(((IN.x - cir_lar.x) * (cir_sma.x - cir_lar.x) + (IN.y - cir_lar.y) * (cir_sma.y - cir_lar.y)) / (6*R*R))
                small_round = np.arccos(((OUT.x - cir_sma.x) * (cir_lar.x - cir_sma.x) + (OUT.y - cir_sma.y) * (cir_lar.y - cir_sma.y)) / (3*R*R))
                cir_l = cir_lar
                cir_r = cir_sma                


    print(MIN)        
    # print(I)
    # print(R_in(I))
    # print()
    # print(O)
    # print(R_out(O))
    # print()
    # print(PR)
    # print()
    # print(big_round)
    # print(small_round)
    # print()
    # print(cir_l.x)
    # print(cir_l.y)
    # print()
    # print(cir_r.x)
    # print(cir_r.y)

            



                
         


    # radio = R_in(end_)
    # radio_be = radio / 3 * 2
    # radio_en = radio / 2
    # begin = point(radio, end_)
    # end = point(radio, end_ + pi)    
    # cir_begin = point(radio / 6, end_)
    # cir_end = point(radio / 3, end_ + pi)
    
    
    pass

if __name__ == '__main__':
    main()


