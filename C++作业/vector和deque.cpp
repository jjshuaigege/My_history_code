#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main()
{
	deque<int> h;
	h.push_back(1);
	h.push_back(3);
	h.push_back(5);
	h.push_back(7);
	h.pop_front();
	cout<<h[0]<<endl;
	for(deque<int>::iterator i=h.begin();i!=h.end();++i)
	{
		cout<<*i<<" ";
	}
	vector<int> h2;
	h2.push_back(11);
	h2.push_back(12);
	for(vector<int>::iterator i=h2.begin();i!=h2.end();++i)
	{
		cout<<*i<<" ";
	}
	cout<<endl;
	h2.pop_back();
	cout<<h2[0]<<endl;
	return 0;
}

