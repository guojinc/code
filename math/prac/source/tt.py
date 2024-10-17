import pandas as pd
import numpy as np  
import random
import os
import multiprocessing
import itertools

excel_path = 'C:\\code\\math\\with\\B\\data.xlsx'
excel_file = os.path.join(excel_path)
xls = pd.ExcelFile(excel_file)
sheet_names = xls.sheet_names
data = pd.read_excel(excel_file, sheet_name=sheet_names[0], index_col=0)
matrix = data.values.transpose()

inter = pd.read_excel(excel_file, sheet_name=sheet_names[1], index_col=0)

I = inter.values





def judge(matrix):
    if sum(sum(matrix)) != 280:
        print(sum(sum(matrix)))
        exit(0)
    for i in range(len(matrix)):
        if sum(matrix[i]) < 2:
            print(i)
            print(sum(matrix[i]))
            exit(0)
    return True

def discontentment(D, solution,I):
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


    # for task_index, task_workers in enumerate(solution):
    #     # 如果没有员工被分配给该任务，则跳过
    #     if not np.any(task_workers):
    #         continue
        
    #     # 获取分配给该任务的员工索引
    #     workers_indices = np.where(task_workers == 1)[0]
        
    #     # 计算多名员工的不满意程度的平均值
    #     task_discontent = np.mean(D[task_index, workers_indices])
        
    #     # 将任务的不满意程度加到总不满意程度中
    #     total_discontent += task_discontent
    


    return total_discontent
def random_change2(current_solution):
    randomtasknum_1, randomtasknum_2 = np.random.choice(100, replace=False, size=2)
    randomtask_1 = current_solution[randomtasknum_1]
    randomtask_2 = current_solution[randomtasknum_2]
    randomemployee = []
    for i in range(280):
        if randomtask_1[i] == 1: 
            randomemployee.append(i)
            randomtask_1[i] = 0
        elif randomtask_2[i] == 1:
            randomtask_2[i] = 0
            randomemployee.append(i)

    #print(randomemployee, end=' ')
    #print(len(randomemployee), end=' ')
    random1, random2 = split_array_randomly(randomemployee)
    # print(len(random1), len(random2))
    for i in random1:
        randomtask_1[i] = 1
    for i in random2:
        randomtask_2[i] = 1
    current_solution[randomtasknum_1] = randomtask_1
    current_solution[randomtasknum_2] = randomtask_2
    return current_solution
def random_change(current_solution_copy, D, I):
    current_solution = current_solution_copy.copy()
    best_solution = current_solution.copy()
    best_discontentment = discontentment(D, best_solution, I)
    randtasknum_1, randtasknum_2 = np.random.choice(100, replace=False, size=2)
    randtask_1 = current_solution[randtasknum_1]
    randtask_2 = current_solution[randtasknum_2]
    randemployee_1 = []
    randemployee_2 = []
    for i in range(280):
        if randtask_1[i] == 1: 
            randemployee_1.append(i)
            randtask_1[i] = 0
        if randtask_2[i] == 1:
            randtask_2[i] = 0
            randemployee_2.append(i)

    # rand1, rand2 = split_array_randomly(randemployee)
    # rand1 = [0 for i in range(len(randemployee_1))]
    # rand2 = [0 for i in range(len(randemployee_2))]
    # rand1,rand2 = []
    # if len(rand2) == 4:
    #     pass
    # iter_1 = itertools.permutations(randemployee_1, len(randemployee_1))
    # iter_2 = itertools.permutations(randemployee_2, len(randemployee_2))
    for q in range(2):
        for l in range(len(randemployee_1)):
            for g in range(len(randemployee_2)):
                rand1 = randemployee_1.copy()
                rand2 = randemployee_2.copy()
                rand1[l], rand2[g] = rand2[g], rand1[l]
                if q == 1:
                    rand1, rand2 = rand2, rand1
                for i in rand1:
                    randtask_1[i] = 1
                for i in rand2:
                    randtask_2[i] = 1
                current_solution = best_solution.copy()
                current_solution[randtasknum_1] = randtask_1
                current_solution[randtasknum_2] = randtask_2
                res = discontentment(D, current_solution, I)
                # print(res)
                if res < best_discontentment:
                    best_discontentment = discontentment(D, current_solution, I)
                    best_solution = current_solution.copy()
    return best_solution, best_discontentment
