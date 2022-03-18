c=[1,3,4,6]
b=c
print(c)
b.append(8)
print(c)
print(b is c)    #b和c是否指向同一个地方
b={}
print(b is c)

#python有优化机制，对于int float,str等这类不可变对象，变量取同一个值时，只创建一个对象，所有变量都引用这个对象
a=15604566.2
b=15604566.2
print(a is b)

#列表的元素本质上也是指针
a=[1,2,3,4]
b=[1,2,3,4]
b[1]=9
print(a[1])

b=a   #b中的所有元素（指针）和对应位置a中的所有元素（指针）指向同一个地方了
b[1]=9
print(a[1])