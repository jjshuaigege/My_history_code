import matplotlib.pyplot as plt
from matplotlib import rcParams
#设置中文支持，中文字体为简体黑体
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
ax=plt.figure().add_subplot()
#画纵向直方图
ax.bar(x=(0.2,0.6,0.8,1.2),height=(1,2,3,0.5),width=0.1,color=['blue','green','red','orange']) #四个柱子，x为四柱的位置，height为各柱子高度，width为柱子宽度，color为各柱子颜色
ax.set_title("我的直方图")   #设置标题
plt.show()

ax=plt.figure().add_subplot()
ax.set_title("我的直方图(横向)")   #设置标题
#画横向直方图
ax.barh(y=(0.2,0.6,0.8,1.2),width=(1,2,3,0.5),height=0.1,color=['blue','green','red','orange'])
ax.set_xlabel("横");ax.set_ylabel("纵")          #设置x和y轴的名称
plt.show()