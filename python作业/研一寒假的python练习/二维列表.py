#易错点
martix=[[0,0,0]]*3
martix[0][1]=100
print(martix)

#正确写法
martix=[[0 for i in range(3)] for j in range(3)]
martix[0][1]=100
print(martix)