import pandas as pd
import numpy as np  
import random
import os
import itertools


# excel_path = 'math\\with\\B\\data.xlsx'
# excel_file = os.path.join(excel_path)
# xls = pd.ExcelFile(excel_file)
# sheet_names = xls.sheet_names
# data = pd.read_excel(excel_file, sheet_name=sheet_names[0], index_col=0)
# matrix = data.values.transpose()
# total_discontent = 0

excel_path = 'C:\\code\\math\\with\\B\\data.xlsx'
excel_file = os.path.join(excel_path)
xls = pd.ExcelFile(excel_file)
sheet_names = xls.sheet_names
data = pd.read_excel(excel_file, sheet_name=sheet_names[0], index_col=0)
matrix = data.values.transpose()

inter = pd.read_excel(excel_file, sheet_name=sheet_names[1], index_col=0)

I = inter.values
directory = 'C:\\code\\math\\with\\B\\'
csv_file = 'data2.csv'
csv = pd.read_csv(directory + csv_file)
initial_solution = csv.values
def discontentment_2(D, solution, I):
    total_discontent = 0
    task_negative_impact = 0
    for i in range(len(solution)):
        row_discontent = 0
        times = 0
        row_workers = []
        for j in range(len(solution[i])):
            if solution[i][j] == 1:
                row_discontent += D[i][j]
                times += 1 
                row_workers.append(j)
        for pair in itertools.combinations(row_workers, 2):
            task_negative_impact += I[pair[0]][pair[1]]
        total_discontent += row_discontent / times
    total_discontent += task_negative_impact
    return total_discontent

def discontentment(D, solution):
    total_discontent = 0
    # for i in range(len(solution)):
    #     row_discontent = 0
    #     times = 0
    #     for j in range(len(solution[i])):
    #         if solution[i][j] == 1:
    #             row_discontent += D[i][j]
    #             times += 1 
    #     total_discontent += row_discontent / times
    for task_index, task_workers in enumerate(solution):
        # 如果没有员工被分配给该任务，则跳过
        if not np.any(task_workers):
            continue
        
        # 获取分配给该任务的员工索引
        workers_indices = np.where(task_workers == 1)[0]
        
        # 计算多名员工的不满意程度的平均值
        task_discontent = np.mean(D[task_index, workers_indices])
        
        # 将任务的不满意程度加到总不满意程度中
        total_discontent += task_discontent
    
    return total_discontent

print(discontentment(matrix, initial_solution))
print(discontentment_2(matrix, initial_solution, I))
