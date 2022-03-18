import matplotlib.pyplot as plt
from matplotlib import rcParams
import random
import math
#让中文被支持
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
#显示负号
rcParams["axes.unicode_minus"]=False
ax=plt.figure(figsize=(10,5),dpi=100).add_subplot()    #dpi为清晰度

xs=[i/100 for i in range(1500)]
ys=[10*math.sin(i) for i in xs]
ys1=list(range(-18,19))
random.shuffle(ys1)
ys1=ys1[:16]
def drawplot(xs,ys,ys1,ax):
    ax.plot(xs,ys,color="blue",label="曲线")
    ax.plot(list(range(16)),ys1,color="orange",label="折线图")
    ax.scatter(list(range(16)),ys1,color="orange",label="散点图")
    ax.set_xticks([2,4,6,8,10,12,14])
    return
drawplot(xs,ys,ys1,ax)

ax.legend()
plt.show()