def gcd(n,m):                   #辗转相除求最大公约数
    while(True):
        ret=n%m
        if ret==0:
            break
        else:
            n=m
            m=ret
    return m
if __name__=="__main__":
    try:
        n=int(input("请输入要输入的数字个数\n"))
        if n<=0:
            raise Exception("输入的n不合法")
        num = []
        print("请输入各个数字")
        for i in range(n):
            num.append(int(input()))
        outcome_bef=num[0]
        for i in range(1, n):
            gcd_t=gcd(outcome_bef, num[i])
            outcome=int(outcome_bef/gcd_t*num[i])
            outcome_bef=outcome
        print("这%d个数的最小公倍数为%d"%(n,outcome))
    except Exception as err:
        print("发生了异常："+str(err))
    # a,b=tuple(map(eval,input().split()))
    # common=gcd(a,b)
    # print("{:}/{:}".format(a/common,b/common))