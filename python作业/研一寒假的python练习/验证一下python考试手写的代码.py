import numpy as np
import matplotlib.pyplot as plt
import random
from matplotlib import rcParams
rcParams["font.family"]=rcParams["font.sans-serif"]="SimHei"
xlist=[(i+1)/10 for i in range(9)]
ylist=[j/10 for j in range(11,110,11)]
random.shuffle(xlist)
random.shuffle(ylist)
print(xlist)
print(ylist)
x=np.array(xlist);y=np.array(ylist)


plt.subplot(3,1,1)
plt.xlim(0,1);plt.ylim(0,10)
plt.xlabel("横");plt.ylabel("纵")
plt.plot(x,y,"r")

plt.subplot(3,1,2)
plt.xlim(0,1);plt.ylim(0,10)
plt.xlabel("横");plt.ylabel("纵")
plt.scatter(x,y)

plt.subplot(3,1,3)
plt.xlim(0,1);plt.ylim(0,10)
plt.xlabel("横");plt.ylabel("纵")
plt.bar(x,y,width=0.05)

plt.show()
# import random
#
# a=[i for i in range(1,11,1)]
# random.shuffle(a)
# print(a)