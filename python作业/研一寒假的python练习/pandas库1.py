import pandas as pd
#Series是一维表格，每个元素带标签且有下标，兼具列表和字典的访问形式
a=pd.Series(data=[80,90,100],index=["语文","数学","英语"])
for x in a:
    print(x,end=" ")
print("")
for x in range(len(a.index)):
    print(a.index[x],end=" ")
print("")
print(a[2],a["数学"])     #序号和标签都可以作为下标来访问
print(a["数学":"英语"][1])          #切片为左闭右闭
a["体育"]=110            #增加一个元素，标签为“体育”，值为110
a.pop("数学")            #删去标签为“数学“的这个元素
# print(a)
b=a.append(pd.Series(data=[120,],index=["物理",]))    #a本身不会改变，而是生成一个新的Series
print(a)
print(b)
#DataFrame是带行列标签的二维表格，它的每一列都是一个Series

pd.set_option("display.unicode.east_asian_width",True)
scores=[["男",108,115,97],["女",115,87,105],["女",100,60,130],
        ["男",112,80,50]]
names=["刘一哥","王二姐","张三妹","李四弟"]
courses=["性别","语文","数学","英语"]
df=pd.DataFrame(data=scores,index=names,columns=courses)
print(df)

print(df.values[0][2],type(df.values))
print("******")
print(df.index[2],df.columns[1])
# #取一行
# r1=df.loc["王二姐"]            #r1是个Series
# print(r1,type(r1))
#取一列
c1=df["数学"]
print(c1,type(c1))

#取到的某行或某列都是视图

