import tkinter as tk
correct_username="NJUPT"
correct_password="123"
def login():
    if username.get()==correct_username and password.get()==correct_password:
        lbHint["text"]="登录成功！"
        lbHint["fg"]="green"
    else:
        #清空两个框
        username.set("")
        password.set("")
        #提示信息
        lbHint["text"]="用户名或密码错误，请重新输入"
        lbHint["fg"]="red"
def show_password_switch():
    global show_password
    if show_password.get()==True:      #要取得tk变量的值，需要通过get函数
        enPassword["show"]=""
    else:
        enPassword["show"]="*"
if __name__=="__main__":
    win=tk.Tk()
    #定义tk变量
    username,password=tk.StringVar(),tk.StringVar()
    show_password=tk.BooleanVar()
    #排版
    lbHint=tk.Label(win,text="请登录")
    lbHint.grid(row=0,column=0,columnspan=2,sticky="EW")

    lbUsername=tk.Label(win,text="用户名：",padx=5,pady=5)
    lbUsername.grid(row=1,column=0,padx=5,pady=5)

    enUsername=tk.Entry(win,textvariable=username)             #此框与变量username绑定
    enUsername.grid(row=1,column=1,padx=5,pady=5)

    lbpassword=tk.Label(win,text="密码：",padx=5,pady=5)
    lbpassword.grid(row=2,column=0,padx=5,pady=5)

    enPassword=tk.Entry(win,textvariable=password,show="*")     #与变量password绑定，默认密码显示为"*"
    enPassword.grid(row=2,column=1,padx=5,pady=5)

    cbtShowPassword=tk.Checkbutton(win,text="显示密码",variable=show_password,command=show_password_switch)   #与变量show_password绑定，并添加事件响应
    cbtShowPassword.grid(row=3,column=0,padx=5,pady=5)

    btLogin=tk.Button(win, text="登录",command=login)
    btLogin.grid(row=4,column=0,padx=5,pady=5)
    btExit=tk.Button(win,text="退出",command=win.quit)
    btExit.grid(row=4,column=1,padx=5,pady=5)
    win.mainloop()