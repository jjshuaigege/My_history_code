#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	ifstream ifs;
	ofstream ofs;
	vector<int> v;
	ifs.open("读写文件的排序\\in.txt",ios::in);
	ofs.open("读写文件的排序\\out.txt",ios::out);
	if(!ifs)
	{
		cout<<"读操作失败！"<<endl; 
	}
	else if(!ofs)
	{
		cout<<"写操作失败!"<<endl;
	}
	else
	{
		int x;
		while(ifs>>x)
		{
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			ofs<<v[i]<<" ";
			if((i+1)%5==0)
			{
				ofs<<endl;
			}
		}
		ifs.close();
		ofs.close();
		cout<<"操作成功！"<<endl;
	}
	return 0;
}

