#include <iostream>
#include <time.h>
using namespace std;
const int N=5000;    //ѭ������
const int array_size=50;   //�����С 
template<class T>
T MAX_sub_add(T* a,int n)
{
	T this_sum,max_sum=0 ;
	for(int i=0;i<n;++i)   //i�����е���� 
	{
		for(int j=i;j<n;++j) // j�����е��Ҷ� 
		{
			this_sum=0;
			for(int k=i;k<=j;++k)    //��ʼ����ĳ�����к� 
			{
				this_sum+=a[k];	
			}
			max_sum=(max_sum<this_sum?this_sum:max_sum);	
		}	
	}
	return max_sum;	
}
template<class T>
T MAX_sub_add1(T* a,int n)//�Ľ�1��ȥ��һ��ѭ�� 
{
	T this_sum,max_sum=0;
	for(int i=0;i<n;++i)   //i�����е���� 
	{
		this_sum=0;
		for(int j=i;j<n;++j) // j�����е��Ҷ� 
		{
			this_sum+=a[j];     //��ĳһ���е����к� 
			max_sum=(max_sum<this_sum?this_sum:max_sum);	
		}	
	}
	return max_sum;	
}
//��Խ�߽��������к� 
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
T MAX_sub_add2(T* a,int n)    //�Ľ�2�����η� 
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
		t3=MAX_over_bound(a,a+n/2,a+n);    //�����Խ�߽磨һ�������߽��Ǹ�Ԫ�أ�������������к� ��??�����k1�������ұ���k2����������O(k1*k2)�����У����ɼ�Ϊk1+k2�μ��㣩 
		max=(t1<t2?t2:t1);
		max=(max<t3?t3:max);
	}
	return max;	
} 
template<class T>
T MAX_sub_add3(T* a,int n)   //�ռ��� �����ߴ���
{//ԭ����ͷ��ʼ�ۼӣ�����ۻ��ʹ������е�max�������max������ۼӺ�С��0�������ۼӺ͸���Ϊ0��ǰ��Ĳ����Ѿ����ˣ��ӵ����У�
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

