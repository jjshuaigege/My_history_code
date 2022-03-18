import re
sample_1="\(.*?\)"   #量词后面加?，表示懒惰匹配
oc1=re.findall(sample_1,"I (have a) bomb,do (you) copy (11520 replys)")
sample_2="a.*?b"
oc2=re.findall(sample_2,"aab,abbdsbb")     #不同位置优先匹配最前面的，同一位置优先匹配最短的
print(oc1)
print(oc2)

# def func1(*x):
#     ret=0
#     if x is not tuple:
#         for i in x:
#             ret+=i
#     return ret
# print(func1(11,22,61,3))