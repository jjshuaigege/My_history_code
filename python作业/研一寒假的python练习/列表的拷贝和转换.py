import copy
#拷贝
a=[1,2,3]
b=a[:]
b[1]=0
print(a,b)

#一般方法不能做到深拷贝
a=[1,[2]]
b=a[:]
a[1].append(0)
b.append(4)
print(a,b)

#要做到深拷贝需要用到copy库中的deepcopy
a=[1,[2]]
print(isinstance(a,list))
b=copy.deepcopy(a)
a[1].append(0)
print(a,b)