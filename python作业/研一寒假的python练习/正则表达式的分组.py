import re
#括号中的表达式是一个分组，多个分组按左括号从左到右从1开始编号
pt="(a(b(cd)))e"
x=re.search(pt,"abcdefg")
print(x.group(0))   #等效于x.group()
print(x.group(1))
print(x.group(2))
print(x.group(3))
print(x.groups())

#在分组的右边可以通过分组的编号引用该分组所匹配的子串
pt1="(((ab*)c)d)e\\3"
x1=re.search(pt1,"mnabbbcdeabbbbbkgj")
print(x1.group(3))
print(x1.group())

#分组作为一个整体，后面可以跟量词
pt3="(ab*)+def"
x2_1=re.search(pt3,"ababbdef")
print(x2_1.group())
print(x2_1.groups())
#在正则表达式分组超过一个时，re.findall()返回的是一个元组的列表，元组内的元素，按组号排序
pt4="\w+ \w+"
x3=re.findall(pt4,"Hello world My name is shenguozhi")
print(x3)
