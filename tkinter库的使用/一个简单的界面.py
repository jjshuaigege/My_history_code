import tkinter as tk
win=tk.Tk()
win.title("一个简单的界面")
#创建4个组件
label1=tk.Label(win,text="用户名")
label2=tk.Label(win,text="密码")
user_name_entry=tk.Entry(win)
password_entry=tk.Entry(win)
log_button=tk.Button(win,text="登陆")
#根据grid布局给各组件分配位置
#sticky参数决定控件在单元格的贴边方式，共有四个字符--"E","W","S","N"
label1.grid(row=0,column=0,sticky="EWSN")      #padx=5表示左右留白5像素,pady=5表示上下留白5像素,sticky表示标签居中
label2.grid(row=1,column=0,sticky="EN")        #sticky表示贴近东北
user_name_entry.grid(row=0,column=1,sticky="EWSN") #sticky表示框占满整个单元格
password_entry.grid(row=1,column=1,sticky="NS")
log_button.grid(row=2,column=0,columnspan=2)    #columnspan=2表示跨2列

#设置各行各列的增量分配权重(即当窗口放大时，网格区域随之放大的权重，默认为0，总权重为各行（列）权重之和)

#设置第0列的权重为1
win.columnconfigure(0,weight=1)

win.columnconfigure(1,weight=1)

for i in range(3):
    win.rowconfigure(i,weight=1)

#把窗口显示出来
win.mainloop()




