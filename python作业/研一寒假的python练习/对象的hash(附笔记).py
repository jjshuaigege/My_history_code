"""
两个对象a,b 若hash（a）=hash（b），但a==b不成立，
则a，b可以处于同一集合（也可以作为同一字典的不同元素的键）
即不算重复，可以放在同一个槽里

若dt是个字典，dt[x]计算过程如下：
（1）根据hash（x）去找x应该在的槽的编号
（2）如果该槽没有元素，则认为dt中没有键为x的元素
（3）如果该槽中有元素，则试图在槽中找一个元素y，使得y的键==x。
如果找到，则dt【x】即为y的值，如果找不到，则dt【x】没有定义，即
认为dt中不存在键为x的元素

自定义类的对象，默认情况下根据对象id进行计算，所以对于两个对象，只要a is b不成立，a与b的哈希值就不同
默认情况下，只有a与b的id相同，a==b才成立
如果为自定义类对象重写了__eq__方法，却没有重写__hash__方法，当且仅当在这种情况下，自定义类不可哈希
"""
class Complex:
    def __init__(self,real=0,image=0):
        self.real=real
        self.image=image
    def __hash__(self):
        # print("__hash__() called!")
        return self.real
    def __str__(self):
        ret="("+str(self.real)+","+str(self.image)+")"
        return ret
    # def __eq__(self, o):
    #     return self.real==o.real
a=Complex(1,3)
b=Complex(1,5)
st={a,b}
dt={a:"hh",b:"kk"}
for i in st:
    print(i)
for i in dt.items():
    print(i)
# print(hash(a))
