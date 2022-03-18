import numpy as np
import math_functions
import math
# x=np.array([[i+6*j for i in range(0,6)] for j in range(0,6)],dtype=float)
# print(type(x.shape))
# print(x.shape)
# print(type(x))
# print(x)
# x[1,:]=[i for i in range(44,50)]
# print(type(x[1,:]))
# print(x.reshape([9,-1]))
# print(x)
# xx=x[1,1]
# print(type(xx))
# print(xx)
# layers_num=7
# w=list(np.array([]) for i in range(layers_num))
# w[2]=np.array([i for i in range(1,10)]).reshape([3,3])
# print(w)
class Neutral_network(object):
    #layers_vec是一个一维np矩阵，代表各层神经元个数
    #x是一个二维np矩阵，代表训练集（所有输入数据），其中x[i]代表第i个输入数据
    #Y是输入数据所对应的的标签（one_hot_vector）
    #step是每次更新的步长
    def __init__(self,layers_vec,x,Y,*,fai="sigmoid",update="SGD",batch_size=100,step=0.05):
        self.layers_vec=layers_vec           #各层的神经元个数
        self.layers_num=len(layers_vec)      #总共有多少层
        self.w=list(np.array([]) for i in range(self.layers_num))          #总的w,是一个列表，w[0],w[1]等等对应第一层，第二层等等,分别是M(1)*M(0),M(2)*M(1)...的矩阵，其中M(0)是输入数据的维度,
        self.b=list(np.array([]) for i in range(self.layers_num))                    #总的b，是一个列表,b[0],b[1]等等对应第一层，第二层等等,分别是M(1),M(2)...大小的一维数组;M(1),M(2),M(3),M(l)组成了layers_vec,即各层的神经元个数
        self.z=list(np.array([]) for i in range(self.layers_num))          #总的z，是一个列表，z[0],z[1]等对应第一层，第二层的z，分别是M(1),M(2)行的一维矩阵
        self.a=list(np.array([]) for i in range(self.layers_num))          #总的a,是一个列表，a[0],a[1]等对应第一层，第二层的a，分别是M(1),M(2)行的一维矩阵
        self.idx=0                                                         #idx代表当前正处理第idx个数据
        self.x=x                                                           #记录所有输入数据为x
        self.Y=Y                                                           #记录所有标签为Y
        self.y=np.array([])                                                #记录当前的输出y
        self.theta=list(np.array([]) for i in range(self.layers_num))
        self.aE_aw=list(np.array([]) for i in range(self.layers_num))
        self.aE_ab=list(np.array([]) for i in range(self.layers_num))      #记录所有theta（theta[i]即aE/az[i]）、aE_aw、aE_ab
        self.fai=fai                                                       #记录所用的激活函数
        self.update=update                                                 #记录所用的更新参数方式
        self.batch_size=batch_size                                         #记录batch_size
        self.step=step                                                     #记录步长
        #给w和b赋初值，在区间(-1/sqrt(d),1/sqrt(d))均匀随机取值，其中d为该层的神经元个数
        sec_size = x.shape[1]      #先赋值为输入数据的维度
        for i in range(self.layers_num):
            s = -1 / math.sqrt(layers_vec[i])
            e = 1 / math.sqrt(layers_vec[i])
            # print(layers_vec[i])
            # print(s)
            self.w[i]=math_functions.Random_uniform_value(s,e,[layers_vec[i],sec_size])
            sec_size=layers_vec[i]
            self.b[i]=math_functions.Random_uniform_value(s,e,layers_vec[i])
    """
    本函数的目的是前向算出所有的(z,a,y)
    x_i代表某条输入数据
    """
    #idx代表第idx个输入数据
    def forward_calculate(self):
        for i in range(self.layers_num):   #总共有多少层，就循环多少遍
            if i == 0:
                self.z[i]=np.dot(self.w[i],self.x[self.idx].reshape((self.x[self.idx].size,1)))+self.b[i].reshape(self.b[i].size,1)
            else:
                self.z[i]=np.dot(self.w[i],self.a[i-1].reshape((self.a[i-1].size,1)))+self.b[i].reshape(self.b[i].size,1)
            self.a[i] = eval("math_functions."+self.fai)(self.z[i])  # 通过激活函数
        self.y=self.a[self.layers_num-1]                   #记录当前的输出
        #让theta、aE_aw、aE_ab的形状和z、w、b保持一致
        for i in range(self.layers_num):
            self.theta[i]=np.copy(self.z[i])
            self.aE_aw[i]=np.copy(self.w[i])
            self.aE_ab[i]=np.copy(self.b[i])
    #本函数的目的，算出矩阵theta
    def back_derivative(self):
        for m in range(self.layers_num-1,-1,-1):
            if m==self.layers_num-1:
                self.theta[m]=(self.y.reshape((self.y.size,1))-self.Y[self.idx].reshape((self.Y[self.idx].size,1)))*math_functions.fai_der(self.fai,self.z[m])

            else:
                self.theta[m]=np.dot(self.theta[m+1].reshape((1,self.theta[m+1].size)),self.w[m+1])*math_functions.fai_der(self.fai,self.z[m].reshape((1,self.z[m].size)))
                self.theta[m]=self.theta[m].reshape(self.theta[m].size,1)
            self.aE_aw[m]=np.dot(self.theta[m].reshape((self.theta[m].size,1)),self.a[m-1].reshape((1,self.a[m-1].size)))
            self.aE_ab[m]=np.copy(self.theta[m])
        self.idx=(self.idx+1)%self.x.shape[0]
    def update_parameter(self):
        if self.batch_size==1:
            for m in range(self.layers_num):
                self.w[m]=self.w[m]-self.step*self.aE_aw[m]
                self.b[m]=self.b[m]-self.step*self.aE_ab[m].reshape((self.aE_ab[m].size,))
    def test(self,x):
        y=np.full((len(x),x.shape[1]),1)
        for j in range(len(x)):
            for i in range(self.layers_num):  # 总共有多少层，就循环多少遍
                if i == 0:
                    self.z[i] = np.dot(self.w[i], x[j].reshape((x[j].size, 1))) + self.b[i].reshape((self.b[i].size,1))
                else:
                    self.z[i] = np.dot(self.w[i], self.a[i - 1].reshape((self.a[i - 1].size, 1))) + self.b[i].reshape((self.b[i].size,1))
                self.a[i] = eval("math_functions." + self.fai)(self.z[i])  # 通过激活函数
            y[j] = self.a[self.layers_num - 1].reshape((self.a[self.layers_num - 1].size,))  # 记录当前的输出
        return y
    def show(self):
        print("w[2][:2,:2]的值:{}".format((self.w[2][:2,:2])))
        print("b[2][:5]的值:{}".format((self.b[2][:5])))
        print("theta[2][:5]的值：{}".format(self.theta[2][:5]))
        print("aE_aw[2][:2,:2]的值：{}".format(self.aE_aw[2][:2,:2]))
        print("aE_ab[2][:5]的值：{}".format(self.aE_ab[2][:5]))






