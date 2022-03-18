import tkinter as tk
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from tkinter import filedialog
from PIL import Image,ImageTk
from math import*
"""
tkinter界面上matplotlib绘图要点
(1)创建一个matplotlib.pyplot.Figure对象fig
(2)在fig对象上用add_subplot()创建一个子图ax
(3)canvas=FigureCanvasTkAgg(fig,master=win)
(4)canvas.get_tk_widget().grid(...)将canvas布局到win的合适位置
(5)子图ax上画完图后，还要canvas.draw()才能刷新显示

用Label显示图像要点
(1) aLabel.config(image=tkinter.PhotoImage(file="xxx.gif"))只可以显示gif图像
(2) 要显示jpg，png需要用到PIL库里的Image和ImageTk
from PIL import Image,ImageTk
img=ImageTk.PhotoImage(Image.open("XXX.jpg"))
aLabel.config(image=img)

两个组件可以放在同一个单元格里面
ctrl.grid_forget() 可以让ctrl组件消失
ctrl.grid()又可以让其恢复

"""
img=None
def f_mouse_down(e):
    gWin.mousedown=True
def f_mouse_up(e):
    gWin.mousedown=False
    gWin.lbHint["text"]="按住鼠标左键移动，可显示位置"
def f_mouse_move(e):
    if gWin.mousedown==True:
        gWin.lbHint["text"]="当前位置:({},{})".format(e.x,e.y)
def plot_click():
    gWin.geometry("")
    gWin.imageFrame.grid_forget()
    gWin.plotFrame.grid(row=1, column=0)
    fig=plt.figure()
    ax=fig.add_subplot()
    canvas=FigureCanvasTkAgg(fig,master=gWin.plotFrame)
    canvas.get_tk_widget().grid(row=0,column=0)
    xs=np.linspace(-3,3,100)
    ys=np.array([eval(gWin.formula.get()) for x in xs])
    ax.plot(xs,ys,color="red",linewidth=1.1,linestyle="--")
    canvas.draw()
def show_click():
    file=filedialog.askopenfilename(initialdir="C:\\Users\\10204\\Desktop\\裁剪图片用",filetype=[("图像文件","*.png *.jpg *.jpeg *.gif")],title="打开图像文件")
    if file!="":
        global img
        gWin.geometry("")
        gWin.plotFrame.grid_forget()
        gWin.imageFrame.grid(row=1,column=0)
        img = ImageTk.PhotoImage(Image.open(file))
        gWin.aLabel.config(image=img)
        gWin.aLabel.grid(row=0,column=0)
#定义全球变量
gWin=tk.Tk()
gWin.formula=tk.StringVar(value="sin(x)")
gWin.mousedown=False
gWin.title("MasterPiece")
gWin.controlFrame=tk.Frame(gWin)
gWin.controlFrame.grid(row=0,column=0,sticky="N")
tk.Label(gWin.controlFrame,text="y = ").grid(row=0,column=0,sticky="E")
tk.Entry(gWin.controlFrame,textvariable=gWin.formula).grid(row=0,column=1)
tk.Button(gWin.controlFrame,text="绘制图形",command=plot_click).grid(row=0,column=2)
tk.Button(gWin.controlFrame,text="显示图像",command=show_click).grid(row=0,column=3)
#用来装plot的框架
gWin.plotFrame=tk.Frame(gWin)
gWin.plotFrame.grid(row=1,column=0)
#用来装image的框架
gWin.imageFrame=tk.Frame(gWin)

#装image时下方有提示信息
gWin.aLabel = tk.Label(gWin.imageFrame)
gWin.aLabel.grid(row=0,column=0)
gWin.lbHint=tk.Label(gWin.imageFrame,text="按住鼠标左键移动，可显示位置",fg="red",bg="blue")
gWin.lbHint.grid(row=1,column=0,sticky="EW")
gWin.aLabel.bind("<ButtonPress-1>",f_mouse_down)
gWin.aLabel.bind("<ButtonRelease-1>",f_mouse_up)
gWin.aLabel.bind("<Motion>",f_mouse_move)
plot_click()
gWin.mainloop()

