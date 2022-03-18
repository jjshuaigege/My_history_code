import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
#显示负号
rcParams["axes.unicode_minus"]=False
import math
import random
fg=plt.figure(figsize=(8,8))
ax=fg.add_subplot(2,2,1)
###
lbs=['A','B','C','D']
sectors=[16,29.55,44.45,10]
expl=[0,0.3,0,0]   #突出程度,如0.3为占圆饼直径的30%
def draw_pie(lbs,sectors,expl,ax):
    #sectors为比例，labels为标签，explode为各块饼离中心的距离，autopct为保留后两位小数，labeldistance为标签距中心的距离，pctdistance为比例的数字距中心的距离，startangle为初始饼的角度
    ax.pie(x=sectors,labels=lbs,explode=expl,autopct="%.2f",shadow=True,labeldistance=1.1,pctdistance=0.6,startangle=90)    #所有距离的值都是饼半径的倍数
    ax.set_title("我的饼图")
draw_pie(lbs,sectors,expl,ax)
ax.legend()
###
ax=fg.add_subplot(2,2,2,projection="polar")
###
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
ax.legend(names)
###
ax=fg.add_subplot(2,1,2)
###
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

ax.legend(loc=[0.95,0.9])
###
plt.figtext(0.05,0.05,"多子图的绘制")    #为整个窗口添加标题
plt.show()