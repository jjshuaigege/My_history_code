from turtle import*
#预备工作
setup(800,600,0,0)
title("自动轨迹绘制")
colormode(1)
pencolor("RED")
pensize(5)
penup()
goto(0,0)
pendown()
#获取数据
datalist=[]     #列表的列表
tf=open("目标文件.txt","r",encoding="utf-8")
for line in tf.readlines():
    line=line.replace("\n","")
    datalist.append(list(map(eval,line.split(","))))
tf.close()
#根据数据绘图
for i in range(len(datalist)):
    pencolor(datalist[i][3],datalist[i][4],datalist[i][5])
    fd(datalist[i][0])
    if datalist[i][1]==0:
        left(datalist[i][2])
    elif datalist[i][1]==1:
        right(datalist[i][2])
    else:
        print("错误！")
        break
hideturtle()
done()
