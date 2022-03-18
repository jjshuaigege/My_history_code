import tkinder
"""
有的控件有函数可以用来设置和获取其属性，或以字典下标的形式获取和设置其属性
lbHint=tk.Label(win,text="请登录")
lbHint["text"]="登录成功"      #修改了标签lbHint的文字

txt=tk.Text(win)
txt.get(0.0,tk.END)          #从第0行第0列取到末尾，即取全部文字

有的控件必须和一个变量相关联，取变量值或设置变量值，就是取或设置该控件的属性
s=tk.StringVar()
s.set("sin(x)")
tk.Entry(win,textvariable=s)      #此时s与编辑框中的文字绑定在一起了
"""

