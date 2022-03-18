#include <iostream>
#include <fstream>
using namespace std;
/*用法示例： <exe的名字> dest.dat src.dat*/
int main(int argc,char* argv[])
{
	cout<<"argc="<<argc<<endl;
	if(argc!=4)
	{
		cout<<"format of order is not correct"<<endl;
	}
	else
	{
		cout<<argv[3]<<endl;
		ifstream ifs(argv[3],ios::in|ios::binary);
		ofstream ofs(argv[2],ios::out|ios::binary);
		if(!ifs)
		{
			cout<<"ifs error"<<endl;
			
		}
		else if(!ofs)
		{
			cout<<"ofs error"<<endl;
		}
		else
		{
			char c;
			while(ifs.read(&c,sizeof(char)))
			{
				ofs.write(&c,sizeof(char));
				cout<<"one operate"<<endl;
			}
			ifs.close();
			ofs.close();
			cout<<"success"<<endl;
		}
	}
	return 0;
}

