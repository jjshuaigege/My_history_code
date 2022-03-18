#include <iostream>
#include <queue>
using namespace std;
//写一个流操纵算子 
ostream& tab(ostream& o)
{
	o<<"\t";
	return o;
}
int main()
{
	priority_queue<double> pq;
	pq.push(9.8);
	pq.push(4.6);
	pq.push(5.8);
	pq.push(6.7);
	pq.push(6.6);
	pq.push(7.8);
	pq.push(11.2);
	pq.push(2.9);
	while(!pq.empty())
	{
		cout<<pq.top()<<tab;
		pq.pop();
	}
	cout<<endl;
	priority_queue<double,vector<double>,greater<double> > pq2;    //小根堆
	pq2.push(9.8);
	pq2.push(4.6);
	pq2.push(5.8);
	pq2.push(6.7);
	pq2.push(6.6);
	pq2.push(7.8);
	pq2.push(11.2);
	pq2.push(2.9); 
	while(!pq2.empty())
	{
		cout<<pq2.top()<<tab;
		pq2.pop();
	}
	return 0;
}

