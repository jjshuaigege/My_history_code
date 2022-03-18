def func1():
    x=10
    while(x<20):
        yield x          #只要函数中出现yield，则该函数必是一个generator函数
        x+=1
        print("func1()")
    print("finished")
it_1=func1()
print(type(it_1))
print("begin!")
for i in it_1:
    print(i)
