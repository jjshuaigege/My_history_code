import matplotlib.pyplot as plt
from matplotlib import rcParams
wd=2
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
ax=plt.figure(figsize=(10,5)).add_subplot()
ax.set_xlabel("时间",fontsize=20);ax.set_ylabel("销量",fontsize=20)
x3=[10,20,30,40,50,60]
x1=[i-wd for i in x3]
x2=[i+wd for i in x3]
y1=[41,39,13,69,39,14]
y2=[123,15,20,105,79,37]
y3=[124,91,204,264,221,175]
ax.set_xticks(x3)
ax.set_xticklabels(["时间1","时间2","时间3","时间4","时间5","时间6"],fontsize=10)
rect1=ax.bar(x=x1,height=y1,width=wd,color="red",label="xiaomi")
rect2=ax.bar(x=x2,height=y2,width=wd,color="orange",label="iphone")
rect3=ax.bar(x=x3,height=y3,width=wd,color="yellow",label="huawei")


#写一个标明各框框高度的数字
def mark_height(ax,rects):
    for rect in rects:
        height=rect.get_height()
        ax.text(rect.get_x()-0.05+rect.get_width()/2.0,height+5,str(height),rotation=90)       #ax.text(x,y,words,rotation=)      在位置(x,y)写上字符串words，旋转一定角度
mark_height(ax,rect1)
mark_height(ax,rect2)
mark_height(ax,rect3)

ax.legend(fontsize=15)
plt.show()