def random_change3(current_solution):
    randomtasknum_1, randomtasknum_2, randomtasknum_3 = np.random.choice(100, replace=False, size=3)
    randomtask_1 = current_solution[randomtasknum_1]
    randomtask_2 = current_solution[randomtasknum_2]
    randomtask_3 = current_solution[randomtasknum_3]
    randomemployee = []
    for i in range(280):
        if randomtask_1[i] == 1: 
            randomemployee.append(i)
            randomtask_1[i] = 0
        elif randomtask_2[i] == 1:
            randomtask_2[i] = 0
            randomemployee.append(i)
        elif randomtask_3[i] == 1:
            randomtask_3[i] = 0
            randomemployee.append(i)

    #print(randomemployee, end=' ')
    #print(len(randomemployee), end=' ')
    random1, random2, random3 = _split_array_randomly(randomemployee)
    # print(len(random1), len(random2), len(random3))
    for i in random1:
        randomtask_1[i] = 1
    for i in random2:
        randomtask_2[i] = 1
    for i in random3:
        randomtask_3[i] = 1
    current_solution[randomtasknum_1] = randomtask_1
    current_solution[randomtasknum_2] = randomtask_2
    current_solution[randomtasknum_3] = randomtask_3
    return current_solution

def _split_array_randomly(array):
    # 确保数组至少有6个元素，这样每个子数组至少有2个元素
    n = len(array)
    mid = n // 2
    
    # try:
    #     assert n >= 6 , "数组长度至少为6"
    # except AssertionError:
    #     print(array)
    #     print(n)
    # 随机选择两个分割点，范围从2到len(array)-4，确保每个子数组至少有2个元素
    split_points = [0, 0]
    r = mid - 1
    l = mid + 1
    rr = n - 2
    #print(f",,{n}, {mid},,{r},{l},{rr}")
    split_points[0] = random.randint(2, r)
    split_points[1] = random.randint(l,rr)
    # 随机打乱数组
    np.random.shuffle(array)

    # 分割数组
    sub_array_1 = array[:split_points[0]]
    sub_array_2 = array[split_points[0]:split_points[1]]
    sub_array_3 = array[split_points[1]:]


    return sub_array_1, sub_array_2, sub_array_3

def split_array_randomly(array):
    # 确保数组至少有4个元素，这样每个子数组至少有2个元素

    # 随机选择分割点，范围从2到len(array)-2 ，确保每个子数组至少有2个元素
    split_point = random.randint(2, len(array) - 2)
    if (len(array) == 6):
        split_point = 3

    # split_point = np.random.choice(range(2, len(array) - 1))

    # 随机打乱数组
    np.random.shuffle(array)

    # 分割数组
    sub_array_1 = array[:split_point]
    sub_array_2 = array[split_point:]

    return sub_array_1, sub_array_2


# def change(current_solution):
#     for i in range(100):
#         cur_task = current_solution[i]
#         cur_emp = []
#         for j in range(280):
#             if cur_task[j] == 1:
#                 cur_emp.append(j)
#         for k in range(100 - i):
#             cur_task_1 = current_solution[k]
#             for l in range(280):
#                 if cur_task_1[l] == 1:
                    


