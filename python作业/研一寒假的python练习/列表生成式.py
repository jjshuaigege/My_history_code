L=["Hello","World",18,"Apple",None]
a=[x for x in L if isinstance(x,str)]
l1=["AB","EF"]
l2=["CD","GH"]
b=[m+n for m in l1 for n in l2]
print(a)
print(b)
