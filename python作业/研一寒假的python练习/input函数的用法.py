while(True):
    s=input("请输入两个数：\n")      #input()的作用是输出括号里的字符串，并等待和接收输入作为一个字符串
    list=s.split("ss")                #split（）作用是按照（）中的字符串将原字符串划分为多个子串，并返回一个字符串列表
    a=eval(list[0])
    b=eval(list[1])
    print("你输入了："+s)
    try:
        print("a/b=",a/b)
    except(ZeroDivisionError):
        print("除数为0！")
    finally:
        print(" 捕获异常结束")