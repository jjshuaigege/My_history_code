#include <iostream>
#include <functional>
using namespace std;
int main()
{
	//用到functional对象需要include <functional> 
	function<int(int)> ff=[&ff](int n){return n>1?ff(n-1)+ff(n-2):n;};
	cout<<ff(6)<<endl;
	return 0;
}

