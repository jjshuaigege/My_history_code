# 对于列表a,b来说,a+=b 和 a=a+b 是不一样的
a=[1,2]
b=a
a+=[3,4]
print(a,b)
a=a+[5,6]
print(a,b)

a=(1,2)
b=a
a+=(3,4)
print(a)
print(b)

#难点！
a=[[0]]*2+[[0]]*2
a[0][0]=5
print(a)

n=True;
n+=1
print(n)