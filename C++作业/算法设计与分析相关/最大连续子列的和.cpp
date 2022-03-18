#include <iostream>
#include <time.h>
using namespace std;
const int N=5000;    //循环次数
const int array_size=50;   //数组大小 
template<class T>
T MAX_sub_add(T* a,int n)
{
	T this_sum,max_sum=0 ;
	for(int i=0;i<n;++i)   //i是子列的左端 
	{
		for(int j=i;j<n;++j) // j是子列的右端 
		{
			this_sum=0;
			for(int k=i;k<=j;++k)    //开始计算某个子列和 
			{
				this_sum+=a[k];	
			}
			max_sum=(max_sum<this_sum?this_sum:max_sum);	
		}	
	}
	return max_sum;	
}
template<class T>
T MAX_sub_add1(T* a,int n)//改进1，去掉一层循环 
{
	T this_sum,max_sum=0;
	for(int i=0;i<n;++i)   //i是子列的左端 
	{
		this_sum=0;
		for(int j=i;j<n;++j) // j是子列的右端 
		{
			this_sum+=a[j];     //求某一子列的子列和 
			max_sum=(max_sum<this_sum?this_sum:max_sum);	
		}	
	}
	return max_sum;	
}
//跨越边界的最大子列和 
template<class T>
T MAX_over_bound(T* s,T*m,T*e)
{
	T this_sum=0,max_sum1=0,max_sum2=0;
	for(T* p=m-1;p>=s;--p)
	{
		this_sum+=(*p);
		max_sum1=(this_sum>max_sum1?this_sum:max_sum1);
	}
	this_sum=0;
	for(T* p=m;p<e;++p)
	{
		this_sum+=(*p);
		max_sum2=(this_sum>max_sum2?this_sum:max_sum2);
	}
	return (max_sum1+max_sum2);
}
template<class T>
T MAX_sub_add2(T* a,int n)    //改进2，分治法 
{
	T t1,t2,t3,max;
	if(n==1)
	{
		max=a[n-1];
	}
	else
	{
		t1=MAX_sub_add2(a,n/2);
		t2=MAX_sub_add2(a+n/2,n-n/2);
		t3=MAX_over_bound(a,a+n/2,a+n);    //计算跨越边界（一定包含边界那个元素）的最大连续子列和 （??左边有k1个数，右边有k2个数，共有O(k1*k2)个子列，但可简化为k1+k2次计算） 
		max=(t1<t2?t2:t1);
		max=(max<t3?t3:max);
	}
	return max;	
} 
template<class T>
T MAX_sub_add3(T* a,int n)   //终极版 ：在线处理
{//原理：从头开始累加，如果累积和大于已有的max，则更新max，如果累加和小于0，则令累加和更新为0（前面的部分已经烂了，扔掉就行）
	T this_sum=0,max_sum=0;
	for(int i=0;i<n;++i)
	{
		this_sum+=a[i];
		if(max_sum<this_sum)
		{
			max_sum=this_sum;
		}
		else if(this_sum<0)
		{
			this_sum=0;
		}
	}
	return max_sum;	
} 
int main()
{
	double a[array_size]={2,-1,45,-100,56,89,-34,56,88,54,1,2,3,4,56,7,89,-456,45,1,-452,899,-4512,512,5153,4561,841,3574,-123,789,13,456,56,12};
	int s1,s2,s3,s4;
	double t1,t2,t3,t4;
	s1=clock();
	cout<<"(1):"<<MAX_sub_add(a,array_size)<<endl;
	for(int i=0;i<N;++i)
	{
		MAX_sub_add(a,array_size);
	}
	t1=static_cast<double>(clock()-s1)/CLK_TCK;
	cout<<t1<<endl;
	s2=clock();
	cout<<"(2):"<<MAX_sub_add1(a,array_size)<<endl;
	for(int i=0;i<N;++i)
	{
		MAX_sub_add1(a,array_size);
	}
	t2=static_cast<double>(clock()-s2)/CLK_TCK;
	cout<<t2<<endl;
	s3=clock();
	cout<<"(3):"<<MAX_sub_add2(a,array_size)<<endl;
	for(int i=0;i<N;++i)
	{
		MAX_sub_add2(a,array_size);
	}
	t3=static_cast<double>(clock()-s3)/CLK_TCK;
	cout<<t3<<endl;
	s4=clock();
	cout<<"(4):"<<MAX_sub_add3(a,array_size)<<endl;
	for(int i=0;i<N;++i)
	{
		MAX_sub_add3(a,array_size);
	}
	t4=static_cast<double>(clock()-s4)/CLK_TCK;
	cout<<t4<<endl;
	return 0;
}

