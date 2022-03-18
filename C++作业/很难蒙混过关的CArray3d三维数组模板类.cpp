#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
//template <class T>
//class CArray3D
//{
//	public:
//		class CArray2D
//		{
//			public:
//				class CArray1D
//				{
//					public:
//						T* P1D;
//					public:
//						CArray1D(int z):P1D(new T[z])
//						{
//							for(int i=0;i<z;i++)
//							{
//								P1D[i]=0;
//							}
//						}
//						T& operator[](int v)
//						{
//							return P1D[v];
//						}
//						operator void*()
//						{
//							return P1D;
//						}
//				};
//			private:
//				CArray1D* P2D;
//			public:
//				CArray2D(int y,int z):P2D((CArray1D*)new T[y*z])
//				{
//					for(int i=0;i<y;++i)
//					{
//						P2D[i]=CArray1D(z);
//					}
//				}
//				CArray1D& operator[](int v)
//				{
//					return P2D[v];
//				}
//				operator void*()
//				{
//					return (void*)((P2D)->P1D);
//				}
//		};
//	private:
//		CArray2D* P3D;
//	public:
//	CArray3D(int x,int y,int z):P3D((CArray2D*)new T[x*y*z]/*错误！！！！*/)
//	{
//		for(int i=0;i<x;++i)
//		{
//			P3D[i]=CArray2D(y,z);
//		}
//	}
//	CArray2D& operator[](int v)
//	{
//		return P3D[v];
//	}
//};



//template <class T>
//class CArray3D
//{
//	public:
//		class CArray2D
//		{
//			private:
//				T**py;
//				T*pz;
//			public:
//				CArray2D(int y,int z):py(new T*[y]),pz(new T[y*z])
//				{
//					for(int i=0;i<y;++i)
//					{
//						py[i]=pz+i*z;
//					}
//				}
////				~CArray2D()
////				{
////					delete[] py;
////					delete[] pz;
////				}
//				T* operator[](int v)
//				{
//					return py[v];
//				}
//				operator void*()
//				{
//					return py[0];
//				}
//				
//		};
//	private:
//		CArray2D* px;
//	public:
//		CArray3D(int x,int y,int z):px((CArray2D*)new char[sizeof(CArray2D)*x])
//		{
//			for(int i=0;i<x;++i)
//			{
//				px[i]=CArray2D(y,z);
//			}
//		}
//		~CArray3D()
//		{
//			delete []px;
//		}
//		CArray2D& operator[](int v)
//		{
//			return px[v];
//		}
//};



template <class T>
class CArray3D
{
	public:
		class CArray2D
		{
			private:
				T**py;
				int y;
				int z;
			public:
				CArray2D(int y,int z):y(y),z(z),py(new T*[y])
				{
					for(int i=0;i<y;++i)
					{
						py[i]=new T[z];
					}
				}
				//需要重写CArray2D的复制构造函数!!
				CArray2D(const CArray2D& x):py(new T*[x.y]),y(x.y),z(x.z)
				{
					cout << "executing copy call" << endl;
					for(int i=0;i<x.y;++i)
					{
						py[i]=new T[x.z];
					}
				}
				//需要重写CArray2D的赋值函数!!
				CArray2D& operator=(const CArray2D& x)
				{
					cout << "value = called" << endl;
					y=x.y;
					z=x.z;
					py=new T*[x.y];
					for(int i=0;i<x.y;++i)
					{
						py[i]=new T[x.z];
					}
					
				}
//				~CArray2D()
//				{
//					cout<<"~CArray2D()"<<endl;
////					for(int i=0;i<y;++i)
////					{
////						delete[] py[i];
////					}
////					delete[] py;
//				}
				T* operator[](int v)
				{
					return py[v];
				}
				operator void*()
				{
					return py[0];
				}
				
		};
	private:
		CArray2D* px;
		int x;
	public:
		CArray3D(int x,int y,int z):x(x),px((CArray2D*)new char[sizeof(CArray2D)*x])
		{
			for(int i=0;i<x;++i)
			{
				new(px+i)CArray2D(y,z);
			}
		}
//		~CArray3D()
//		{
//			cout<<"~CArray3D()"<<endl;
//			reinterpret_cast<CArray2D*>(px);
//			for(int i=0;i<x;++i)
//			{
//				delete px[i];
//			}
//			delete []px;
//		}
		CArray2D& operator[](int v)
		{
			return px[v];
		}
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);
void PrintA()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k) 
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}
void PrintB()
{
	for(int i = 0;i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k) 
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main()
{
	a[1][1][1]=68;
	cout<<a[1][1][1];

//	cout<<sizeof(CArray3D<int>)<<endl;
//	cout<<sizeof(CArray3D<int>::CArray2D)<<endl;
//	cout<<sizeof(CArray3D<int>::CArray2D::CArray1D)<<endl;
	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
//			a[j][i][i];	
		}
	}
	
	PrintA();
//	memset(a[1],-1 ,9*sizeof(int));	
	memset(a[1],-1 ,20*sizeof(int));
	PrintA(); 
	memset(a[1][1],0 ,5*sizeof(int));	
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();
	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;
		
	return 0;
}

