b=a=[5,7,6,2,4,1,3]
a.sort()
print(a)
print(b)

b=a=[5,7,6,2,4,1,3]
c=sorted(a,reverse=True)          #sorted不改变原列表，而是创建一个新的根据原来列表排好序的列表
print(a,b,c)

#自定义排序
def mykey(x):
    return x%10       #根据个位数进行排序
a=[94,18,36,22,15,46,41,57,83]
a.sort(key=mykey,reverse=True)
print(a)

txt=sorted("This is a test string from Andrew".split(),key=str.lower)
print(txt)