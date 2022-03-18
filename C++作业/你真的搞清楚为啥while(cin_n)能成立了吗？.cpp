#include <iostream>
using namespace std;
class MyCin
{
	private:
		bool boolflag;
	public:
		MyCin():boolflag(true)
		{
		}
		template<typename T>
		MyCin& operator>>(T& x)
		{
			if(boolflag)
			{
				cin>>x;
				if(x==-1)
				{
					boolflag=false;
				}
			}
			return *this;
		}
		operator bool()
		{
			if(boolflag==true)
			return boolflag;
			else
			{
				boolflag=true;
				return false;
			}
		}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    m>>n1>>n2;
    cout<<n1<<n2;
    return 0;
}

