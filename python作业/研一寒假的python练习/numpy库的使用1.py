import numpy as np
# print(np.array([1,5,8]))      #将列表转为numpy数组
# print(np.arange(1,9,2))       #[1,9),间隔为2
# print(np.linspace(1,10,4))    #将区间【1，10】三等份(在此过程会自动转为浮点数)
# print(np.random.randint(10,20,[5,6]))  #生成一个取值为[10,20),5行6列的二维数组
# b=np.array([3.0,1.0,2.6,8.8,4.5,6.6])
# c=b.reshape([3,2])            #生成一个由b而来的3*2的矩阵，b本身不变
# print(c.size,c.dtype,c.size,c.shape)
# print(c)

# na=np.arange(1,13)
# nb=na.reshape([3,4])   #得到一个有na变来的3行4列的数组，na不变
# print(nb.ndim)         #数组是几维的
# print(nb.size)         #数组有多少个元素
# print(nb.shape)        #数组几行几列
# print(nb.dtype)
# L=nb.tolist()          #转化成列表，nb不变
# print(L)
# nc=nb.flatten()       #由nb得到一个一维np数组，nb本身不变
# print(nc==na)         #同样形状的数组之间的比较是各位置的元素依次作比较
#
# #np矩阵增删元素：np矩阵一旦生成，不能增删元素，但可以通过生成新的np数组来做到
# nd=np.append(nb,[7.7,8.8,9.9,10.10])           #将列表中的元素加到nb中去，生成一个新的一维np数组
# print(nb)
# print(nd)
#
# ne=np.array([[1,2,3],[4,5,6],[7,8,9]])
# print(ne)
# nf=np.array([[1,9,11],[2,8,12],[4,6,13]])
# ng=np.concatenate((ne,nf),axis=0)     #axis=n,按第n维拼接
# nh=np.concatenate((nd,nd))
# print(ng)
# print(nh)
# ni=np.delete(ng,(2,5),axis=0)            #删除第2、5行的元素
# print(ni)
# pos1=np.argwhere(ni>6)                   #ni中大于6的所有元素的位置
# print(pos1)
# #np数组的切片是视图，而不是浅拷贝
# ni[1:3,1:3]=np.array([[77,88],[99,1010]])   #[1,3)行，[1,3)列的切片
# print(ni)

nk=np.array([[5,8,10,11],[13,15,18,19],[22,23,24,25]])
print(nk.transpose())
ne=np.array([1,2,3,4]).reshape((4,1))
nf=np.array([8,5,6,7]).reshape((1,4))
ng=np.array([4,3,2,1])
print(np.dot(ne,nf))
print(np.dot(nf,ne))
print(np.dot(ng,ne))
# print(np.dot(ne,ng))

