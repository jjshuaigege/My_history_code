def f(x):
    print("输出点东西")
    return x*x
a=[1,2,3]
temp=map(f,a)      #map()返回的是一个延时求值对象，此时还没有真正开始调用f函数
#进一步的理解：其实返回的是一个迭代对象!

print("在这停顿")
b=tuple(temp)
print(b)
print(tuple(temp))          #temp中已经没有操作，故得到的是一个空元组

print(list(map(lambda x:2*x,a)))
print(a)


#自己仿写一个map函数
def mymap(f,a):
    ret=[]
    for i in a:
        ret.append(f(i))
    return ret
a=[1,2,3]
b=tuple(mymap(f,a))
print(b)

#fileter(f,a)  返回一个延时求值对象，里面的元素为使f（）为True的a中的元素，过滤掉为False的
x=[1,2,3,4,5,6,7,8]
def f1(x):
    return x%2==0
print(tuple(filter(f1,x)))
