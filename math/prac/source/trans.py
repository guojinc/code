import pandas as pd
import numpy as np
import os
file_path = 'C:\\code\\math\\with\\B\\data2.csv'
file_path_1 = 'C:\\code\\math\\with\\B\\data.xlsx'


data = pd.read_csv(file_path)
data_set = pd.read_excel(file_path_1)


matrix = data.values
D = data_set.values

column_name_1 = "人序号"
column_name_2 = "任务序号"
column_name_3 = "当前任务不满意程度"
column_name_4 = "最小不满意程度"
column_name_5 = "最小不满意程度对应的任务序号"



column_1 = [i for i in range(1, 281)]
column_2 = [0 for i in range(280)]
column_5 = [0 for i in range(280)]
for i in range(100):
    for j in range(280):
        if matrix[i][j] == 1:
            column_2[j] = i + 1

column_3 = [0 for i in range(1,281)]
print(D.shape)
for i in range(280):
    column_3[i] = D[i][column_2[i]]

column_4 = [0 for i in range(280)]
for i in range(280):
    column_4[i] = min(D[i, :])
    column_5[i] = np.where(D[i, :] == column_4[i])[0][0] + 1
# 创建一个数据框
df = pd.DataFrame({
    column_name_1: column_1,
    column_name_2: column_2,
    # column_name_3: column_3,
    # column_name_4: column_4,
    # column_name_5: column_5
})

# 将数据框写入Excel文件
directory = 'C:\\code\\math\\with\\B\\result\\'
# file_name = 'final_1.xlsx'
file_name = 'final_2.xlsx'
df.to_excel(os.path.join(directory, file_name), index=False)