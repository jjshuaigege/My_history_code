x1=26
print(x1.__hash__(),hash(26))
x2=23.1
print(x2.__hash__(),23.1.__hash__(),hash(x2))
x3=(3,5)
print(x3.__hash__(),(3,5).__hash__(),hash((3,5)))
x4="OK"
print(x4.__hash__(),"OK".__hash__(),hash())
