import sqlite3
db=sqlite3.connect("C:\\Users\\10204\\Desktop\\database1.db")
cur=db.cursor()
sql1="update students set age=?,gpa=? where name=? "
cur.execute(sql1,(20,3.5,"王五"))

db.commit()
cur.close()
db.close()