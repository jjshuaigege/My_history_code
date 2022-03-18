while(True):
    temp1=1;temp2=1
    k=int(input())
    if k<=0:
        print("k不对")
    elif 1<=k<=2:
        print(1)
    else:
        for i in range(k-2):
            outcome=temp1+temp2
            temp1=temp2
            temp2=outcome
        print(outcome)