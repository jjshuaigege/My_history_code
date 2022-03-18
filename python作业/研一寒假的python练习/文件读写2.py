#如果不写encoding,则会用操作系统默认编码，本机为GBK
fp=open("C:/Users/10204/Desktop/python练习/寒假python练习/for_file_test/file1.txt","a+",encoding="utf-8")
fp.write("你19好78\n")
fp.write("写点东西\n")
for i in range(1,4):
    fp.write("{:d}个客户".format(i))
    if(i!=3):
        fp.write(",")
fp.write("\n")
poem=["唯有知情一片月","曾窥飞鸟入昭阳","一枝红艳露凝香","云雨巫山枉断肠"]
fp.writelines(poem)  #将某个字符串的列表写入文件
fp.seek(0,0)         #前面的参数为偏移量
t_1=fp.readline()
t_2=fp.readlines()   #读取从当前读写指针位置到文件末尾的所有行，返回一个字符串的列表，每个元素为一行
fp.close()
print(t_1)
print(t_2)