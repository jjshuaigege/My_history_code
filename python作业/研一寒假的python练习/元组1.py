#元组元素的内容可以修改
a=[1,5,8],"hello",99
print(a[0])
a[0][1]="sgz"
print(a[0])
a[0].append(88)
print(a[0])

#单个元素的元组末尾需要加一个逗号
t_1=(1)
print(isinstance(t_1,tuple))
print(isinstance(t_1,int))
t_1=(1)
print(isinstance(t_1,tuple))

a=[1,2,3]
b=(a,a)
b[0][1]=99    #等效于a[1]=99
print(a,b)
