import sqlite3
db=sqlite3.connect("C:/Users/10204/Desktop/database1.db")
cur=db.cursor()
sql="select * from students"
cur.execute(sql)
x=cur.fetchone()
print(type(x))
print(x)
for x in cur.fetchall():
    print(x[:-2])
cur.execute("select * from students where name='李四' ")
x=cur.fetchone()
if(x==None):
    print("can't find 李四")
else:
    print(x)
cur.close()
db.close()