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
	ifs.open("��д�ļ�������\\in.txt",ios::in);
	ofs.open("��д�ļ�������\\out.txt",ios::out);
	if(!ifs)
	{
		cout<<"������ʧ�ܣ�"<<endl; 
	}
	else if(!ofs)
	{
		cout<<"д����ʧ��!"<<endl;
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
		cout<<"�����ɹ���"<<endl;
	}
	return 0;
}

