#coding=utf-8
"""
DataFrame的切片:
iloc[行选择器，列选择器]     用下标作切片
loc[行选择器，列选择器]      用标签作切片
DataFrame的切片是视图
"""

import pandas as pd
scores=[["男",108,115,97],["女",115,87,105],["女",100,60,130],
        ["男",112,80,50]]
names=["刘一哥","王二姐","张三妹","李四弟"]
courses=["性别","语文","数学","英语"]
df=pd.DataFrame(data=scores,index=names,columns=courses)
print(df)
# print(df.iloc[1:3,1:3])
# print(df.loc[:,"数学":"英语"])    #标签为左闭右闭，序列为左闭右开
# print(df.iloc[0:3,[0,2,1]])       #列取第0列、第2列和第1列
print(df.sum())
print(df.mean(axis=1))
print(df.T)                       #df的转置矩阵
dg=df.loc[:,"语文":"英语"]
print(dg)
dg.sort_values("刘一哥",ascending=False,inplace=True,axis=1)          #axis=1和“刘一哥”表示按标签“刘一哥”进行排序，降序，并改变原DataFrame
print(dg)

#一种特殊的切片方法
print(df.loc[(df["语文"]>100)&(df["英语"]>=85)])    #&是 位运算--且

