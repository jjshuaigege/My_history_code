import time
tf=open("C:/Users/10204/Desktop/python练习/文件操作/file1.txt","r",encoding="utf-8")
txt1=tf.read(2)
print("指针当前位置{}".format(tf.tell()))
tf.seek(3,0)             #移动当前指针往前3个单位，即1个汉字
txt2=tf.read()
print(txt1)
print(txt2)