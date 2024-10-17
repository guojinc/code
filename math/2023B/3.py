from math import sin, cos, pi, tan, atan, sqrt
import numpy as np

alpha = (1.5 / 180) * pi
theta = (120 / 180) * pi
H = 110
L0 = 3.9 * 1852
H0 = H + tan(alpha) * L0 / 2
d11 = H0 * sqrt(3)
fac = 1 / cos(theta / 2 + alpha) + 1 / cos(theta / 2 - alpha)

def cal(List):
    ret = 0
    for item in List:
        ret += item
    return ret

def condi(H_, delta_x):
    return d11 + cal(delta_x) - delta_x[-1] + sin(theta / 2) * cos(alpha) * H_[-1] / cos(theta / 2 - alpha) >= L0
def main():
    H_ = []
    H1 = H0 - d11 * tan(alpha)
    H_.append(H1)
    delta_x = []
    delta_x1 = 0.9 * H1 * fac / (tan(alpha) * ( -0.1 * fac + 1 / (cos(theta / 2 + alpha))) + 1)
    delta_x.append(delta_x1)
    while True:
        H_.append(H_[-1] - delta_x[-1] * tan(alpha))
        delta_x.append(0.9 * H_[-1] * fac / (tan(alpha) * (0.1 * fac - 1 / (cos(theta / 2 - alpha))) + 1))
        if condi(H_, delta_x):
            break
    # for item in delta_x:
    #     print(item)
    print(len(delta_x) - 1)
    # print(cal(delta_x) - delta_x[-1])
if __name__ == '__main__':
    main()
    