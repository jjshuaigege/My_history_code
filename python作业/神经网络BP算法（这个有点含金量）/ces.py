import math_functions
import numpy as np
import math
import copy
import math_functions as mf
# class A:
#     def __init__(self):
#         self.index=None
#         print("fsd")
#     def set(self):
#         for i in range(5):
#             self.index[i]=np.array([i*1,i*2,i*3,i*4,i*5])
# a=A()
# print(a.index)
# a.set()
# print(a.index)

x=np.arange(-1,-10,-1)
y=list(np.array([4*i,8*i,9*i]) for i in range(1,3 ))
z=copy.deepcopy(y)
print(z)
z[1][1:]=np.array([22,33])
print(z)
print(y)
print(np.sqrt(y))