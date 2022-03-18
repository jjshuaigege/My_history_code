import re
def match(pattern,string):
    #re.match是从母串的开头部分去匹配
    x=re.match(pattern,string)
    if x!=None:
        print(x.group())
    else:
        print("not matched!")
match("4\\\\g6","4\g686")     #变换过程: "4\\\\g6"(python字符串)->r"4\\g6"(正则表达式)->"4\g6"（匹配的字符串）
print("4\\n")

def search(pattern,string):
    #re.search()是从母串的任意位置去找匹配的子串，返回第一个符合条件的子串
    x=re.search(pattern,string)
    if x!=None:
        print("matched")
        print(x.group(),x.span())
    else:
        print("not matched!")
def findall(pattern,string):
    #re.findall()是从母串的任意位置去找匹配的子串，返回所有子串的一个列表,若有分组，分组数大于1则列表的元素是由各分组构成的元组，
    # 分组数等于一则列表各元素是分组对应的内容。但无论怎样，列表元素个数始终等于匹配结果数
    x=re.findall(pattern,string)
    if x!=list():
        print(x)
        for i in x:
            txt=str()
            for j in i:
                txt+=j
            print(txt)
    else:
        print("not matched!")
def finditer(pattern,string):
    #返回的是一个迭代对象
    x=re.finditer(pattern,string)
    if x!=None:
        for i in x:
            print(i.group(),i.span())
    else:
        print("not matched!")

#符合模式的子串都将被替换
print(re.sub("\d+","...","56个民族56支花960万平方公里14亿人口"))

#匹配原则：不同位置优先匹配最前面的，同一位置优先匹配最长的（默认为贪婪模式）
print(re.sub("ddd\d*","kksk","gddd648ddf"))
search("高{1,2}兴{1,2}[^的].*上学","我今天高高兴背着书包去上学")
findall("(w{3}\.[a-zA-Z]+\.)(com|cn)","www.baidu.comhjkwww.edu.cnffsdkfwww.google.comrs")
finditer("\w{3}\.[a-zA-Z]+\.(com|cn)","www.baidu.comhjkwww.edu.cnffsdkfwww.google.comrs")

# 匹配过程的详细分析
search("\\b45\\b","/45?")   #过程："\\b"(原python字符串)->"\b"（正则表达式）->以边界来匹配
search("\\\\b","\\b")       #过程："\\\\b"(原python字符串)->"\\b"(正则表达式)->匹配字符串"\\b"
search("\b","\b")           #过程："\b"(原python字符串)->退格符(正则表达式,长度为1，是一个字符,代表退格)->去匹配

print("--------")
pt="ka\b.*"
search(pt,"ka")
search(pt,"kax")
search(pt,"ka?x")

search("\Ba\sb\B\w \w","xa bl l")
search("\Ba\sb\B\w \w","?a bl l")

