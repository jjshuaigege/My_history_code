tf=open("C:/Users/10204/Desktop/python练习/文件操作/file1.txt","a+",encoding="utf-8")
tf.write("\n祝你生日快乐\n")
ls=["我","是","一个","研究生"]
tf.writelines(ls)
tf.seek(0,0)
txt=tf.read()
print(txt)