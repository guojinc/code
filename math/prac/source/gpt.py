import pandas as pd
from A import dispose_all,dispose,dispose_all_col
# 加载数据
normal_data = pd.read_csv('math\\with\\A\\Normal_exp.csv')
early_stage_data = pd.read_csv('math\\with\\A\\EarlyStage_exp.csv')
later_stage_data = pd.read_csv('math\\with\\A\\LaterStage_exp.csv')
# 数据清洗
# 检查缺失值
import numpy as np
from scipy import stats
import numpy as np
from matplotlib import pyplot as plt
from scipy.stats import normaltest



from scipy.stats import spearmanr
import statsmodels.api as sm
data = normal_data.iloc[1, 1:].values

# 创建 Q-Q 图，并增加 45度线
fig = sm.qqplot(data, line='45')
plt.show()

# print(col)
# 执行正态性检验
# Generate and plot quantile-quantile plot
# for i in range(len(normal_data.columns)):
#     stats.probplot(normal_data.iloc[:, i], dist="norm", plot=plt)
#     plt.title(f'Q-Q Plot for column {i}')
#     plt.show()

# 执行正态性检验

# for i in range(len(col)):
#     # print(normal_data.iloc[:, i])
#     k2, p_value = normaltest(normal_data.iloc[:, i])
#     print(f'Normality test for column {i}: K2 statistic: {k2}, p-value: {p_value}')


# p_values = []
# for i in range(col.columns.size):
#     # print(col.iloc[i, 0:].values)
#     k2, p_value_ = normaltest(list(col.iloc[:, i].values))
#     p_values.append(p_value_)
#     # if p_value_ < 0.05:
#     #     p_values.append(p_value_)

# #绘制p值

# # 绘制散点图
# plt.scatter(range(len(p_values)), p_values)
# plt.xlabel('Column Index')
# plt.ylabel('p-value')
# plt.title('p-value Distribution')
# plt.show()









# 对每一列求和
# normal_data_sum = nor_col.sum(axis=0)

# # 打印求和结果
# print("Sum of normal_data:", normal_data_sum)
# normal_data_sum = nor_col.sum(axis=1)

# # 打印求和结果
# print("Sum of normal_data:", normal_data_sum)


# Gene_name = list(normal_data["Unnamed: 0"])#基因名
# # 执行T检验
# Gene = []
# for i in range(1,30):
#     t_statistic, p_value = stats.ttest_ind(normal_data.iloc[:, i], early_stage_data.iloc[:, i])
#     for j in range(len(p_value)):
#         if p_value[j] < 0.05:
#             Gene.append(Gene_name[j])
#     # 输出T检验结果
# Gene = set(Gene)
# print(len(Gene))
# # spearman_results = []
# print(len(Gene))
# for gene in Gene:
#     gene_data = normal_data.loc[normal_data["Unnamed: 0"] == gene].values.flatten()[1:]
#     print(len(gene_data))
#     print(len(early_stage_data.iloc[:, 1:].values.flatten()))
#     spearman_corr, spearman_pvalue = spearmanr(gene_data, early_stage_data.iloc[:, 1:])
#     spearman_results.append((gene, spearman_corr, spearman_pvalue))
# print(spearman_results)















# # # 假设normal_data和early_stage_data是两个NumPy数组
# # # 首先，检查它们的形状
# # print("normal_data形状：", normal_data.shape)
# # print("early_stage_data形状：", early_stage_data.shape)

# # # 如果它们的列数不一致，需要对其中一个数组进行reshape操作
# # # 假设需要将normal_data的形状调整为与early_stage_data相同
# # # 计算early_stage_data的列数
# # num_columns = early_stage_data.shape[1]

# # # 调整normal_data的形状
# # normal_data_reshaped = normal_data.iloc[:, 1:].values.reshape(-1, num_columns)

# # # 现在，再次检查它们的形状
# # print("调整后的normal_data形状：", normal_data_reshaped.shape)
# # print("early_stage_data形状：", early_stage_data.shape)

# # # 现在两个数组的列数相同了，就可以执行T检验了
# # t_statistic, p_value = stats.ttest_ind(normal_data_reshaped, early_stage_data.iloc[:, 1:])
# # 仅保留normal_data的前129列，使其与early_stage_data具有相同的形状
# normal_data_trimmed = normal_data.iloc[:, 1:130]

# # 现在两个数组的形状是一致的，可以进行T检验
# t_statistic, p_value = stats.ttest_ind(normal_data_trimmed, early_stage_data.iloc[:, 1:])

# # t检验比较正常人和早期患者的基因表达差异
# # t_statistic, p_value = stats.ttest_ind(normal_data.iloc[:, 1:], early_stage_data.iloc[:, 1:])
# # 获取显著差异的基因
# significant_genes = normal_data.columns[1:][p_value < 0.05]

# # 差异分析
# # 差异基因分析
# # 这里可以使用差异分析方法，如limma、DESeq2等
# # 这里以简单的示例展示
# mean_normal = normal_data[significant_genes].mean(axis=1)
# mean_early_stage = early_stage_data[significant_genes].mean(axis=1)
# mean_later_stage = later_stage_data[significant_genes].mean(axis=1)

# # 构建相关网络
# # 这里可以使用相关性分析、基因共表达网络分析等方法
# # 这里以简单的相关性分析示例
# correlation_matrix = np.corrcoef(normal_data[significant_genes].values.T)

# from sklearn.model_selection import train_test_split
# from sklearn.linear_model import LogisticRegression
# from sklearn.metrics import accuracy_score, classification_report

# # 特征选择与模型建立
# X = np.concatenate([normal_data[significant_genes].values, early_stage_data[significant_genes].values])
# y = np.concatenate([np.zeros(normal_data.shape[0]), np.ones(early_stage_data.shape[0])])

# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# # Logistic回归建模
# model = LogisticRegression()
# model.fit(X_train, y_train)

# # 模型评价
# y_pred = model.predict(X_test)
# accuracy = accuracy_score(y_test, y_pred)
# report = classification_report(y_test, y_pred)

# print("Accuracy:", accuracy)
# print("Classification Report:\n", report)

# from sklearn.preprocessing import StandardScaler

# # 数据标准化处理
# scaler = StandardScaler()
# X_scaled = scaler.fit_transform(X)
