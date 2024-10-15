import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

COL_NUM = 2

average = lambda x: sum(x) / len(x)#求平均值

# 范数归一化

def normalize(data):
    data = np.array(data)
    data = data / np.sum(np.abs(data))
    return data
#标准化
def standardization(data):
    data = np.array(data)
    data = (data - np.mean(data)) / np.std(data)
    return data

def dispose(csv):
    names = csv.iloc[0]
    names = names.keys()
    col = list(csv[names[COL_NUM]])
    name = names[COL_NUM]
    col = normalize(col)
    return names, col, name#返回样本名字，基因表达量，选取的样本名

def dispose_all_col(csv):

    
    names = csv.iloc[0]
    names = names.keys()
    col = []
    for i in range(1, len(names)):
        col.append(list(csv[names[i]]))
    for i in range(len(col)):
        col[i] = normalize(col[i])
    col = pd.DataFrame(col)
    col.transpose()
    
    return col#返回样本名字，基因表达量

def dispose_all(csv):
    names = csv.iloc[0]
    names = names.keys()
    col = []
    for i in range(1, len(names)):
        col.append(list(csv[names[i]]))
    for i in range(len(col)):
        col[i] = normalize(col[i])
    ret_col = []
    tmp = []
    for i in range(len(col[0])):
        for j in range(len(col)):
            tmp.append(col[j][i])
        ret_col.append(average(tmp))
        tmp = []
    return ret_col#返回样本名字，基因表达量




# with open('math\\with\\A\\Normal_exp.csv') as nor:
#     csv_nor = pd.read_csv(nor)#读取csv文件
#     Gene = list(csv_nor["Unnamed: 0"])#基因名
#     nor_col = dispose_all(csv_nor)#处理数据
#     # nor_names, nor_col, nor_name = dispose(csv_nor)#处理数据
#     #print(csv_nor.shape)
#     with open('math\\with\\A\\EarlyStage_exp.csv') as ear:
#         csv_ear = pd.read_csv(ear)
#         ear_col = dispose_all(csv_ear)
#         # ear_names, ear_col, ear_name = dispose(csv_ear)
#         # print(csv_ear.shape)
#         with open('math\\with\\A\\LaterStage_exp.csv') as lat:
#             csv_lat = pd.read_csv(lat)
#             lat_col = dispose_all(csv_lat)
#             # lat_names, lat_col, lat_name = dispose(csv_lat)
#             # print(csv_lat.shape)
#             # print(nor_col)
#             # print(csv_nor["Unnamed: 0"])
#             #print(csv_nor["Unnamed: 0"])
#             #print(csv_nor[nor_names[1]])
#             # print(nor_col)
#             # print(len(Gene))

#             plt.plot(Gene, nor_col, label="Normal",color='blue',alpha=0.2)
#             plt.plot(Gene, ear_col, label="EarlyStage",color='green',alpha=0.2)
#             plt.plot(Gene, lat_col, label="LaterStage",color='red',alpha=0.2)
#             plt.legend()
#             plt.show()
