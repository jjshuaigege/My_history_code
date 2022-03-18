#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
int main()
{
	time_t* temp=new time_t;
	cout<<time(temp)<<endl;
	cout<<*temp<<endl;
	cout<<ctime(temp)<<endl;
	default_random_engine e;
	cout<<e()<<endl;
	cout<<e()<<endl;
	return 0;
}

