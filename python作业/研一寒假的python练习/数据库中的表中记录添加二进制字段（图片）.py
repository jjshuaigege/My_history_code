import sqlite3
fp1=open("../../sgz.jpg","rb")
db=sqlite3.connect("../../database1.db")
cur=db.cursor()
sql1="insert into students values(?,?,?,?,?,?)"
cur.execute(sql1,(5835,"sgz",3.5,"1998-04-06",24,fp1.read()))

fp1.close()
db.commit()
cur.close()
db.close()