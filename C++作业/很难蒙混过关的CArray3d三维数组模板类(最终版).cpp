#include <iostream>
#include <iomanip> 
#include <cstring>
using namespace std;
template <class T>
class CArray3D
{	
	public:
		class CArray2D
		{
			private:
				T** py;
				T* pz;
				int y;
				int z;
			public:
				CArray2D(int y,int z):y(y),z(z),py(new T*[y]),pz(new T[y*z])
				{
					for(int i=0;i<y;++i)
					{
						py[i]=pz+i*z;
					}
				}
				~CArray2D()
				{
//					cout<<"~CArray2D()"<<endl;
					delete[] pz;
					delete[] py;
				}
				T* operator [](int v)
				{
					return v<y?py[v]:py[0];	
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
		CArray3D(int x,int y,int z):x(x),px((CArray2D*)new char[x*sizeof(CArray2D)])
		{
			for(int i=0;i<x;++i)
			new(px+i)CArray2D(y,z);
		}
		~CArray3D()
		{
//			cout<<"~CArray3D()"<<endl;
			for(int i=0;i<x;++i)
			{
				px[i].~CArray2D();
			}
			delete[] (char*)px;
		}
		CArray2D& operator [](int v)
		{
			return v<x?px[v]:px[0];
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

	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];	
		}
	}
	PrintA();
	memset(a[1],-1 ,20*sizeof(int));	
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

