import re
pt="((孔明|诸葛亮|亮).{0,2}曰：“[^”]*(曹操|曹贼|操|操贼|曹阿瞒).*?”)"
fp=open("三国演义.txt","r",encoding="utf-8")
txt=fp.read()
fp.close()
oc=re.findall(pt,txt)
print(len(oc))
for a in oc:
    print(a[0])
pt1="\B\d*"
s1="??123"
print(re.search(pt1,s1).group())