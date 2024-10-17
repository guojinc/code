
from math import sin, cos, pi, tan, atan
import numpy as np
import pandas as pd

alpha = (2 / 180) * pi
theta = (110 / 180) * pi
beta = [i * 45 for i in range(8)]
s = [ i * 0.4 * 1852 for i in range(8) ]


def f(Beta, S):
    h = 110 + S * tan(alpha) * cos(Beta)
    phi = atan(tan(alpha) * sin(Beta))
    ret = h * sin(theta / 2) * (1 / (cos(phi + (theta / 2))) + 1 / (cos(phi - (theta / 2))))
    return ret if ret > 0 else 0
    # return ret
def main():
    print("          ", end = ' ')
    res = np.zeros((8, 8))
    for i in range(8):
        print(f"{round(s[i] / 1852, 2):^10}", end = ' ')
    print()
    for i in range(8):
        print(f"{round(beta[i], 2):^10}", end = ' ')
        for j in range(8):
            print(f"{round(f((180 - abs(beta[i] - 180)) / 180 * pi, s[j]) , 2):^10}", end = ' ')
            res[i][j] = round(f((180 - abs(beta[i] - 180)) / 180 * pi, s[j]), 2)  
        print()  

    df = pd.DataFrame(res)
    res = df.to_excel("result2.xlsx", sheet_name = 'Sheet1', index = False)
if __name__ == '__main__':
    main()