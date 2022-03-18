class A(object):
    def __init__(self,i=25,j="hello"):
        self.i=i
        self.j=j
        print("一个A类被生成")
    def __del__(self):
        print("一个A类被销毁")
def f1():
    n.x=25

n=A(35)
n.x=10
print(n.x)
f1()
print(n.x)