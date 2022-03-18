class rectangle:
    def __init__(self,x,y):
        self.x=x
        self.y=y
    def area(self):
        return self.x*self.y
    def perimeter(self):
        return 2*(self.x+self.y)

if __name__=="__main__":
    r1 = rectangle(6,10)
    print(r1.area())
    print(r1.perimeter())
    r1.x=12
    r1.y=24
    print(r1.area())
    print(r1.perimeter())
