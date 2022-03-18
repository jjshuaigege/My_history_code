import numpy as np
import math
def Random_uniform_value(s,e,shape):     #为w，b赋初值
    return np.random.uniform(s,e,shape)
def softmax(x):
    return (math.e**x)/(np.sum(math.e**x))
def sigmoid(x):
    return 1/(1+math.e**(-x))
def tanh(x):
    return (math.e**(x)-math.e**(-x))/(math.e**(x)+math.e**(-x))
def fai_der(fai,x):
    if fai=="sigmoid":
        return sigmoid(x)*(1-sigmoid(x))
    elif fai=="tanh":
        return 1-tanh(x)**2
#测试代码
if __name__=="__main__":
    x=Random_uniform_value(-10,10,8)
    print(x)
    x1=sigmoid(2)
    fai="sigmoid"
    x2=eval(fai)(np.array([2,3,5]))
    x3=np.array([[2,4,8,6],[6,2,8,3]])
    x4=np.array([6,7,8,11])
    x5=np.dot(x3,x4)
    print(x1)
    print(x2)
    print(type(x5),x5)
    print(tanh(2))
    print(pai_der("tanh",2))