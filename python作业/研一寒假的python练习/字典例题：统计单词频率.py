#输入
#若干行，每行一个单词
#输出
#首先按单词出现次数从高到低排序，次数相同的，按照字典序从小到大排
dict1=dict()
try:
    while(True):
        t_k=input()
        dict1[t_k]=dict1.get(t_k,0)+1
except:
    pass
list1=[]
for i in dict1.items():
    list1.append(i)
list1.sort(key=lambda x:(-x[1],x[0]))
for i in list1:
    print(i[1],i[0])