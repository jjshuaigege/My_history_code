import re
import tkinter as tk
from tkinter import ttk
#设置几个全局变量
gWin=None
gDishTypes=[["清汤（15元）","麻辣（20元）","鸳鸯（20元）"],
            ["香菜（4元）","蒜酱（5元）","韭花（6元）"],
            ["猪肉（20元）","羊肉卷（40元）","肥牛（35元）","大白菜（10元）","花菜（8元）"]]
#将菜品添加到列表框中
def addDishTypeToList(lstbox,serial):
    for i in gDishTypes[serial]:
        lstbox.insert(tk.END,i)
def add_dishes():
    sl=gWin.availableDishList.curselection()
    if sl==tuple():
        gWin.lbHint["fg"]="red"
        gWin.lbHint["text"]="您未选中任何菜，添加失败！"
    else:
        #餐桌添加项目
        temp="["+gWin.category.get()+"]"+gWin.availableDishList.get(sl)+"x"+str(gWin.dishNum.get())
        gWin.lsbTable.insert(tk.END,temp)
        #计算总价格
        ##获得单价
        pt=".+?（(\d+)元）"
        oc=re.search(pt,gWin.availableDishList.get(sl))
        solo_price=int(oc.group(1))
        gWin.totalcost+=solo_price*gWin.dishNum.get()
        doDiscount()
def delete_dishes():
    al=gWin.lsbTable.curselection()     #al是一个元组，表示当前被选中的列表框的项目序号
    if al==tuple():
        gWin.lbHint["fg"] = "red"
        gWin.lbHint["text"] = "您未选中任何菜，删除失败！"
    else:
        for i in al[::-1]:
            #改变总价格
            num=int(re.search(".*?x(\d*)",gWin.lsbTable.get(i)).group(1))
            solo_price=int(re.search(".+?（(\d+)元）",gWin.lsbTable.get(i)).group(1))
            gWin.totalcost-=num*solo_price
            #删除这个项目
            gWin.lsbTable.delete(i)
        doDiscount()
def category_changed(e):
    gWin.availableDishList.delete(0,tk.END)
    idx=gWin.cbxCategory.current()     #得到当前菜肴大类的序号
    addDishTypeToList(gWin.availableDishList,idx)
    # gWin.availableDishList.select_set(0,0)
def doDiscount():
    gWin.discount=[1.0,0.9,0.8][gWin.discount_type.get()]
    gWin.lbHint["fg"] = "black"
    gWin.lbHint["text"]="饭菜总价格为"+str(gWin.totalcost*gWin.discount)+"元"
def main():
    global gWin
    gWin=tk.Tk()
    gWin.geometry("520x300")
    #设置tk变量
    gWin.dishNum=tk.IntVar(value=1)      #选中的菜肴数量
    gWin.category=tk.StringVar(value="锅底")         #选中的菜肴大类
    gWin.totalcost,gWin.discount=0,1     #总价钱，折扣，用一般的int就行

    gWin.title("我的火锅店")
    gWin.resizable(False,False)
    lb=tk.Label(gWin,text="欢迎光临python火锅店",font=("宋体",20,"bold"),
                    fg="white",bg="red")
    lb.grid(row=0,column=0,columnspan=4,sticky="EW")

    #下拉框
    gWin.cbxCategory=ttk.Combobox(gWin,textvariable=gWin.category,value=["锅底","佐料","菜品"],state="readonly")
    gWin.cbxCategory.grid(row=1,column=0,sticky="ESWN")
    gWin.cbxCategory.bind("<<ComboboxSelected>>",category_changed)      #下拉框被选中时，调用相关函数，更新列表框内容
    #列表框
    gWin.availableDishList=tk.Listbox(gWin,selectmode=tk.SINGLE,exportselection=False)  #selectmode意思是设置为单选模式，exportselection意思是选中别的列表框，此列表框仍然保持焦点
    #列表框某一菜品被选中后，菜肴数额需要归1
    gWin.availableDishList.bind("<<ListboxSelect>>",lambda e:gWin.dishNum.set(1))
    #双击列表框中某一菜品，需要触发添加操作
    gWin.availableDishList.bind("<Double-Button-1>",lambda e:add_dishes())
    gWin.availableDishList.grid(row=2,column=0,sticky="ESWN")
    category_changed(None)

    #中间的frame组件
    gWin.fr=tk.Frame(gWin)
    gWin.fr.grid(row=2,column=1,sticky="ESWN",pady=5)
    ##选择数量
    gWin.lbDishNum=tk.Label(gWin.fr,text="数量：")
    gWin.sbxDishnum=tk.Spinbox(gWin.fr,from_=1,to=1000,textvariable=gWin.dishNum,font=20)
    gWin.lbDishNum.grid(row=0,column=0,sticky="NSWE")
    gWin.sbxDishnum.grid(row=0,column=1,sticky="NSWE")
    ##添加键
    gWin.btAdd=tk.Button(gWin.fr,text="添加",command=add_dishes)
    gWin.btAdd.grid(row=1,column=0,columnspan=2,sticky="NSWE")
    gWin.bind("<KeyPress-Return>",lambda e:add_dishes())
    ##删除键
    gWin.btAdd = tk.Button(gWin.fr, text="删除",command=delete_dishes)
    gWin.btAdd.grid(row=2, column=0, columnspan=2, sticky="NSWE")
    ##价格折扣(frame中的frame)
    gWin.fr.lbfDiscount=tk.LabelFrame(gWin.fr,text="价格")
    gWin.fr.lbfDiscount.grid(row=3,column=0,columnspan=2,sticky="NSWE")
    ###定义一个tk变量，表示选中了哪种折扣
    gWin.discount_type=tk.IntVar(value=0)
    ttk.Radiobutton(gWin.fr.lbfDiscount,value=0,text="普通价",variable=gWin.discount_type,command=doDiscount).grid(row=0,sticky="EW")
    ttk.Radiobutton(gWin.fr.lbfDiscount, value=1, text="会员价（九折）", variable=gWin.discount_type,command=doDiscount).grid(row=1,sticky="EW")
    ttk.Radiobutton(gWin.fr.lbfDiscount, value=2, text="VIP价（八折）", variable=gWin.discount_type,command=doDiscount).grid(row=2,sticky="EW")

    #我的餐桌
    tk.Label(gWin,text="我的餐桌").grid(row=1,column=2,sticky="NSWE")
    gWin.lsbTable=tk.Listbox(gWin,selectmode=tk.EXTENDED,exportselection=False)  #设置可以多选
    gWin.lsbTable.grid(row=2,column=2,sticky="NSWE")
    #添加滚动条并相互绑定
    scTableBar=tk.Scrollbar(gWin,width=20,orient="vertical",command=gWin.lsbTable.yview)
    gWin.lsbTable.configure(yscrollcommand=scTableBar.set)
    scTableBar.grid(row=2,column=3,sticky="NS")


    #提示信息（显示总价格）
    gWin.lbHint=tk.Label(gWin,text="无")
    gWin.lbHint.grid(row=3,column=0,columnspan=3,sticky="NSW")
    gWin.rowconfigure(2,weight=1)
    gWin.columnconfigure(0,weight=1)
    gWin.columnconfigure(2,weight=1)
    gWin.mainloop()
main()