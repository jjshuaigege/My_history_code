import numpy as np
from sklearn.neural_network import MLPClassifier
import math_functions as mf
clf = MLPClassifier(hidden_layer_sizes=(200,100),activation="logistic",solver="sgd",learning_rate_init=0.5,learning_rate="constant",max_iter=10,batch_size=100)
# 准备数据
x = np.zeros((50000, 2), float)
y = np.zeros((50000, 2), float)
for i in range(len(x)):
    x[i] = mf.Random_uniform_value(0, 6, (2,))
    if (x[i][0] - 3) ** 2 + (x[i][1] - 3) ** 2 <= 4:
        y[i][0] = 1
    else:
        y[i][1] = 1
#对输入数据作归一化
x_mean=np.mean(x,axis=0)
x_std=np.std(x,axis=0,ddof=1)    #ddof=1说明是样本标准差（除以n-1）
for i in range(len(x)):
    x[i]=(x[i]-x_mean)/x_std
clf.fit(x[:40000],y[:40000])
res=clf.predict(x[40000:])
error_num=0
num=len(x[40000:])
for i in range(num):
    if np.sum(res[i]==y[40000:][i])<2:
        error_num+=1
print("Total num:",num,"Wrong num:",\
      error_num,"WrongRate:",error_num / float(num))