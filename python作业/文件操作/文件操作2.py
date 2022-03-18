import time
tf=open("C:/Users/10204/Desktop/python练习/文件操作/file1.txt","r",encoding="utf-8")
tf.seek(6,0)
text=tf.readline(2)
print(text)
text=tf.readlines(6)
print(text)
tf.seek(0,0)
for i in tf.readlines():
    print(i)
tf.seek(0,0)
for i in tf:
    print(i)
tf.close()