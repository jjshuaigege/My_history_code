#include <iostream>
using namespace std;
//template<typename T>
//struct sequence
//{
//	private:
//		int size;
//		T* p;
//	public:
//		sequence(int size):size(size),p(new T[size])
//		{
//			for(int i=0;i<size;++i)
//			cin>>p[i];
//		}
//		sequence max_up_sequence(int k)    //k����size
//		{
//			if(size==1)
//			{
//				sequence temp()
//			}
//			T end=max_up_sequence(k-1).p[k-2];	
//		} 
//}
#define MAXSIZE 100
int main()
{
	int a[MAXSIZE];
	int n;
	//nΪԭʼ���еĳ��� 
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	int length[n];
	length[0]=1;
	for(int i=1;i<n;++i)    //���յ�Ϊa[1]��a[n-1]������� 
	{
		int max=1;
		for(int j=0;j<i;++j)
		{
			if(a[j]<a[i]&&max<length[j]+1)
			{
				max=length[j]+1;
			}
		}
		length[i]=max;
	}
	cout<<length[n-1]<<endl;
	return 0;
}

