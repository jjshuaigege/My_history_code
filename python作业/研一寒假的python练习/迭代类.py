class A(object):
    def __init__(self,x,y):
        self.x=x
        self.y=y                            #初始化
    def __iter__(self):
        print("this is a iter_class")
        return self                         #返回值为迭代器对象，一般为自己
    def __next__(self):
        if self.x<20:
            self.x+=1
            self.y*=2
            print("iterating")
            return self                    #返回当前迭代值
        else:
            raise StopIteration()          #停止迭代
    def __str__(self):
        return "(%d,%d)"%(self.x,self.y)
a=A(1,2)
for i in a:
    print(i)
