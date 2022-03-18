class point:
    def __init__(self,x=0,y=0):
        self.x=x
        self.y=y
    def __eq__(self,other):
        try:
            return (self.x**2+self.y**2)==(other.x**2+other.y**2)
        except:
            return None
    def __lt__(self,other):
        try:
            return (self.x**2+self.y**2)<(other.x**2+other.y**2)
        except:
            return None

    def __str__(self):
        return "({:},{:})".format(self.x,self.y)
if __name__ =="__main__":
    p1=point(6,1)
    p2=point(8,9)
    p3=point(-2,3)
    p4=point(6,6)
    p5=point(2,3)
    p6=point(1,2)
    l_1=[p1,p2,p3,p4,p5,p6]
    for i in l_1:
        print(i)
    print("-------")
    l_1.sort()
    for i in l_1:
        print(i)
    print(p3==p5)