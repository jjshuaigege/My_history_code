#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
template <typename T1,typename T2,typename funcp=greater<T1> >
class MyMultimap:public multimap<T1,T2,funcp>
{
	public:
		void Set(T1 key,T2 value)
		{
			for(typename multimap<T1,T2,funcp>::iterator x=this->begin();x!=this->end();++x)    
			//multimap<T1,T2,funcp>::iterator还没有被实例化，编译器无法判断这是个类型还是个变量，因此在前面加上typename表明这是个类型  
			{
				if(x->first==key)
				{
					x->second=value;
				}
			}
		}
};
template <typename T1,typename T2>
ostream& operator<< (ostream& o,const pair<T1,T2>& x)
{
	o<<"("<<x.first<<","<<x.second<<")";
	return o;
}
struct Student 
{
	string name;
	int score;
};
template <class T>
void Print(T first,T last) {
	for(;first!= last; ++ first)
		cout << * first << ",";
	cout << endl;
}
int main()
{
	
	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };
	
	MyMultimap<string,int> mp;
	for(int i = 0; i<5; ++ i)
		mp.insert(make_pair(s[i].name,s[i].score));
	Print(mp.begin(),mp.end()); //?????????

	mp.Set("Tom",78); //?????"Tom"??????????78
	Print(mp.begin(),mp.end());
	
	
	
	MyMultimap<int,string,less<int> > mp2;
	for(int i = 0; i<5; ++ i) 
		mp2.insert(make_pair(s[i].score,s[i].name));
	
	Print(mp2.begin(),mp2.end()); //?????????
	mp2.Set(70,"Error");          //??????70???,?????"Error"
	Print(mp2.begin(),mp2.end());
	cout << "******" << endl;
	
	mp.clear();
	
	string name;
	string cmd;
	int score;		
	while(cin >> cmd ) {
		if( cmd == "A") {
			cin >> name >> score;
			if(mp.find(name) != mp.end() ) {
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name,score));
		}
		else if(cmd == "Q") {
			cin >> name;
			MyMultimap<string,int>::iterator p = mp.find(name);
			if( p!= mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl; 
			}		
		}
	}
	return 0;
}

