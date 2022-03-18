#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
class CHugeInt {
	private:
		char p[51]={0};
		char to_print[51]={0};
	public:
		 //将p2的内容颠倒放入p1 
		void myreverse(char* p1,const char* p2)
		{
			int i=0,j=0;
			while(p2[j]!='\0')
			{
				j++;
			}
			j--;
			while(j>=0)
			{
				p1[i++]=p2[j--];		
			}
			p1[i]='\0';
		}
		CHugeInt()
		{
			
		}
		CHugeInt(const char* x)
		{
			strcpy(p,x);
			myreverse(p,x);
//			reverse(p,p+strlen(p));	
		}
		CHugeInt(int x)
		{
			int temp=x;
			int adj=0;
			while(temp!=0)
			{
				p[adj++]=temp%10+'0';
				temp/=10;
			}
			p[adj]='\0';
		}
		CHugeInt operator + (const CHugeInt x)const
		{
			int a1,a2;
			int adj;
			int higher_num=0;
			int this_num=0;
			CHugeInt temp_CHI("0"); 
			for(adj=0;(p[adj]>='0'&&p[adj]<='9')||(x.p[adj]>='0'&&x.p[adj]<='9');adj++)
			{
				if(p[adj]>='0'&&p[adj]<='9')
				{
					a1=p[adj]-'0';
				}
				else
				{
					a1=0;
				}
				if(x.p[adj]>='0'&&x.p[adj]<='9')
				{
					a2=x.p[adj]-'0';
				}
				else
				{
					a2=0;
				}
				this_num=(a1+a2+higher_num)%10;
				temp_CHI.p[adj]=this_num+'0';
				higher_num=(a1+a2+higher_num)/10;	
			}
			if(higher_num!=0)
			{
				temp_CHI.p[adj]=higher_num+'0';
			}
			return temp_CHI;	
		}
		//用于cout 
		operator char*()
		{
//			strcpy(to_print,p);
//			reverse(to_print,to_print+strlen(to_print));
			myreverse(to_print,p);
			return to_print;	
		}
		CHugeInt operator +(int n)
		{
			CHugeInt temp(n);
			return temp+*this;	
		}
		friend CHugeInt num(int b,int e);
		friend CHugeInt operator +(int n,CHugeInt x)
		{
			CHugeInt temp(n);
			return temp+x;	
		}
		CHugeInt& operator=(const CHugeInt& x)
		{
			if(p!=x.p)
			{
				strcpy(p,x.p);
				return *this;
			}
		}
		CHugeInt& operator+=(int n)
		{
			CHugeInt temp(n);
			*this=temp+*this;
			return *this;	
		}
		CHugeInt operator++(int nouse)
		{
			CHugeInt obj=*this;
			CHugeInt temp(1);
			*this=temp+*this;
			return obj;
		}
		CHugeInt& operator++()
		{
//			cout<<"in CHugeInt& operator++() before b="<<*this<<endl;
			CHugeInt temp(1);
			*this=temp+*this;
//			cout<<"in CHugeInt& operator++() b="<<*this<<endl;
			return *this;	
		}
		friend istream& operator>>(istream& i,CHugeInt& x)
		{
			i>>x.p;
		}
		int size()
		{
			int i;
			for(i=0;p[i]!=0;++i);
			return i;
		}
		bool operator< (const CHugeInt x)
		{
			int i=0;
			while(p[i]!=0&&x.p[i]!=0)
			{
				++i;	
			}
			if(p[i]!=0)
			{
				return false;	
			}
			else if(x.p[i]!=0)
			{
				return true;	
			}
			else
			{
				--i;
				while(p[i]==x.p[i])
				{
					--i;	
				}	
				if(p[i]<x.p[i])
				{
					return true;
				}
				else
				{
					return false;
				}
			}	
		}	
};
//思路
//(1)状态V(n,m)    在前n个数字里面放置m个加号,所对应的最小值  
//(2)边界
//1.V(n,m)=正无穷 (m>=n)
//2.V(n,0)=num(0,n-1)      num(0,n-1)表示前n个数字所组成的大数 
//(3)递推关系  
//v(n,m)=min{v(1,m-1)+num(1,n-1),v(2,m-1)+num(2,n-1),...,v(n-1,m-1)+num(n-1,n-1)}
//=min{v(m,m-1)+num(m,n-1),v(m+1,m-1)+num(m+1,n-1),...,v(n-1,m-1)+num(n-1,n-1)} //V的一维从m到n-1，二维是m-1；num的一维从m到n-1，二维是n-1 
#define infinite "9999999999" 
CHugeInt n;
CHugeInt num(int b,int e)
{
	CHugeInt temp;
	int i;
	for(i=b;i<=e;++i)
	{
		temp.p[i-b]=n.p[i];	
	}
	temp.p[i]=0;
	reverse(temp.p,temp.p+i-b);
	return  temp;
}
int main()
{
	int m;
	cin>>m;        //m个加号 
	cin>>n;        //n为待处理的大数 
	vector<vector<CHugeInt> > V;     //对应思路中的V[n][m]
	//把一维下标为0的置为-1（无用）
	V.push_back(vector<CHugeInt>()); 
	for(int j=0;j<=m;j++)
	{
		V[0].push_back(-1);
	}
	//V(n,0)=num(0,n-1)
	for(int i=1;i<=n.size();++i)
	{
		V.push_back(vector<CHugeInt>());
		V[i].push_back(num(0,i-1));
	}
	
	for(int i=1;i<=n.size();++i)
	{
		for(int j=1;j<=m;j++)
		{
			if(j>=i)
			{
				V[i].push_back(infinite);
//				cout<<V[i][j]<<"\t";	
			}
			else
			{
				CHugeInt min=V[j][j-1]+num(j,i-1);
				for(int k=j;k<=i-1;k++)
				{
					if((V[k][j-1]+num(k,i-1))<min)
					{
						min=V[k][j-1]+num(k,i-1);
//						cout<<" 调试："<<min<<endl;	
					}
				}
				V[i].push_back(min);
//				cout<<V[i][j]<<"\t";
			}
				
		}
//		cout<<endl;	
	}
//	cout<<(num(0,2)+CHugeInt(321))<<endl;
//	cout<<V[1][0]<<endl;
//	cout<<(num(0,2))<<endl;
	cout<<V[n.size()][m];
	return 0;
}

