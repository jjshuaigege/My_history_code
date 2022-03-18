"""
普遍格式
for <variable> in <sequence>:
    <statement1>
else:
    <statement2>
依次对sequence中的每个值，执行一遍语句1
循环结束后(正常终止循环，不通过break)再执行一遍语句2。通常不需要语句2
sequence可以是range（...），也可以是列表，元组，集合，字典
"""
dict1={"hj":'sgz','fsd':'shx',98:'llh',"sxx":88}
for i in dict1:
    print(i)
else:
    print("%s,结束"%i)
for j in range(5,40,3):     #range() 函数返回的结果是一个整数序列的对象，而不是列表。
    print(j)