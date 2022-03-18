a=3
b=5
c=7
print(a>2 and c<4)
print(a>2 or c<4)
print(not a>2)
print(5 and 3)
print(3 and 5)
print(not 3)
print(5 or 3)
print(3 or 5)
c=n=[10,15,79]    #c,n指向了同一个列表
print(c,n)
c.append(88)
print(n)
print((not {})==True)
print({} or False)    #{}相当于False，即在逻辑运算中被视为False，但{}不等于False，即{}=False结果为False