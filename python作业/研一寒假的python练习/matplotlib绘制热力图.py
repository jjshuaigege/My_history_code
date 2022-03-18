import matplotlib.pyplot as plt
from matplotlib import rcParams
import numpy as np
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
ax=plt.figure(figsize=(10,5),dpi=200).add_subplot()
data=np.random.randint(0,101,30,int).reshape(5,6)
xlabels=["Beijing","Shanghai","Chengdu","Guangzhou","Hangzhou","Wuhan"]
ylabels=['2016','2017',"2018","2019","2020"]
ax.set_xticks(list(range(len(xlabels))))
ax.set_yticks(list(range(len(ylabels))))
ax.set_xticklabels(xlabels)
ax.set_yticklabels(ylabels)
heatMp=plt.imshow(data,cmap=plt.cm.hot,aspect='auto',vmin=0,vmax=100)
#写出各区域数字
for i in range(len(xlabels)):
    for j in range(len(ylabels)):
        ax.text(i,j,data[j][i],ha="center",va="center",color="blue",fontsize=26)  #ha,va的值表示，以这段文字的中心位置的坐标设置大小
plt.colorbar(heatMp)     #画出图右边的柱子指示图
plt.xticks(rotation=45,ha="right")   #旋转45度，右侧为位置参考点
plt.title("Sales Volume(ton)")
plt.show()
