import os
c_path=os.getcwd()                #获取当前目录
files_list=os.listdir(c_path)     #获取当前目录下的所有文件，返回一个列表
print(type(files_list))
for i in files_list:
    print(i)
os.mkdir("学习资料")
fp=open("独立宣言.txt","wt",encoding="utf-8")
fp.write("ok，兄弟们，全体目光向我看齐\n")
fp.close()
os.rename("C:\\Users\\10204\\Desktop\\python练习\\寒假python练习\\独立宣言.txt","C:\\Users\\10204\\Desktop\\python练习\\寒假python练习\\学习资料\\独立宣言.txt")