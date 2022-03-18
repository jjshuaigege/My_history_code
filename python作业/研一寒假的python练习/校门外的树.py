l_1=list(map(int,input().split()))
length=l_1[0]
area_num=l_1[1]
V=[True]*(length+1)
for i in range(area_num):
    l_2=list(map(int,input().split()))
    start=l_2[0]
    end=l_2[1]
    for j in range(start,end+1):
        V[j]=False
print(sum(V))
