n=int(input())
while n<5:
    print(n,"小于5")
    n=n+1
else:
    print(n,"大于等于5")
for i in range(26):
    print(chr(ord("a")+i),end="")