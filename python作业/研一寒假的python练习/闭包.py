def f(x):
    def g(y):
        nonlocal x    #此处是在声明x是一个外部嵌套函数内的变量
        x+=1
        return x+y
    return g
h=f(10)       #h是一个闭包
print(h(4))
print(h(5))