import matplotlib.pyplot as plt
from matplotlib import rcParams
#设置中文支持，中文字体为简体黑体
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
ax=plt.figure().add_subplot()

cordx=[2,4,6,8]
data1=[20,30,15,35]
data2=[15,25,20,30]
ax.bar(x=cordx,height=data1,width=0.5,color="red",label="计算机部门")
ax.bar(x=cordx,height=data2,width=0.5,bottom=data1,color="green",label="金融部门")

ax.set_title("我的堆叠直方图")
ax.set_xlabel("工厂");ax.set_ylabel("profit")
ax.set_ylim(0,100)                        #设置y轴的范围
ax.set_xticks([i for i in range(1,11)])   #设置x轴各刻度的位置
ax.set_xticklabels(["","阿里","","百度","","腾讯","","字节","",""])    #设置x轴各刻度的标签

ax.set_title("公司营收情况")

ax.legend()            #显示前面写出的图例说明
plt.show()