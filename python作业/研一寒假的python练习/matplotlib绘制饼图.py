import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
ax=plt.figure(figsize=(10,5),dpi=100).add_subplot()
lbs=['A','B','C','D']
sectors=[16,29.55,44.45,10]
expl=[0,0.3,0,0]   #突出程度,如0.3为占圆饼直径的30%
def draw_pie(lbs,sectors,expl,ax):
    #sectors为比例，labels为标签，explode为各块饼离中心的距离，autopct为保留后两位小数，labeldistance为标签距中心的距离，pctdistance为比例的数字距中心的距离，startangle为初始饼的角度
    ax.pie(x=sectors,labels=lbs,explode=expl,autopct="%.2f",shadow=True,labeldistance=1.1,pctdistance=0.6,startangle=90)    #所有距离的值都是饼半径的倍数
    ax.set_title("我的饼图")
draw_pie(lbs,sectors,expl,ax)
ax.legend()
plt.show()