if __name__=="__main__":
    #准备数据
    x=np.full((5000,2),0)
    y=np.zeros((5000,2),int)
    for i in range(len(x)):
        x[i]=math_functions.Random_uniform_value(0,4,(2,))
        if (x[i][0]-3)**2+(x[i][1]-3)**2<=2:
            y[i][0]=1
        else:
            y[i][1]=1
    addxy=np.concatenate((x,y),axis=1)
    print(addxy)
    times = 1000
    NN = Neutral_network([500, 400, 300, 2],x[0:times],y[0:times],batch_size=1)
    precision=0;p_N=np.zeros(1000,int)
    while(precision<0.95):
        for i in range(times):
            NN.forward_calculate()
            NN.back_derivative()
            NN.update_parameter()
            if i%100==0:
                print("训练%d轮了"%(i))
                NN.show()
        yt=NN.test(x[times:2000])
        #检查准确率
        for i in range(1000):
            if ((yt[i][0]-y[i+times][0])**2+(yt[i][1]-y[i+times][1])**2)<0.4:
                p_N[i]=1
            else:
                p_N[i]=0
            precision+=p_N[i]
        precision=precision/1000
        print("现在的准确率：{:.3f}".format(precision))

    # N=Neutral_network([400,200,300,6])
    # print(N.layers_num)
    # for i in N.w:
    #     print(i.size)
    #     print(i)
    # print("-------------")
    # for i in N.b:
    #     print(i.size)
    #     print(i)