from pro1 import *
import numpy as np
from simulate import *

def compute_t(t):
    lis = [None] * 225
    v = [1]
    last_theta = 32 * pi
    theta = head_theta_t(last_theta, t)
    last_v = 1
    last_theta = theta
    init = head / R(theta)
    theta_ = last_theta + head_pre_theta(theta, init)
    R_n = R(theta_)
    head_r = rectangle(point(R(theta), theta), point(R_n, theta_))
    lis[0] = head_r
    for i in range(1, 225):
        delta_theta = pre_theta(theta_, d / R_n)
        last_v = pre_v(theta_, theta_ + delta_theta, last_v)
        v.append(last_v)
        rec = rectangle(point(R_n, theta_), point(R(theta_ + delta_theta), theta_ + delta_theta))
        lis[i] = rec
        R_n = R(theta_ + delta_theta)
        theta_ += delta_theta
    return lis, v
    pass

def main():
    t = 407.8316

    lis, v = compute_t(t)
    print(v)
    column_name = [
        "横坐标x(m)",
        "纵坐标y(m)",
        "速度(m/s)",
    ]

    row_name = []
    for i in range(224):
        if i == 0:
            row_name.append("龙头")
            continue
        if i == 223:
            row_name.append("龙尾")
            row_name.append("龙尾(后)")
            continue
        row_name.append(f"第{i}节龙身")
    
    data = np.zeros((225, 3))
    for i in range(224):
        if i == 0:
            data[i][0] = np.round(lis[0].last.x, 6)
            data[i][1] = np.round(lis[0].last.y, 6)
            data[i][2] = v[i]
            continue
        if i == 223:
            data[i][0] = np.round(lis[223].last.x, 6)
            data[i][1] = np.round(lis[223].last.y, 6)
            data[i][2] = np.round(v[223], 6)
            data[i + 1][0] = np.round(lis[223].Next.x, 6)
            data[i + 1][1] = np.round(lis[223].Next.y, 6)
            data[i + 1][2] = np.round(v[224], 6)
            break
        data[i][0] = np.round(lis[i].last.x, 6)
        data[i][1] = np.round(lis[i].last.y, 6)
        data[i][2] = np.round(v[i], 6)
    
    df = pd.DataFrame(data, columns=column_name, index=row_name)
    df.to_excel("result2.xlsx")

if __name__ == '__main__':
    main()
    pass