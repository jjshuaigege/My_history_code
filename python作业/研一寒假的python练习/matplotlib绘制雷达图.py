import math
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
ax=plt.figure().add_subplot(projection="polar")    #"polar"代表增加极坐标子图
labs=["EQ","IQ","人缘","魅力","财富","体力"]
names=["张三","李四","王五"]
data=[[0.40,0.32,0.35],[0.85,0.35,0.30],
      [0.40,0.32,0.35],[0.40,0.82,0.75],
      [0.14,0.12,0.35],[0.80,0.92,0.35]]
weidu=len(data)
angles=[i*2*math.pi/weidu for i in range(weidu)]
angles2=[i*360/weidu for i in range(weidu)]
ax.set_ylim(0,1)
ax.set_thetagrids(angles2,labels=labs)
ax.fill(angles,data,alpha=0.25)

ax.set_title("三巨头人格分析")
ax.legend(names,loc=[0.95,0.9])
plt.show()

