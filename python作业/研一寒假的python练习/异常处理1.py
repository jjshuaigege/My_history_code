try:
    v_max=0
    while(True):
        s=input().split()
        for i in range(len(s)):
            temp=int(s[i])
            if v_max<temp:
                v_max=temp
except:
    pass
print(v_max)
"""
异常的一般格式

try:
    
except:   #捕获到异常，则从捕获处中断之后的所有try下的语句，调到except下开始执行

else:     #没有捕获到异常，则会执行else下的语句

finally:  #无论是否捕获到异常，都会执行finally下的语句

"""