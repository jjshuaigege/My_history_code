def hanoi(n,src,mid,des):
    if n==1:
        print("%s->%s"%(src,des))
        return 1
    else:
        n1=hanoi(n-1,src,des,mid)
        print("%s->%s"%(src,des))
        n2=hanoi(n-1,mid,src,des) 
        return n1+n2+1
if __name__=="__main__":
    n=int(input("请输入盘子数目\n"))
    print("总共%d步"%hanoi(n,"x","y","z"))
