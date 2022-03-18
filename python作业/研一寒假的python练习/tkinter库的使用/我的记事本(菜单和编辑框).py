import tkinter as tk
from tkinter import filedialog
def muOpen_click():
    global gWin
    file=filedialog.askopenfilename(initialdir="C:\\Users\\10204\\Desktop\\",filetypes=[("文本文件","*.txt")],title="打开文件")
    if file!="":
        gWin.curFileName = file
        gWin.title(file)
        fp=open(file,"rt",encoding="utf-8")
        txt=fp.read()
        gWin.editPlace.delete(0.0,tk.END)
        gWin.editPlace.insert(0.0,txt)
def muNew_click():
    global gWin
    gWin.curFileName="untitled.txt"
    gWin.title("untitled.txt")
    gWin.editPlace.delete(0.0, tk.END)
def muSave_click():
    global gWin
    if gWin.curFileName=="untitled.txt":
        muSaveAs_click()
    else:
        file=gWin.curFileName
        fp=open(file,"wt",encoding="utf-8")
        txt = gWin.editPlace.get(0.0, tk.END)
        fp.write(txt)
        fp.close()
def muSaveAs_click():
    global gWin
    file=filedialog.asksaveasfilename(initialdir="C:\\Users\\10204\\Desktop\\",filetypes=[("文本文件","*.txt")],
                                      title="保存文件")
    if file != "":
        #使文件自带.txt
        if not file.endswith(".txt"):
            file+=".txt"
        gWin.curFileName=file
        gWin.title(gWin.curFileName)
        fp=open(file,"wt",encoding="utf-8")
        txt=gWin.editPlace.get(0.0,tk.END)
        fp.write(txt)
        fp.close()
def muCut_click():
    global gWin
    gWin.editPlace.event_generate("<<Cut>>")
def muCopy_click():
    global gWin
    gWin.editPlace.event_generate("<<Copy>>")
def muPaste_click():
    global gWin
    gWin.editPlace.event_generate("<<Paste>>")
def muFont_click():
    global gWin
    if gWin.isBigFont.get()==0:
        gWin.editPlace.configure(font=("SimHei", 12))
    else:
        gWin.editPlace.configure(font=("SimHei", 25, "bold"))
def muPrint_click():
    txt=gWin.editPlace.get(0.0,tk.END)
    print(txt)

gWin=tk.Tk()
gWin.geometry("800x600+300+300")
gWin.isBigFont=tk.IntVar(value=0)
gWin.curFileName="untitled.txt"
gWin.title("untitled.txt")
gWin.Menubar=tk.Menu(gWin)
gWin.config(menu=gWin.Menubar)        #将Menubar配置到窗口中

#菜单条下的file子菜单
gWin.fileMenu=tk.Menu(gWin.Menubar,tearoff=0)    #去掉顶端横线
gWin.Menubar.add_cascade(label="file",menu=gWin.fileMenu)

gWin.fileMenu.add_command(label="open",command=muOpen_click)
gWin.fileMenu.add_command(label="new",command=muNew_click)
gWin.fileMenu.add_command(label="save",command=muSave_click,accelerator="Ctrl+S")    #只是将快捷方式显示出来，并没有实际的触发器
gWin.fileMenu.add_command(label="save as",command=muSaveAs_click)
gWin.fileMenu.add_separator()
gWin.fileMenu.add_command(label="exit",command=gWin.quit)

#菜单条下的edit子菜单
gWin.editMenu=tk.Menu(gWin.Menubar,tearoff=0)
gWin.Menubar.add_cascade(label="edit",menu=gWin.editMenu)
gWin.editMenu.add_command(label="cut",command=muCut_click)
gWin.editMenu.add_command(label="copy",command=muCopy_click)
gWin.editMenu.add_command(label="paste",command=muPaste_click)
gWin.editMenu.settingsMenu=tk.Menu(gWin.editMenu,tearoff=0)
gWin.editMenu.add_cascade(label="Settings",menu=gWin.editMenu.settingsMenu)
#edit子菜单下的Settings子菜单
gWin.editMenu.settingsMenu.add_checkbutton(label="Big Font",variable=gWin.isBigFont,command=muFont_click)
gWin.editMenu.settingsMenu.add_command(label="Print Selection",command=muPrint_click)

#添加编辑栏
gWin.editPlace=tk.Text(gWin)
gWin.editPlace.grid(row=0,column=0,sticky="ESWN")
muFont_click()
gWin.rowconfigure(0,weight=1)
gWin.columnconfigure(0,weight=1)
gWin.bind_all("<Control-s>",lambda e:muSave_click())
gWin.mainloop()