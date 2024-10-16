from math import sin, cos, pi, tan
import numpy as np
import pandas as pd

alpha = (2 / 180) * pi
theta = (110 / 180) * pi
H = 80
s = [-720 + i * 180 for i in range(9)]


def f(S):
    h = H - S * tan(alpha)
    ret = h * sin(theta / 2) * (1 / cos(theta / 2 + alpha) + 1 / cos( theta / 2 - alpha))
    return h, ret
def main():
    print("          ", end = ' ')
    for i in range(9):
        print(f"{s[i]:^10}", end = ' ')
    print()
    H_ = []
    length_ = []
    for i in range(9):
        h,length = f(s[i])
        H_.append(round(h,2))    
        length_.append(round(length,2))
    print("     H    ", end = ' ')
    for i in range(9):
        print(f"{H_[i]:^10}", end = ' ')
    print()
    print("  Length  ", end = ' ')
    for i in range(9):
        print(f"{length_[i]:^10}", end = ' ')
    N = []
    for i in range(8):
        n = (H_[i] / cos(theta / 2 -alpha) + H_[i + 1] / cos(theta / 2 + alpha) - 180 / (sin(theta / 2) * cos(alpha))) / (H_[i + 1] / cos(theta / 2 - alpha) + H_[i + 1] / cos(theta / 2 + alpha))
        n *= 100
        N.append(round(n, 2))
    print()
    print("     N    ", end = ' ')
    print(f"{'':-^10}", end = ' ')
    for i in range(8):
        print(f"{N[i]:^10}", end = ' ')
    res = np.zeros((4, 9))
    for i in range(9):
        res[0][i] = s[i]
        res[1][i] = H_[i]
        res[2][i] = length_[i]
        res[3][i] = N[i - 1] if i > 0 else -1
    df = pd.DataFrame(res)
    res = df.to_excel("result1.xlsx", sheet_name = 'Sheet1', index = False)
if __name__ == '__main__':
    main()