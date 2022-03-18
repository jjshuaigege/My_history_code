import tkinter as tk
from tkinter import messagebox
from tkinter import simpledialog
from tkinter import filedialog
def cmd(i):
    def func():
        if i<=4:
            value=eval("messagebox."+dia_names[i])("messagebox-Dialog","拉跨")
        elif i>4 and i<=7:
            value =eval("simpledialog."+dia_names[i])("simple-Dialog", "变成无情的枷锁")
        elif i==8:
            value = filedialog.askopenfilename(title="打开文件",filetypes=[("图像文件","*.jpg *.jpeg *.png"),("文本文件","*.txt"),("所有文件","*")],
                                               initialfile="anonymous",initialdir="C:\\Users\\10204\\Desktop\\新建文件夹 (3)")
        elif i==9:
            value = filedialog.asksaveasfilename(title="保存文件")
        elif i==10:
            value = filedialog.askopenfilenames(title="打开多个文件")
        else:
            value=filedialog.askdirectory(title="打开目录")
        print(i,dia_names[i],value)
    return func
#全局变量
gRoot=tk.Tk()
dia_names=["askokcancel","askyesno","showerror","showinfo","showwarning",
           "askfloat","askinteger","askstring",
            "askopenfilename","asksaveasfilename","askopenfilenames","askdirectory"]
for i in range(12):
     tk.Button(gRoot,text=dia_names[i],command=cmd(i)).grid(row=i//4,column=i%4,padx=5,pady=5)
gRoot.mainloop()
# value=messagebox.askokcancel("Dialog","askokcancel")
# print(value)