import tkinter as tk
import re
# import asyncio
# import time
# async def changing_text():
#     i=0
#     text_to_show=str(i)+"秒过去了"
#     while(True):
#         text_to_show
#         time.sleep(1)
def intro_cur(x):
    print(x)
    global txt1
    txt1.insert(tk.END,"请写出您的个人经历")
def myfunc():
    global s
    pt="按了(\d*)下按钮"
    i=int(re.search(pt,s.get()).group(1))+1   #s.get()返回s所对应的python字符串
    s.set("按了"+str(i)+"下按钮")
    return
win=tk.Tk()
win.geometry("800x600+300+150")    #设置窗口大小与起始坐标位置
win.title("一个稍微复杂点的界面")
blue_frame=tk.Frame(win,bg="blue")
blue_frame.grid(row=0,column=0,rowspan=2,sticky="WSEN")
red_frame=tk.Frame(win,bg="red")
red_frame.grid(row=0,column=1,sticky="WSEN")
yellow_frame=tk.Frame(win,bg="yellow")
yellow_frame.grid(row=1,column=1,sticky="WSEN")
green_frame=tk.Frame(win,bg="green")
green_frame.grid(row=2,column=0,columnspan=2,sticky="WE")

#设置每行每列的增加权重
win.rowconfigure(1,weight=1)
win.columnconfigure(1,weight=1)
##其余为0##

tk.Label(blue_frame,text="筛选条件：").grid(row=0,sticky="WN")
#增加blue_frame下的控件
##增加checkbutton控件
tk.Checkbutton(blue_frame,text="男性").grid(row=1,padx=5,pady=5)
tk.Checkbutton(blue_frame,text="女性").grid(row=2,padx=5,pady=5)
tk.Checkbutton(blue_frame,text="博士").grid(row=3,padx=5,pady=5)
tk.Label(blue_frame,text="符合条件的名单：").grid(row=4,sticky="W",padx=5,pady=5)
#创建了一个列表框
namelist=tk.Listbox(blue_frame)
namelist.grid(row=5,sticky="WSEN")
for x in ["张三","李四","王五","李丽","刘娟"]:
    namelist.insert(tk.END,x)   #每次都插入到列表框尾部
blue_frame.rowconfigure(5,weight=1)

#增加red_frame下的控件
tk.Label(red_frame,text="姓名：").grid(row=0,column=0,padx=5,pady=5)
tk.Entry(red_frame).grid(row=0,column=1,padx=5,pady=5)
tk.Label(red_frame,text="手机号：").grid(row=0,column=2,padx=5,pady=5)
tk.Entry(red_frame).grid(row=0,column=3,padx=5,pady=5)

##增加一个简易的事件相应机制
s=tk.StringVar()
s.set("按了0下按钮")
tk.Button(red_frame,text="更新",command=myfunc).grid(row=0,column=4,padx=5,pady=5)

red_frame.columnconfigure(1,weight=1)
red_frame.columnconfigure(3,weight=1)

#增加yellow_frame下的组件
curriculum=tk.Label(yellow_frame,text="简历：")
curriculum.grid(row=0,sticky="WN",padx=5,pady=5)
txt1=tk.Text(yellow_frame)
txt1.grid(row=1,column=0,sticky="WSEN",padx=5,pady=5)
curriculum.bind("<ButtonPress-1>",intro_cur)

yellow_frame.rowconfigure(1,weight=1)
yellow_frame.columnconfigure(0,weight=1)
#增加green_frame下的组件

tk.Label(green_frame,textvariable=s).grid(row=0,column=0,sticky="W",padx=5,pady=5)




win.mainloop()