def simulated_annealing(D, initial_solution,I ,initial_temperature=1, alpha=0.8,max_iter=500):



    current_solution = initial_solution.copy()
    current_discontentment = discontentment(D, initial_solution, I)
    T = initial_temperature
    Tk = 0.1
    i = 0
    process = 0
    best_solution = current_solution.copy()
    best_discontentment = current_discontentment
    while i < max_iter:
        
        # 随机选择一个任务并交换其执行:者
        new_solution, new_discontentment = random_change(current_solution, D, I)
        # new_solution = random_change2(current_solution)
        # new_discontentment = discontentment(D, new_solution, I)
        
        # 计算交换后的能量
        # print(sum(sum(new_solution)))
        # print(current_discontentment)
        # print(new_discontentment)
        # print(best_discontentment)
        # Metropolis 准则
 
        if new_discontentment < current_discontentment:
            current_solution = new_solution.copy()
            current_discontentment = new_discontentment

            if current_discontentment < best_discontentment:
                best_solution = current_solution.copy()
                best_discontentment = current_discontentment
                # print(current_discontentment)
        # else:
        #     if np.random.rand() < np.exp((current_discontentment - new_discontentment) / T):
        #         current_solution = new_solution.copy()
        #         current_discontentment = new_discontentment
        #     else:
        #         current_solution = new_solution.copy()
        i+=1
        # 更新温度
        # print(current_discontentment)
        # if i % 139 == 0:
        #     print(str(i / 1381.48) + "%")
        T *= alpha

        
    
    return best_solution, best_discontentment

# 示例数据
D = matrix
# 随机生成初始解
import numpy as np

def generate_initial_solution(num_tasks, num_employees):
    initial_solution = np.zeros((num_tasks, num_employees))
    initial_solution = initial_solution.transpose()
    rand_1 = np.random.choice(range(100), 100, replace=False)
    rand_2 = np.random.choice(range(100), 100, replace=False)
    rand_3 = np.random.choice(range(100), 80, replace=True)
    for i in range(num_tasks):
        initial_solution[i][rand_1[i]] = 1
        initial_solution[i + 100][rand_2[i]] = 1
    for i in range(80):
        initial_solution[199 + i][rand_3[i]] = 1
    initial_solution = initial_solution.transpose()
    return initial_solution
# 示例数据
num_tasks = 100
num_employees = 280
# for i in range(100000):
#     initial_solution = generate_initial_solution(num_tasks, num_employees)
#     if (i % 100 == 0):
#         print(str(i/1000) + "%")
#     if discontentment(D, initial_solution) < 500:
#         print(discontentment(D, initial_solution))
#     # final_solution, min_discontentment = simulated_annealing(D, initial_solution)
#     np.set_printoptions(threshold=np.inf)
#     if (discontentment(D, initial_solution) < 500):
#         np.WriteCsv('math\\with\\B\\data.csv', initial_solution)
#         np.WriteTxt('math\\with\\B\\data.txt', discontentment(D, initial_solution))
#     # print(final_solution)
#     # print(final_solution)
#     # print(min_discontentment)

# initial_solution = generate_initial_solution(num_tasks, num_employees)
# final_solution, min_discontentment = simulated_annealing(D, initial_solution)
# print(discontentment(D, initial_solution))
# print(min_discontentment)

# 将initial_solution写入CSV文

# 检查目录是否存在，如果不存在则创建
# directory = 'math\\with\\B\\'
# csv_file = 'data.csv'
# csv = pd.read_csv(directory + csv_file)
# initial_solution = csv.values

# if not os.path.exists(directory):
#     os.makedirs(directory)
# print(discontentment(D, initial_solution))

# 创建进程池


# 定义并行任务函数
# 并行运行任务
pro = 1
if __name__ == '__main__':
    for i in range(10):
        directory = 'C:\\code\\math\\with\\B\\result\\'
        csv_file = 'data3.csv'
        csv = pd.read_csv(directory + csv_file)
        initial_solution = csv.values
        # initial_solution = generate_initial_solution(num_tasks, num_employees)
        with multiprocessing.Pool(pro) as pool:
            results = pool.starmap(simulated_annealing, [(D, initial_solution, I)]* pro)

        # results = pool.map(parallel_task, [initial_solution] * 10)

        # # 关闭进程池
        # pool.close()
        # pool.join()
        # 获取最佳结果
        best_solution, min_discontentment = min(results, key=lambda x: x[1])
        print(min_discontentment)
        
        # 现在你可以安全地写入文件了
        pd.DataFrame(best_solution).to_csv(os.path.join(directory, 'data3.csv'), index=False)


