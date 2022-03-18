def func1(x1,x2):
    print("{0:}+{1:}={2:}".format(x1,x2,x1+x2))
tpl1=(6,8)
func1(*tpl1)        #解包裹参数

#定义一个关键字参数的函数,本质是：函数的参数为接收一个字典(用的比较少)
def print_info(**dkw):
    # dkw["name"]=dkw.get("name","default_zhao")
    # dkw["age"]=dkw.get("age",18)
    print("my name is {},I'm {} years old".format(dkw["name"],dkw["age"]))
print_info(name="zhangsan",age="30")

#限定关键字参数,也称命名关键字参数 （sort函数用的就是这类参数）
def func2(words="nothing",*,name="default_shen",age=18):    #*,的后面全为命名关键字参数
    print("{},my name is {},I'm {} years old".format(words,name,age))
func2("hello everyone",name="shen")