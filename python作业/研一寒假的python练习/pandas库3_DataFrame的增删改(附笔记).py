import pandas as pd
pd.set_option("display.unicode.east_asian_width",True)
scores=[["男",108,115,97],["女",115,87,105],["女",100,60,130],
        ["男",112,80,50]]
names=["刘一哥","王二姐","张三妹","李四弟"]
courses=["性别","语文","数学","英语"]
df=pd.DataFrame(data=scores,index=names,columns=courses)

df.insert(1,"体育",[50,50,50,50])         #插入体育成绩到第一列
df["物理"]=[100,90,80,70]                 #列尾插入物理成绩
print(df)
df.loc["张三妹","语文":"物理"]+=10         #给张三妹除体育外各科加10分
df.loc["钱五叔"]=["男",100,100,100,100,100]   #加入一行
df.columns=["gender","体育","语文","数学","English","物理"]     #修改列标签

df.drop("王二姐",axis=0,inplace=True)      #删除王二姐那一行
df.drop(["语文","English"],axis=1,inplace=True)   #删除语文和English两列
dg=df.drop([df.columns[i] for i in range(2)],axis=1,inplace=False)
print(df)
print(dg)