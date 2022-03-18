#include <iostream>.
#include <map>
using namespace std;
typedef multimap<int ,double,greater<int> > MID;
template<class T1,class T2,class T3>
PrintMID(const multimap<T1,T2,T3> &x)
{
	typename multimap<T1,T2,T3>::const_iterator i;      //iterator是一个在multimap内部定义的类，由于模板还没有实例化，所以需要加上typename
	for(i=x.begin();i!=x.end();++i)  
	cout<<"("<<i->first<<","<<i->second<<")"<<"\t";
	cout<<endl;
}
int main()
{
	MID h{make_pair(1,2.1),make_pair(2,4.1),make_pair(3,3.1),make_pair(5,6.1),make_pair(7,5.1),};
	PrintMID(h);
	MID::iterator i=h.begin(); 
	return 0;
}

