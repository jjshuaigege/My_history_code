#include <iostream>
#include <cstring>
using namespace std;

class Array2 
{
	private:
		int row;
	public:
		class Array1
		{
			public:
				int column;
				int* p2; 
			public:
				Array1(int column):column(column),p2(new int[column])
				{
					
				}
				Array1()
				{
					
				}
				int& operator[](int value)
				{
					return p2[value];
				}
		};
	private:
		Array1* p1;
	public:
		Array2(int row,int column):row(row),p1(new Array1[row])
		{
			for(int cnt=0;cnt<row;cnt++)
			{
				p1[cnt].column =column;
				p1[cnt].p2=new int[column];
			}
		}
		Array2()
		{
			
		}
		Array1& operator[](int value)
		{
			return p1[value];
		}
		int& operator()(int v1,int v2)
		{
			return p1[v1][v2];
		}
		Array2& operator=(const Array2& x)
		{
			row=x.row;
			p1=new Array1[row];
			for(int cnt=0;cnt<row;cnt++)
			{
				p1[cnt].column =x.p1[cnt].column;
				p1[cnt].p2=new int[x.p1[cnt].column];
				for(int cnt1=0;cnt1<x.p1[cnt].column;cnt1++)
				{
					p1[cnt].p2[cnt1]=x.p1[cnt].p2[cnt1];
				}
			}
		}
};
//

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

