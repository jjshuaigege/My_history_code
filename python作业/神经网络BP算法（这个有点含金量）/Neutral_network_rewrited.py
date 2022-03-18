import copy
import time

import numpy as np
import math_functions as mf
import math
class Neutral_network(object):
    """
    layers_vec是代表各层神经元个数的向量
    x是所有条输入数据所组成的二维np矩阵
    Y是所有输入数据所对应的的标签所组成的二维np矩阵
    fai代表所用到的激活函数
    update代表参数更新方式
    batch_size代表sgd所用到的batch大小
    step代表步长
    """
    #改用softmax和交叉熵组合的目标函数
    def __init__(self,layers_vec,x,Y,*,fai="sigmoid",update="SGD",bound=None,batch_size=100,step=0.1,requested_precision=0.99,\
                 batch_normalization=False):
        self.batch_normalization=batch_normalization
        self.requested_precision=requested_precision
        # 神经网络层数
        self.layers_num = len(layers_vec)
        #记录参数
        self.layers_vec=layers_vec
        #设置默认界限
        if bound is None:
            self.bound=int(len(x)*4/5)
        else:
            self.bound=bound
        self.x=x
        self.Y=Y
        self.fai=fai
        self.update=update
        self.batch_size=batch_size
        self.step=step
        #其他内置参数
        self.idx=0                      #表示当前正在处理第idx个输入数据
        self.z=list(np.array([]) for i in range(self.layers_num))
        self.a=list(np.array([]) for i in range(self.layers_num))
        self.theta=list(np.array([]) for i in range(self.layers_num))
        self.aE_aw=list(np.array([]) for i in range(self.layers_num))
        self.aE_ab=list(np.array([]) for i in range(self.layers_num))
        #初始化w和b
        self.w=list(np.array([]) for i in range(self.layers_num))
        self.b=list(np.array([]) for i in range(self.layers_num))
        s=[-1/layers_vec[i]**0.5 for i in range(self.layers_num)]
        e=[1/layers_vec[i]**0.5 for i in range(self.layers_num)]
        for i in range(self.layers_num):
            if i==0:
                self.w[i]=mf.Random_uniform_value(s[i],e[i],(layers_vec[i],self.x.shape[1]))
            else:
                self.w[i]=mf.Random_uniform_value(s[i],e[i],(layers_vec[i],layers_vec[i-1]))
            self.b[i]=mf.Random_uniform_value(s[i],e[i],(layers_vec[i],1))
        #当前的输出
        self.now_q=None

        # 记录当前已经训练的batch的数量
        self.psn = 0
        # 初始化各层的（为了batch_normalization）
        if self.batch_normalization == True:
            self.E_z = np.zeros((self.layers_num, 1), dtype=float)
            self.std_z = np.zeros((self.layers_num, 1), dtype=float)
            self.gamma=list(np.array([]) for i in range(self.layers_num))
            self.beta=list(np.array([]) for i in range(self.layers_num))
            for i in range(self.layers_num):
                #一开始设置gamma为1，beta为0
                self.gamma[i]=np.full((self.layers_vec[i],1),1,dtype=float)
                self.beta[i]=np.zeros((self.layers_vec[i],1),dtype=float)
            self.gamma_grad = list(np.array([]) for i in range(self.layers_num))
            self.beta_grad = list(np.array([]) for i in range(self.layers_num))
            self.x_BN=list(np.array([]) for i in range(self.layers_num))
            self.y_BN=list(np.array([]) for i in range(self.layers_num))

        # 如果步长可变，则设置相应的r矩阵
        if self.update == "AdaGrad" or self.update == "RMSProp" or self.update == "Adam":
            self.rw = list(np.zeros(self.w[i].shape, dtype=float) for i in range(self.layers_num))
            self.rb = list(np.zeros(self.b[i].shape, dtype=float) for i in range(self.layers_num))
            # 如果还有batch_normalization.则还有r_gamma,r_beta
            if self.batch_normalization == True:
                self.r_gamma = list(np.zeros(self.gamma[i].shape, dtype=float) for i in range(self.layers_num))
                self.r_beta = list(np.zeros(self.beta[i].shape, dtype=float) for i in range(self.layers_num))
        # 如果更新方式为Adam（步长可变且有momentum）,则还应设置相应的s矩阵
        if self.update == "Adam":
            self.sw = copy.deepcopy(self.rw)
            self.sb = copy.deepcopy(self.rb)
            if self.batch_normalization == True:
                self.s_gamma = copy.deepcopy(self.r_gamma)
                self.s_beta = copy.deepcopy(self.r_beta)
    def forward_calculate(self):
        now_x=x[self.idx].reshape(x[self.idx].size,1)
        if self.batch_normalization==False:
            for i in range(self.layers_num):
                if i==0:
                    self.z[i]=np.dot(self.w[i],now_x)+self.b[i]
                else:
                    self.z[i]=np.dot(self.w[i],self.a[i-1])+self.b[i]
                self.a[i]=eval("mf."+self.fai)(self.z[i])
            self.a[self.layers_num-1] = mf.softmax(self.z[self.layers_num-1])
            self.now_q=self.a[self.layers_num - 1]
        else:#执行batch_normalization
            for m in range(self.layers_num):
                if m==0:
                    self.z[m]=np.dot(self.w[m],now_x)+self.b[m]
                else:
                    self.z[m]=np.dot(self.w[m],self.a[m-1])+self.b[m]
                # E_z和std_z需要对每次训练过的样本都加权求平均值
                self.E_z[m] = np.mean(self.z[m]) / (self.psn + 1) + self.E_z[m] * self.psn / (self.psn + 1)
                self.std_z[m] = np.std(self.z[m], ddof=1) / (self.psn + 1) + self.std_z[m] * self.psn / (self.psn + 1)
                self.x_BN[m] = (self.z[m] - self.E_z[m]) / (self.std_z[m] + 0.0001)
                self.y_BN[m] = self.gamma[m] * self.x_BN[m] + self.beta[m]
                self.a[m] = eval("mf." + self.fai)(self.y_BN[m])
            self.a[self.layers_num - 1] = mf.softmax(self.y_BN[self.layers_num - 1])
            self.now_q=self.a[self.layers_num - 1]
    def back_derivative(self):
        if self.batch_normalization==False:
            for m in range(self.layers_num-1,-1,-1):
                if m==self.layers_num-1:
                    self.theta[m]= (self.now_q - self.Y[self.idx].reshape(self.Y[self.idx].size, 1))
                else:
                    self.theta[m]=np.dot(self.w[m+1].transpose((1,0)),self.theta[m+1])*mf.fai_der(self.fai,self.z[m])
                self.aE_aw[m]=np.dot(self.theta[m],self.a[m-1].transpose((1,0)))
                self.aE_ab[m]=np.copy(self.theta[m])
        else:#执行batch_normalization
            for m in range(self.layers_num-1,-1,-1):
                if m == self.layers_num - 1:
                    self.theta[m] = (self.now_q - self.Y[self.idx].reshape(-1, 1))* self.gamma[m] / (self.std_z[m] + 0.0001)
                    self.gamma_grad[m] = (self.now_q - self.Y[self.idx].reshape(-1, 1))* self.x_BN[m]
                    self.beta_grad[m] = (self.now_q - self.Y[self.idx].reshape(-1, 1))
                else:
                    self.theta[m] = np.dot(self.w[m+1].transpose((1,0)),self.theta[m+1]) * mf.fai_der(self.fai,self.y_BN[m])*self.gamma[m]/(self.std_z[m]+0.0001)
                    self.gamma_grad[m] = np.dot(self.w[m + 1].transpose((1, 0)), self.theta[m + 1]) * mf.fai_der(self.fai, self.y_BN[m]) * self.x_BN[m]
                    self.beta_grad[m] = np.dot(self.w[m + 1].transpose((1, 0)), self.theta[m + 1]) * mf.fai_der(self.fai, self.y_BN[m])
                self.aE_aw[m] = np.dot(self.theta[m],self.a[m-1].transpose((1,0)))
                self.aE_ab[m] = np.copy(self.theta[m])
        self.idx=(self.idx+1)%(self.x.shape[0])     #准备转到下一个输入数据
        self.psn += 1                               #更新已训练样本数目
        if self.idx==0:
            #走完了一遍训练集，重新打乱
            addxy=np.concatenate((self.x[:self.bound],self.Y[:self.bound]),axis=1)
            np.random.shuffle(addxy)
            self.x[:self.bound]=addxy[:,0:self.x.shape[1]]
            self.Y[:self.bound]=addxy[:,self.x.shape[1]:]
    def update_parameter(self):
        #预备变量
        final_aE_aw = list(np.zeros(self.w[m].shape, float) for m in range(self.layers_num))
        final_aE_ab = list(np.zeros(self.b[m].shape, float) for m in range(self.layers_num))
        if self.batch_normalization==True:
            final_gamma_grad = list(np.zeros(self.gamma[m].shape,float) for m in range(self.layers_num))
            final_beta_grad = list(np.zeros(self.beta[m].shape,float) for m in range(self.layers_num))
        #对一个batch中的梯度加权求和
        for i in range(self.batch_size):
            self.forward_calculate()
            self.back_derivative()
            bef_w=i/(i+1)
            aft_w=1/(i+1)
            for m in range(self.layers_num):
                final_aE_aw[m] = bef_w * final_aE_aw[m] + aft_w * self.aE_aw[m]
                final_aE_ab[m] = bef_w * final_aE_ab[m] + aft_w * self.aE_ab[m]
                if self.batch_normalization == True:
                    final_gamma_grad[m] = bef_w * final_gamma_grad[m] + aft_w * self.gamma_grad[m]
                    final_beta_grad[m] = bef_w * final_beta_grad[m] + aft_w * self.beta_grad[m]
        #若步长可变，则有下面的额外操作
        if self.update=="AdaGrad" or self.update=="RMSProp":
                if self.update=="AdaGrad":
                    a1=1.0;a2=1.0
                elif self.update=="RMSProp":
                    a1=0.6;a2=0.4
                for m in range(self.layers_num):
                    self.rw[m] = a1*self.rw[m] + a2*(final_aE_aw[m]**2)
                    self.rb[m] = a1*self.rb[m] + a2*(final_aE_ab[m]**2)
                    if self.batch_normalization==True:
                        self.r_gamma[m] = a1*self.r_gamma[m] + a2*(final_gamma_grad[m]**2)
                        self.r_beta[m] = a1*self.r_beta[m] + a2*(final_beta_grad[m]**2)
                # 更改w,b所有参数
                if self.batch_normalization == True:
                    for m in range(self.layers_num):
                        self.w[m] = self.w[m] - self.step / np.sqrt(self.rw[m]+1e-6) * final_aE_aw[m]
                        self.b[m] = self.b[m] - self.step / np.sqrt(self.rb[m]+1e-6) * final_aE_ab[m]
                        self.gamma_grad[m] = self.gamma_grad[m] - self.step / np.sqrt(self.r_gamma[m]+1e-6) * final_gamma_grad[m]
                        self.beta_grad[m] = self.beta_grad[m] - self.step / np.sqrt(self.r_beta[m]+1e-6) * final_beta_grad[m]
                else:
                    for m in range(self.layers_num):
                        self.w[m] = self.w[m] - self.step / np.sqrt(self.rw[m]+1e-6) * final_aE_aw[m]
                        self.b[m] = self.b[m] - self.step / np.sqrt(self.rb[m]+1e-6) * final_aE_ab[m]
        #步长可变且有momentum
        elif self.update=="Adam":
            for m in range(self.layers_num):
                #步长调整
                a1=0.999;a2=0.001
                self.rw[m] = a1 * self.rw[m] + a2 * (final_aE_aw[m] ** 2)
                self.rb[m] = a1 * self.rb[m] + a2 * (final_aE_ab[m] ** 2)
                if self.batch_normalization == True:
                    self.r_gamma[m] = a1 * self.r_gamma[m] + a2 * (final_gamma_grad[m] ** 2)
                    self.r_beta[m] = a1 * self.r_beta[m] + a2 * (final_beta_grad[m] ** 2)
                #方向调整
                b1=0.9;b2=0.1
                self.sw[m] = b1 * self.sw[m] + b2 * final_aE_aw[m]
                self.sb[m] = b1 * self.sb[m] + b2 * final_aE_ab[m]
                if self.batch_normalization == True:
                    self.s_gamma[m] = a1 * self.r_gamma[m] + a2 * final_gamma_grad[m]
                    self.s_beta[m] = a1 * self.r_beta[m] + a2 * final_beta_grad[m]
                # 更改w,b所有参数
                if self.batch_normalization == True:
                    for m in range(self.layers_num):
                        self.w[m] = self.w[m] - self.step / np.sqrt(self.rw[m] + 1e-6) * self.sw[m]
                        self.b[m] = self.b[m] - self.step / np.sqrt(self.rb[m] + 1e-6) * self.sb[m]
                        self.gamma_grad[m] = self.gamma_grad[m] - self.step / np.sqrt(self.r_gamma[m] + 1e-6) * self.s_gamma[m]
                        self.beta_grad[m] = self.beta_grad[m] - self.step / np.sqrt(self.r_beta[m] + 1e-6) * self.s_beta[m]
                else:
                    for m in range(self.layers_num):
                        self.w[m] = self.w[m] - self.step / np.sqrt(self.rw[m] + 1e-6) * self.sw[m]
                        self.b[m] = self.b[m] - self.step / np.sqrt(self.rb[m] + 1e-6) * self.sb[m]
        #若更新时步长固定,直接更改w,b所有参数
        else:
            if self.batch_normalization == True:
                for m in range(self.layers_num):
                    self.w[m]=self.w[m]-self.step*final_aE_aw[m]
                    self.b[m]=self.b[m]-self.step*final_aE_ab[m]
                    self.gamma_grad[m] = self.gamma_grad[m]-self.step*final_gamma_grad[m]
                    self.beta_grad[m] = self.beta_grad[m]-self.step*final_beta_grad[m]
            else:
                for m in range(self.layers_num):
                    self.w[m]=self.w[m]-self.step*final_aE_aw[m]
                    self.b[m]=self.b[m]-self.step*final_aE_ab[m]
    #返回一个二维np矩阵
    def test(self):
        xt = self.x[self.bound:]
        Yt = self.Y[self.bound:]
        qt = np.zeros(Yt.shape, float)
        precision = 0
        for i in range(len(xt)):
            self.z[0] = np.dot(self.w[0], xt[i].reshape((-1, 1))) + self.b[0]
            if self.batch_normalization==False:
                self.a[0] = eval("mf." + self.fai)(self.z[0])
                for m in range(1,self.layers_num):
                    self.z[m] = np.dot(self.w[m], self.a[m - 1]) + self.b[m]
                    self.a[m] = eval("mf." + self.fai)(self.z[m])
                self.a[self.layers_num - 1] = mf.softmax(self.z[self.layers_num-1])
            else:
                self.a[0] = eval("mf." + self.fai)((self.z[0] - self.E_z[0]) / (self.std_z[0] + 0.0001) * \
                                                   self.gamma[0] + self.beta[0])
                for m in range(1,self.layers_num):
                    self.z[m] = np.dot(self.w[m], self.a[m - 1]) + self.b[m]
                    self.a[m] = eval("mf." + self.fai)((self.z[m] - self.E_z[m]) / (self.std_z[m] + 0.0001) *\
                                                       self.gamma[m] + self.beta[m])
                self.a[self.layers_num - 1] = mf.softmax((self.z[self.layers_num - 1] - self.E_z[self.layers_num - 1]) / (\
                    self.std_z[self.layers_num - 1] + 0.0001) *self.gamma[self.layers_num - 1] + self.beta[self.layers_num - 1])
            qt[i]=self.a[self.layers_num-1].reshape((-1,))
            if abs( (Yt[i][0]-qt[i][0]) )+abs( (Yt[i][1]-qt[i][1]) ) < 1:
                precision+=1
        precision=precision/(len(self.x)-self.bound)
        print("一轮测试完成，当前正确率为{}".format(precision))
        return qt,precision
    def begin_training(self):
        precision=0
        while precision<self.requested_precision:
            #走完一个epoch测试一次
            for i in range(int(self.bound/self.batch_size)):
                self.update_parameter()
            qt_toprint,precision=self.test()
            print(qt_toprint[-100:])    #打印后100个测试集经模型后的输出，便于观察


    def show(self):
        print("w[2][:2,:2]的值:{}".format((self.w[2][:2,:2])))
        print("b[2][:5]的值:{}".format((self.b[2][:5][0])))
        print("theta[2][:5]的值：{}".format(self.theta[2][:5][0]))
        print("aE_aw[2][:2,:2]的值：{}".format(self.aE_aw[2][:2,:2]))
        print("aE_ab[2][:5]的值：{}".format(self.aE_ab[2][:5][0]))

if __name__=="__main__":
    # 准备数据
    x = np.zeros((50000, 2), float)
    y = np.zeros((50000, 2), float)
    for i in range(len(x)):
        x[i] = mf.Random_uniform_value(0, 6, (2,))
        if (x[i][0] - 3) ** 2 + (x[i][1] - 3) ** 2 <= 4:
            y[i][0] = 1
        else:
            y[i][1] = 1
    #对输入数据作归一化
    x_mean=np.mean(x,axis=0)
    x_std=np.std(x,axis=0,ddof=1)    #ddof=1说明是样本标准差（除以n-1）
    for i in range(len(x)):
        x[i]=(x[i]-x_mean)/x_std
    NN = Neutral_network([2,200,100,2], x, y,bound=40000,batch_size=10,step=0.0    5,batch_normalization=True,update="Adam")
    NN.begin_training()