#n级台阶，每步走一级或两级台阶，问有多少种解法
def stair(n):
    if n<=0:
        return 0
    elif n==1 or n==2:
        return n
    else:
        return stair(n-1)+stair(n-2)
print(stair(9))